# google-pacman-replica
google-pacman replica with WIN32 API

<img src='https://github.com/teumal/google-pacman-replica/blob/main/pacman%20screenshot.PNG?raw=true'></img>

## Overview
구글에 **팩맨** 이라고 검색하면 나오는 게임의 레플리카입니다. 디자인과 이미지의 출처는 [PAC-MAN Doodle](https://www.google.com/search?q=%ED%8C%A9%EB%A7%A8&sxsrf=AJOqlzXBLCsyMjlyfYBAdCktiTSromhGOQ%3A1675050104488&source=hp&ei=eDzXY5qqG5vw4-EPz-mc4As&iflsig=AK50M_UAAAAAY9dKiHjFIRKgkVezUuriGxuUGaxih4ap&oq=&gs_lcp=Cgdnd3Mtd2l6EAMYAzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJzIHCCMQ6gIQJ1AAWABg7hRoAXAAeACAAQCIAQCSAQCYAQCwAQo&sclient=gws-wiz) 이며, 음악 파일들에 대한 출처는  [Pac-Man Sounds](https://www.classicgaming.cc/classics/pac-man/sounds),  [Pacman Sound Effects](http://soundfxcenter.com/sound_effect/search.php?sfx=Pacman) 입니다. 기본적인 룰과 조작법은 원본과 동일하지만, 아직 미완성된 부분들이 남아있습니다. 

### Todo list
- 고스트 하우스 중간에 체리, 딸기 등 과일이 등장해야 함.
- 휴식 시간 추가.
- 고스트들이 중간 통로를 이용시, 급격히 느려져야 함.

## Description
``Pacman`` 폴더에 있는 ``Pacman final.exe`` 를 실행시키는 것으로 플레이 가능합니다. 방향키로 팩맨을 조종할 수 있으며, 화면에 있는 모든 쿠키를 먹게되면 승리합니다. 

<img src="https://github.com/teumal/google-pacman-replica/blob/main/ezgif.com-gif-maker.gif?raw=true"></img><img src="https://github.com/teumal/google-pacman-replica/blob/main/ghost%20curve%20to.gif?raw=true"></img><br>
- 고스트들은 일반적으로 팩맨보다 이동속도가 조금 빠르지만, 커브를 돌 때 항상 절도 있게, 직각으로 돕니다. 반면, 팩맨은 곡선으로 돌기 때문에 미로에서 커브를 여러 번 돌면 고스트들을 따돌리는게 가능합니다. <br>

<img src="https://github.com/teumal/google-pacman-replica/blob/main/ghost%20scared.gif?raw=true"></img><img src="https://github.com/teumal/google-pacman-replica/blob/main/pacman%20death.gif?raw=true"></img><br>
- 고스트들에게 잡히게 되면, 목숨을 하나 잃게 됩니다. 하지만 팩맨이 일반 쿠키보다 3배 큰 파워 쿠키를 먹게 되면  모든 고스트들이 **겁먹음(Frightened)** 상태가 되며, 팩맨을 피해 도망다니게 됩니다. 파워 쿠키를 하나 먹고, 겁 먹음 상태인 네 마리의 고스트들을 잡아 먹으면 200 (1마리) - 400 (2마리) - 800 (3마리) - 1600 (4마리) 순으로 추가 점수를 얻게 됩니다. 이렇게 잡아먹은 고스트는 눈알만 남은 상태가 되어, 고스트 하우스로 돌아가며, 일시적으로 집에 머물게 됩니다. 겁먹음 상태의 지속 시간은 스테이지가 넘어갈 수록 줄어드며, 마지막에는 아예 겁먹음 상태가 되지 않게 됩니다. 

- 고스트들은 각자 다른 알고리즘으로 팩맨을 추격하거나 도망갑니다. 고스트들이 가질 수 있는 상태는 다음 중 하나입니다:
``` c++
enum struct GhostState : UINT {
  NONE, READY, START, SCATTER, WANDER, CHASE, FRIGHTENED, END
};
```

고스트들은 여기서 ``NONE``, ``READY``, ``START``, ``WANDER``, ``END`` 라는 공통적인 **A.I** (Artificial Intelligence) 를 사용하며, ``CHASE``, ``FRIGHTENED`` 의 경우, 고스트에 따라 다른 알고리즘을 사용합니다. 노드의 번호는 **map info.PNG** 를 참고하길 바랍니다.



### GhostState::NONE
- 아무것도 하지 않은 상태이며, 실제 게임에서는 사용되지 않습니다. 

### GhostState::READY
- 고스트 하우스에서 대기를 하는 상태입니다. 고스트마다 각자의 방이 있으며, 나가는 순서가 다릅니다. 시간은 pinkey - inky - clyde 순입니다. 


### GhostState::START
- 고스트 하우스에서 나가는 상태입니다. 정확하게는 **261** 번 노드를 목표로 움직입니다. 목표 노드에 도착하면, 항상 ``GhostState::SCATTER`` 상태가 됩니다. 블링키는 맨 처음 이 상태로 시작합니다.

### GhostState::SCATTER
- 분산모드로, 일정시간 동안 각자의 집을 배회하는 상태입니다. 이 상태에서 고스트들은 팩맨을 공격하지 않습니다. 단, 지속시간이 매우 짧습니다. <br><br>
``blinky`` - 1시 방향에 있는 집을 배회합니다. 정확하게는 **91** 번 노드와 **55** 번 노드를 도는 것을 반복합니다.<br>
``pinkey`` - 11시 방향에 있는 집을 배회합니다. 정확하게는 **0**번 노드와 **64** 번 노드를 도는 것을 반복합니다. <br>
``inky`` - 7시 방향에 있는 집을 배회합니다. 정확하게는 **183**번 노드와 **182** 번 노드를 도는 것을 반복합니다.<br>
``clyde`` - 5시 방향에 있는 집을 배회합니다. 정확하게는 **173**번 노드와 **237** 번 노드를 도는 것을 반복합니다. <br>

### GhostState::WANDER
- 방랑 모드. 일반적으로 팩맨을 발견하지 못했다면, 대부분 이 상태로 있게 됩니다. 팩맨이 있는 노드를 목표로 하는 것은 아니지만, 플레이어와 최대한 가까워지는 방향으로 이동합니다. 예를 들어, 플레이어가 우측 하단에 있다면 고스트들은 ``DIR::RIGHT``, ``DIR::DOWN`` 방향을 우선적으로 이동을 하게 됩니다. 만약, 현재 움직이는 방향으로 8 칸 범위에 팩맨이 들어오게 되면, 팩맨을 발견하게 되고 ``GhostState::CHASE`` 상태로 변경됩니다. 반대로 찾지 못하고 일정시간을 맴돌았다면,  ``GhostState::WANDER``, ``GhostState::CHASE``, ``GhostState::SCATTER`` 중 하나의 상태로 무작위로 변경되게 됩니다( 확률은 ``CHASE`` < ``SCATTER`` < ``WANDER`` 순입니다 ). 

### GhostState::CHASE
- 추격 모드로, 고스트마다 다른 알고리즘을 사용하여 목표 노드를 정해 이동합니다. 만약, 아래의 알고리즘을 사용한 결과가  **팩맨으로 갈 수 있는 길이 존재하지 않다** 라면, 블링키와 똑같은 알고리즘으로 팩맨을 추격합니다. <br>

``blinky`` - 팩맨에게 도달할 수 있는 최단 거리를 계산해서 이동합니다. 정확하게는 팩맨이 현재 머물고 있는 노드를 목표로 합니다. <br><br>
``pinkey`` - 팩맨이 다음에 어디로 갈지를 예측해서 이동합니다. 정확하게는 팩맨이 현재 머물고 있는 노드의 4 칸 앞을 목표로 합니다. <br><br>
``inky`` - 팩맨과 블링키의 위치를 보고, 가장 효율적으로 잡을 수 있는 길로 쫓아옵니다. 정확하게는 팩맨이 있는 노드의 2 칸 앞을 중심으로, 블링키의 현재 위치의 회전 대칭한 지점을 목표로 합니다.  <br><br>
``clyde`` - 블링키와 똑같이 이동하다, 팩맨 8 칸 범위에 들어오면, 겁먹음 모드 처럼 도망갑니다. 정확하게는 팩맨이 현재 머물고 있는 노드를 목표로 하다, 거리가 8 칸 이하로 좁혀지면, 플레이가 있는 노드를 피해 **183** 번 또는 **182** 번 노드를  도망갑니다.<br><br>

### GhostState::FRIGHTENED
- 겁먹음 상태로, 고스트들이 팩맨을 피해 달아나는 상태입니다. 이 상태가 되면, 고스트들의 이동속도가 저하됩니다. ``GhostState::WANDER`` 와 비슷한 로직을 사용합니다. 단, 이 상태와는 다르게 각자의 집이 있는 방향으로 도망가려 하며, 플레이어가 가까이 오면  플레이어가 없으면서 자신의 집에 가까워지는 곳으로 이동하려 합니다. <br>

``blinky`` - 주로 1 시 방향으로 도망갑니다. 정확하게는 ``DIR::UP``, ``DIR::RIGHT`` 방향을 우선적으로 이동합니다.<br>
``pinkey`` - 주로 11 시 방향으로 도망갑니다. 정확하게는 ``DIR::UP``, ``DIR::LEFT`` 방향을 우선적으로 이동합니다. <br>
``inky`` - 주로 5시 방향으로 도망갑니다. 정확하게는 ``DIR::DOWN``, ``DIR::LEFT`` 방향을 우선적으로 이동합니다. <br>
``clyde`` 주로 7시 방향으로 도망갑니다. 정확하게는 ``DIR::DOWN``, ``DIR::RIGHT`` 방향을 우선적으로 이동합니다.  <br>

### GhostState::END
- 겁먹음 상태에서 팩맨에게 먹혀 눈알만 남은 상태로, 고스트 하우스로 아주 빠르게 복귀하는 상태입니다. 집에 도착한 후에는 ``GhostState::READY`` 상태로 변경됩니다.


## Implmentation

### Rendering an image.
``` c++
///////////////////
// Sprite        //
///////////////////

struct Sprite {
 int sx, sy, sWidth, sHeight;
 int dx, dy, dWidth, dHeight;

public:
 void Render(HDC srcDC, HDC destDC) const {
   StretchBlt(
     destDC, dx, dy, dWidth, dHeight,
     srcDC,  sx, sy, sWidth, sHeight, SRCCOPY
   );
 }
};
```
게임에 등장하는 모든 객체들은 화면에 렌더링하기 위해서, ``sx,sy,sWidth,sHeight`` 과 ``dx,dy,dWidth,dHeight`` 를 세팅한 후,  ``Sprite::Render`` 함수를 사용해야 합니다. 첫번쨰 인자 ``srcDC`` 는  ``pacman.bmp`` 를 가리키는 memory device context 의 핸들이며, ``destDC`` 는 ``srcDC`` 에서 잘라온 이미지를 붙여넣을 후면 버퍼(back-buffer)를 가리키는 memory device context 에 대한 핸들입니다. ``srcDC`` 와 ``destDC`` 는 ``PacmanApp::inst.Run`` 함수에서 콜백 호출되는 함수에서 얻어올 수 있습니다.

### Animation
``` c++
///////////////////
// SceneData     //
// Scene         //
// SceneContainer//
///////////////////

struct SceneData {
  int sx, sy, sWidth, sHeight;
};

struct Scene {
  const SceneData* contents;
  UINT totalFrame;
};

class SceneContainer : public Sprite {
  // replace the contents of the contaienr.
  SceneContainer& operator=(const std::initializer_list<Scene>& lst);
  
  // add the new scenes.
  void AddScene(const std::initializer_list<Scene>& lst);
  
  // select the desired scene.
  bool SelectScene(UINT sceneID);
  
  // select the desired frame.
  bool SelectFrame(UINT nFrame);
  
  // update the current frame to the next.
  // you must have called to `SelectScene` or `SelectFrame` before.
  void NextFrame();
};
```
애니메이션이 필요한 객체들은 ``Sprite`` 를 상속받은 ``SceneContainer`` 타입이어야 합니다. ``SceneData`` 는 이미지에서 어느 부분을 잘라와야 하는 지에 대한 정보를 담고 있는 구조체입니다. ``Scene`` 은 여러 개의 ``SceneData`` 의 모음입니다. ``SceneContainer`` 는 여러 개의 ``Scene`` 들을 담는 컨테이너의 역할을 수행합니다. 다음은 ``SceneContainer`` 객체들을 사용하는 방법을 기술합니다:

1) ``operator=``, ``AddScene`` 를 사용해 원하는 ``Scene`` 들을 한번에 등록합니다. 등록한 ``Scene`` 들은 등록한 순으로 ``0`` 부터 차례대로 ``sceneID`` 를 부여받게 됩니다.
2) 원하는 ``Scene`` 을 선택합니다. 이를 위해 ``sceneID`` 를  ``SelectScene`` 함수에 전달합니다.
3) 선택한 ``Scene`` 에서 몇 번째 ``SceneData`` 를 사용할지, ``nFrame`` 을 ``SelectFrame`` 함수에 전달합니다.
4) ``Render`` 함수를 사용하여 화면에 렌더링합니다. 이후, 다음 프레임으로 넘기고 싶다면 ``NextFrame`` 함수를 호출합니다. ``NextFrame`` 은 다음 프레임이 존재하지 않는다면, ``0`` 번째 프레임으로 설정해줍니다.


