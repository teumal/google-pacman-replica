
// PacmanObject.hpp
# pragma once
# include"PacmanApp.hpp"
# include"GameObject.hpp"



/////////////////////
// PlayerScene     //
// Player          //
/////////////////////


enum struct PlayerScene : UINT {
  UP, RIGHT, DOWN, LEFT, GAMEOVER
};



class Player : public GameObject {
  DIR reservedDir = DIR::LEFT; // for player move.

  // for curving effect.
  NODEPTR curveSrc    = nullptr;
  NODEPTR curveDest   = nullptr;
  bool    curveDone1  = false;
  bool    curveDone2  = false;

private:

  // update `*this` position, curving to the destination node.
  void CurveTo();

public:
  // the player scene data.
  static const SceneData scenes[80];  


  // default constructor.
  Player() = default;

 
  // destructor.
  ~Player() = default;
  

  // initialize the contents of the container.
  Player(const std::initializer_list<Scene>& lst) : GameObject(lst) {}


  // set the source node, destination node, and the direction.
  bool SetPosition(UINT srcID, DIR inDir);

  // checks if the player is collided with the cookie on the source node.
  bool HitTestCookie(UINT cookieID) const;


  // checks if the player is curving to.
  bool IsCurveTo() const {
      return curveDest;
  }


  // update `*this` game logic.
  virtual void Update() override;
};



/////////////////////
// GhostScene      //
// GhostState      //
// GhostType       //
// Ghost           //
/////////////////////


enum struct GhostScene : UINT {
  UP, RIGHT, DOWN, LEFT,
  FRIGHTENED1, FRIGHTENED2,
  END_UP, END_RIGHT, END_DOWN, END_LEFT
};



enum struct GhostState : UINT {
  NONE,
  START,
  READY,
  SCATTER,
  WANDER,
  CHASE,
  FRIGHTENED,
  END
};


enum struct GhostType : UINT {
  BLINKY, PINKEY, INKY, CLYDE
};


class Ghost : public GameObject {
  struct Path {
    DIR  dir;
    UINT parentID;
  };

  // get priority
  UINT GetPriority(UINT srcID, UINT destID, bool(&closedList)[323]) const;


  // replace the contents of the `paths` queue.
  void SetPath(UINT srcID, UINT destID, Path(&pathDetail)[323]);


  // find the shortest paths to the node as `destID`, and set `paths` queue.
  bool FindPath(UINT destID, bool(&closedList)[323]);


  // access the first element of `paths`, and remove it.
  void NextPath();


  // checks if `*this` found `player`.
  bool FoundPlayer() const;


  // set `curDir` toward `toLeft` and `toUp`.
  void NextDir(bool toLeft, bool toUp);


  // 
  UINT GetNextID(UINT srcID, DIR dir, UINT nNext);


private:

  // the update function in the `READY` state.
  void Ready();


  // the update function in the `START` state.
  void Start();


  // the update function in the `SCATTER` state.
  void Scatter();


  // the update function in the `WANDER` state.
  void Wander();


  // the update function in the `CHASE` state.
  void Chase();


  // the update function in the `FRIGHTENED` state.
  void Frightened();


  // the update function in the `END` state.
  void End();


private:
 GhostState curState  = GhostState::NONE, 
            nextState = GhostState::NONE;
 GhostType  type;

 DIR  paths[323];  
 UINT nPath;       

 UINT speedUpCnt = 0;

public:
 // the ghost scene data.
 static const SceneData scenes[112];

 // data member for debugging
  UINT finalID = 322;

 // default constructor.
 Ghost() = default;


 // destructor.
 ~Ghost() = default;


 // initialize the contents of the container.
 Ghost(const std::initializer_list<Scene>& lst) : GameObject(lst) {}


 // set `*this` ghost type.
 void SetGhostType(GhostType inType) { type = inType; }


 // update `*this` game logic
 virtual void Update() override;


 // set `*this` ghost state.
 void SetGhostState(GhostState newState);


 // get the current state.
 GhostState CurrentState() const { return curState; }


 // check if `*this` is in `FRIGHTENED` state.
 bool IsFrightened() const {
   return (curState==GhostState::FRIGHTENED || nextState==GhostState::FRIGHTENED);
 }


 // check if `*this` is in `END` state.
 bool IsEnd() const {
   return (curState==GhostState::END || nextState==GhostState::END);
 }
};



/////////////////////
// player          //
// blinky          //
// pinkey          //
// inky            //
// clyde           //
/////////////////////

extern Player player;
extern Ghost  blinky, pinkey, inky, clyde;


///////////////////////
// numberScenes      //
// scoreEffectScenes //
// powCookieScenes   //
// _1upScenes        //
///////////////////////

extern const SceneData numberScenes[10];
extern const SceneData scoreEffectScenes[4];
extern const SceneData powCookieScenes[16];
extern const SceneData _1upScenes[16];






