
// PacmanApp.cpp
# include"PacmanApp.hpp"

#ifdef _XBOX //Big-Endian
  #define fourccRIFF 'RIFF'
  #define fourccDATA 'data'
  #define fourccFMT  'fmt '
  #define fourccWAVE 'WAVE'
  #define fourccXWMA 'XWMA'
  #define fourccDPDS 'dpds'
#endif

#ifndef _XBOX //Little-Endian
  #define fourccRIFF 'FFIR'
  #define fourccDATA 'atad'
  #define fourccFMT  ' tmf'
  #define fourccWAVE 'EVAW'
  #define fourccXWMA 'AMWX'
  #define fourccDPDS 'sdpd'
  #endif


////////////////////////
// PacmanApp::        //
////////////////////////

PacmanApp PacmanApp::inst;


// the window procedure.
LRESULT CALLBACK PacmanApp::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

  switch(uMsg) {
    case WM_TIMER: {
      if(wParam == 256) {
        InvalidateRect(hwnd, &inst.rect, true);
        break;
      }
      inst.isTimeout[(UINT8) wParam] = true;
      KillTimer(hwnd, wParam);
      break;
    }

    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hDC    = BeginPaint(hwnd, &ps),     // the screen.
          memDC  = CreateCompatibleDC(hDC),   // the pacman sprite
          memDC2 = CreateCompatibleDC(memDC); // the back-buffer

      SelectObject(memDC, inst.hBM);
      SelectObject(memDC2, inst.hBM2);

      inst.callbackFn(memDC, memDC2);

      // render to the screen.
      StretchBlt(
        hDC,    0, 0, inst.rect.right, inst.rect.bottom,
        memDC2, 0, 0, inst.rect.right, inst.rect.bottom, SRCCOPY
      );

      DeleteDC(memDC);
      DeleteDC(memDC2);
      EndPaint(hwnd, &ps);
      break;
    }

    case WM_KEYDOWN: {
      inst.keyStates[wParam] = true;
      break;
    }

    case WM_KEYUP: {
      inst.keyStates[wParam] = false;
      break;
    }

    case WM_DESTROY: {
      PostQuitMessage(0);
      break;
    }
  };
  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


// find chunk from `fFile`.
HRESULT PacmanApp::FindChunk(HANDLE hFile, DWORD fourcc, DWORD& dwChunkSize, DWORD& dwChunkDataPosition) {
    HRESULT hr = S_OK;

    if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN)) {
        return HRESULT_FROM_WIN32(GetLastError() );
    }

    DWORD dwChunkType;
    DWORD dwChunkDataSize;
    DWORD dwRIFFDataSize = 0;
    DWORD dwFileType;
    DWORD bytesRead = 0;
    DWORD dwOffset  = 0;

    while (hr == S_OK) {
        DWORD dwRead;

        // read ChunkID.
        if (0 == ReadFile(hFile, &dwChunkType, sizeof(DWORD), &dwRead, NULL)) {
            hr = HRESULT_FROM_WIN32(GetLastError() );
        }

        // read ChunkDataSize.
        if(0 == ReadFile(hFile, &dwChunkDataSize, sizeof(DWORD), &dwRead, NULL) )  {
            hr = HRESULT_FROM_WIN32(GetLastError() );
        }


        if (dwChunkType == fourccRIFF) {
            dwRIFFDataSize  = dwChunkDataSize;
            dwChunkDataSize = 4;

            // read RIFFType.
            if (0 == ReadFile(hFile, &dwFileType, sizeof(DWORD), &dwRead, NULL) ) {
                hr = HRESULT_FROM_WIN32(GetLastError() );
            }
        }
        else {
            if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, dwChunkDataSize, NULL, FILE_CURRENT) ) {
                return HRESULT_FROM_WIN32(GetLastError() );
            }
        }

        dwOffset += sizeof(DWORD) * 2;

        if (dwChunkType == fourcc) {
            dwChunkSize         = dwChunkDataSize;
            dwChunkDataPosition = dwOffset;
            return S_OK;
        }

        dwOffset += dwChunkDataSize;

        if (bytesRead >= dwRIFFDataSize) {
            return S_FALSE;
        }
    }
    return S_OK;
}



// read chunk data from `hFile`.
HRESULT PacmanApp::ReadChunkData(HANDLE hFile, void* buffer, DWORD buffersize, DWORD bufferoffset) {
    HRESULT hr = S_OK;
    DWORD   dwRead;

    if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, bufferoffset, NULL, FILE_BEGIN) ) {
        return HRESULT_FROM_WIN32(GetLastError() );
    }
    if (0 == ReadFile(hFile, buffer, buffersize, &dwRead, NULL) ) {
        hr = HRESULT_FROM_WIN32(GetLastError() );
    }
    return hr;
}