### Update, Sound, Key Events.
``` c++
//////////////////////
// PacmanApp        //
//////////////////////

class PacmanApp {
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
  bool SetVolume(UINT sndID, float volume);
  
  // run the pacman application.
  template<typename Functor>
  void Run(Functor&& callbackFn, int nCmdShow, UINT fps);
  
  // check if the keyboard input on `keyCode` is true
  bool GetKey(UINT8 keyCode) const;
  
  // set timer event.
  void SetTimeout(UINT8 timerID, UINT elapse);
  
  // check if the timer is over.
  bool IsTimeout(UINT8 timerID) const;
};
```
- ``PacmanApp`` 클래스는 윈도우 프로그램을 초기화하는 역할을 수행합니다. 해당 클래스는 프로그램에서 딱 하나의 인스턴스 만 존재하며, ``PacmanApp.cpp`` 에 ``PacmanApp PacmanApp::inst;`` 가 정의되어 있습니다. 윈도우 프로그램을 초기화하기 위해서는 먼저 ``Init`` 함수를 호출합니다. 이후, ``Run`` 함수에 콜백함수 ``callbackFn``을 등록하고, 1초에 몇 번 호출할지 ``fps`` 를 전달합니다. 콜백함수는 반드시 ``void(HDC srcDC, HDC destDC)`` 와 같은 호출방법을 가지고 있어야 합니다. 
``PacmanApp`` 클래스는 매 ``fps`` 마다, 등록한 ``callbackFn`` 을 호출해주며.. ``callbackFn`` 이 ``destDC`` 로 렌더링한 것들을 최종적으로 ``hDC`` 화면으로 렌더링합니다.

- 특정 키보드가 눌렸는지를 확인하려면, ``GetKey`` 함수를 사용하면 됩니다. ``GetKey`` 함수에는 ``UINT8`` 타입의 virtual key code 를 전달합니다. 예를 들어, 왼쪽 방향키가 눌렸는지 확인하려면 ``PacmanApp::inst.GetKey(VK_LEFT);`` 처럼 호출합니다.

- ``PacmanApp`` 클래스는 ``SetTimeout``, ``IsTimeout`` 함수를 사용하여 timer-event 를 구현할 수 있게 해줍니다. 단, ``SetTimeout`` 에 콜백함수를 등록하는 것이 아닌, 단순히 등록한 시간이 되면, ``IsTimeout`` 으로 이를 확인하는 구조입니다.

- ``PacmanApp`` 클래스는 **소리**를 재생하기 위해서 ``LoadSound`` 와 ``StartSound``, ``StopSound``, ``SetVolume`` 등을 지원합니다. XAudio2 API 를 사용하였기 때문에, ``LoadSound`` 에는 항상 ``WAVE`` 포맷의 파일이름을 주어야 합니다. 
