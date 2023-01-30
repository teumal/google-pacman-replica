
// GameObject.hpp
# pragma once
# include<Windows.h>
# include<vector>
# include<string>
# include<initializer_list>


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
protected:
  std::vector<Scene> sceneList;
  UINT curFrame, curScene;

public:
  // default constructor.
  SceneContainer() = default;


  // copy constructor.
  SceneContainer(const SceneContainer& other) { *this = other; }


  // move constructor.
  SceneContainer(SceneContainer&& other) { *this = std::move(other); }


  // initialize the contents of the container.
  SceneContainer(const std::initializer_list<Scene>& lst) { *this = lst; }


  // destructor.
  ~SceneContainer() = default;

  

  // replace the contents of the contaienr.
  SceneContainer& operator=(const std::initializer_list<Scene>& lst) { 
      sceneList.assign(lst);
      return *this;
  }


  // copy the contents of the other to `*this`.
  SceneContainer& operator=(const SceneContainer& other);


  // move the contents of the other to `*this`.
  SceneContainer& operator=(SceneContainer&& other);


  // add the new scenes.
  void AddScene(const std::initializer_list<Scene>& lst) { sceneList.insert(sceneList.end(), lst); }


  // remove the scene of `*this` identified by `sceneID`.
  bool RemoveScene(UINT sceneID);


  // select the desired scene.
  bool SelectScene(UINT sceneID);


  // select the desired frame.
  bool SelectFrame(UINT nFrame);


  // update the current frame to the next.
  // you must have called to `SelectScene` or `SelectFrame` before.
  void NextFrame();
  

  // get the current frame number.
  UINT CurrentFrame() const { return curFrame; }

  
  // get the current sceneID.
  UINT CurrentScene() const { return curScene; }


  // set the size 
  void SetSize(UINT nWidth, UINT nHeight) { 
    dWidth  = nWidth;
    dHeight = nHeight;
  }
};




///////////////////
// Node          //
///////////////////

struct Node {
  INT16 dx, dy;
  INT16 cookieID;
  struct NodeInfo {
    INT16 nodeID;
  } adjacent[4];

  static const Node map[323];
};



///////////////////
// CookieType    //
// Cookie        //
///////////////////

enum struct CookieType : INT16 {
  NORM, POW
};


struct Cookie {
  INT16 dx, dy, dWidth, dHeight;
  CookieType type;
  bool       visible;

  static Cookie data[323];  
};



///////////////////
// INVALID       //
// ADJ           //
///////////////////

constexpr UINT INVALID = 322;
constexpr UINT ADJ     = 100;



///////////////////
// DIR           //
// GameObject    //
///////////////////

enum struct DIR : UINT {
  UP, RIGHT, DOWN, LEFT, NONE
};



class GameObject : public SceneContainer {
protected:
  using NODEPTR = const Node*;

  NODEPTR src, dest;
  DIR  curDir;
  int  speed;

public:
  // default constructor.
  GameObject() = default;

 
  // destructor.
  ~GameObject() = default;


  // copy constructor.
  GameObject(const GameObject& other);


  // move constructor.
  GameObject(GameObject&& other);


  // initialize the contents of the container.
  GameObject(const std::initializer_list<Scene>& lst) : SceneContainer(lst) {}


  // update `*this` game logic.
  virtual void Update() = 0;


  // update `*this` position.
  void UpdatePosition(DIR dir);


  // check if `*this` is collided with `inObject`.
  bool HitTest(const GameObject& inObject) const;


  // set the source node, destination node, and the direction.
  bool SetPosition(UINT srcID, DIR inDir);

  
  // set the speed.
  void SetSpeed(UINT inSpeed) {  speed    = inSpeed; }


  // get the pointer to the source node.
  NODEPTR Source() const { return src; }


  // get the pointer to the destination node.
  NODEPTR Dest() const { return dest; }


  // get the current direction.
  DIR CurrentDir() const { return curDir; }
};






























