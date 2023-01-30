
// PacmanApp.hpp
# pragma once
# include<Windows.h>
# include<functional>
# include<xaudio2.h>
# include<vector>
# include"resource.h"


//////////////////////
// PacmanApp        //
//////////////////////


class PacmanApp {
 using Delegate = std::function<void(HDC,HDC)>;

 struct AudioData {
     BYTE*                pDataBuffer;
     DWORD                dwChunkSize;
     IXAudio2SourceVoice* pSourceVoice;
     WAVEFORMATEXTENSIBLE wfx;
     UINT                 nOverlapped;
 };

 // the window procedure.
 static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

 // find chunk from `fFile`.
 static HRESULT FindChunk(HANDLE hFile, DWORD fourcc, DWORD& dwChunkSize, DWORD& dwChunkDataPosition);

 // read chunk data from `fFile`.
 static HRESULT ReadChunkData(HANDLE hFile, void* buffer, DWORD buffersize, DWORD bufferoffset);


private:
 // for message loop.
 HINSTANCE hInstance = NULL;
 HWND      hwnd      = NULL;
 WNDCLASS  wc        = { 0 };
 MSG       msg       = { 0 };

 // for rendering.
 HBITMAP hBM  = NULL;
 HBITMAP hBM2 = NULL;
 RECT    rect;
 BITMAP  bm; 

 // for the application.
 Delegate callbackFn     = nullptr;
 bool     keyStates[255] = { 0 };
 bool     isTimeout[256] = { 0 };

 // for sound.
 IXAudio2*               pXAudio2     = nullptr;
 IXAudio2MasteringVoice* pMasterVoice = nullptr;
 XAUDIO2_BUFFER          buffer       = { 0 };
 std::vector<AudioData>  audioList;

private:
 // default constructor.
 PacmanApp() = default;


 // copy constructor.
 PacmanApp(const PacmanApp&) = delete;

 
 // move constructor.
 PacmanApp(PacmanApp&&) = delete;


 // destructor.
 ~PacmanApp() {
    if(hBM) DeleteObject(hBM);
    if(hBM2) DeleteObject(hBM2);

    for (auto& i : audioList) {
        delete[] i.pDataBuffer;
    }
 }

public:
 static PacmanApp inst;


 // initialize the pacman application.
 bool Init(HINSTANCE hInstance, int nWidth, int nHeight);


 // load the desired sound file.
 bool LoadSound(const wchar_t strFileName[]);


 // start the sound identified by `sndID`.
 bool StartSound(UINT sndID, float playLength);


 // stop the sound identified by `sndID`.
 bool StopSound(UINT sndID);


 // set volume
 bool SetVolume(UINT sndID, float volume) {
     if (sndID < audioList.size() ) {
         auto& curAudio = audioList[sndID];

         if (curAudio.pSourceVoice) {
             curAudio.pSourceVoice->SetVolume(volume);
             return true;
         }
     }
     return false;
 }


 // set 
 bool SetSoundOverlappedNumber(UINT sndID, UINT nOverlapped) {
     if (sndID < audioList.size() ) {
         auto& curAudio = audioList[sndID];
         curAudio.nOverlapped = nOverlapped;
         return true;
     }
     return false;
 }


 // run the pacman application.
 template<typename Functor>
 void Run(Functor&& callbackFn, int nCmdShow, UINT fps){
    if(this->callbackFn = std::forward<Functor>(callbackFn) ) {
       ShowWindow(hwnd, nCmdShow);
       SetTimer(hwnd, 256, (1000 / fps), NULL);

       while(GetMessage(&msg, 0, 0, 0) ) {
         TranslateMessage(&msg);
         DispatchMessage(&msg);
       }
        KillTimer(hwnd, 256);
    }
 }


 // check if the keyboard input on `keyCode` is true
 bool GetKey(UINT8 keyCode) const { 
    return keyStates[keyCode]; 
 } 


 // set timer event.
 void SetTimeout(UINT8 timerID, UINT elapse) {
   isTimeout[timerID] = false;
   SetTimer(hwnd, timerID, elapse, NULL);
 }


 // cancel timer event.
 void ClearTimeout(UINT8 timerID) {
   KillTimer(hwnd, timerID);
   isTimeout[timerID] = false;
 }


 // check if the timer is over.
 bool IsTimeout(UINT8 timerID) const {
   return isTimeout[timerID];
 }


 // get the screen's width.
 UINT Width() const { return rect.right; }


 // get the screen's height.
 UINT Height() const { return rect.bottom; }


 // get the bitmap's width.
 UINT BmWidth() const { return bm.bmWidth; }


 // get the bitmap's height.
 UINT BmHeight() const { return bm.bmHeight; }


 // alert the given message
 void Alert(const wchar_t inMsg[]) {
   MessageBox(hwnd, inMsg, NULL, MB_OK);
 }


 // terminate the pacman application.
 void Exit() const {
   PostQuitMessage(0);
 }
};