// initialize the pacmen application.
bool PacmanApp::Init(HINSTANCE hInstance, int nWidth, int nHeight) {
   const wchar_t className[] = L"PACMAN-CLASS";

   wc.lpfnWndProc   = WndProc;
   wc.hInstance     = this->hInstance = hInstance;
   wc.lpszClassName = className;

   RegisterClass(&wc);

   hwnd = CreateWindowEx(
     0,
     className,
     L"PAC-MAN",
     WS_OVERLAPPEDWINDOW,
     CW_USEDEFAULT,
     CW_USEDEFAULT,
     nWidth,
     nHeight,
     NULL,
     NULL,
     hInstance,
     NULL
   );

   if(hwnd == NULL) {
     return false;
   }

   hBM = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP1) );
   GetClientRect(hwnd, &rect);
   GetObject(hBM, sizeof(bm), &bm);

   {
     HDC hDC = GetDC(hwnd);
     hBM2 = CreateCompatibleBitmap(hDC, rect.right, rect.bottom);
     ReleaseDC(hwnd, hDC);
   }

   // create COM
   if (FAILED(CoInitializeEx(nullptr, COINIT_MULTITHREADED)) ) {
       return false;
   }

   if (FAILED(XAudio2Create(&pXAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR) ) ) {
       return false;
   }

   if (FAILED(pXAudio2->CreateMasteringVoice(&pMasterVoice) ) ) {
       return false;
   }

   return true;
}


// load the desired sound file.
bool PacmanApp::LoadSound(const wchar_t strFileName[]) {
   HANDLE hFile = CreateFile(
       strFileName,
       GENERIC_READ,
       FILE_SHARE_READ,
       NULL,
       OPEN_EXISTING,
       0,
       NULL
   );

   if (INVALID_HANDLE_VALUE == hFile) {
       return false;
   }

   if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN) ) {
       CloseHandle(hFile);
       return false;
   }

   DWORD dwChunkSize;
   DWORD dwChunkPosition;
   DWORD filetype;
   WAVEFORMATEXTENSIBLE wfx = { 0 };

   // check the file type, should be fourccWAVE or 'XWMA'
   FindChunk(hFile, fourccRIFF, dwChunkSize, dwChunkPosition);
   ReadChunkData(hFile, &filetype, sizeof(DWORD), dwChunkPosition);

   if (filetype != fourccWAVE) {
       CloseHandle(hFile);
       return false;
   }

   FindChunk(hFile, fourccFMT, dwChunkSize, dwChunkPosition);
   ReadChunkData(hFile, &wfx, dwChunkSize, dwChunkPosition);

   wfx.Format.wFormatTag;
   wfx.Format.nChannels;
   wfx.Format.nSamplesPerSec;
   wfx.Format.nAvgBytesPerSec;

   // fill out the audio data buffer with the contents of the fourccDATA
   FindChunk(hFile, fourccDATA, dwChunkSize, dwChunkPosition);
   audioList.push_back({
       new BYTE[dwChunkSize], 
       dwChunkSize, 
       nullptr,
       wfx,
       1
   });

   ReadChunkData(hFile, audioList.back().pDataBuffer, dwChunkSize, dwChunkPosition);
   CloseHandle(hFile);
   return true;
}



 // start the sound identified by `sndID`.
bool PacmanApp::StartSound(UINT sndID, float playLength) {
    if (sndID < audioList.size() ) {
           auto& curAudio = audioList[sndID];
           const auto SampleSize = (curAudio.dwChunkSize * 8) / (curAudio.wfx.Format.wBitsPerSample * curAudio.wfx.Format.nChannels);

           if (curAudio.pSourceVoice) {
               XAUDIO2_VOICE_STATE voiceState;
               curAudio.pSourceVoice->GetState(&voiceState);

               // There is only one buffer of same kind sound.
               if (voiceState.BuffersQueued >= curAudio.nOverlapped) {
                   return false;
               }
           }

           buffer.AudioBytes = curAudio.dwChunkSize;  // size of the audio buffer in bytes.
           buffer.pAudioData = curAudio.pDataBuffer;  // buffer containing audio data.
           buffer.Flags      = XAUDIO2_END_OF_STREAM; // tell the source voice not to expect any data after the buffer.
           buffer.PlayBegin  = 0;
           buffer.PlayLength = SampleSize * playLength;

           if (curAudio.pSourceVoice==nullptr && FAILED(pXAudio2->CreateSourceVoice(&curAudio.pSourceVoice, (WAVEFORMATEX*)&curAudio.wfx)) ) {
               return false;
           }
           if (FAILED(curAudio.pSourceVoice->SubmitSourceBuffer(&buffer) )   ) {
                return false;
           }
           if (FAILED(curAudio.pSourceVoice->Start(0) ) ) {
                return false;
           }
    }
    return true;
}



// stop the sound identified by `sndID`.
bool PacmanApp::StopSound(UINT sndID) {
    if (sndID < audioList.size() ) {
       auto& curAudio = audioList[sndID];

       if (curAudio.pSourceVoice) {
           curAudio.pSourceVoice->Stop();
           curAudio.pSourceVoice->FlushSourceBuffers();
           return true;
       }
    }
    return false;
 }















































