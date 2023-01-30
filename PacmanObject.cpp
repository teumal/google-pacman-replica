
// PacmanObject.cpp
# include<algorithm>
# include<random>
# include"PacmanObject.hpp"

static std::random_device                  rd;
static std::mt19937                        gen(rd() );
static std::uniform_int_distribution<UINT> dist(1500, 4000); 
static std::uniform_int_distribution<UINT> dist2(0, 9);
static std::uniform_int_distribution<UINT> dist3(15000, 20000);

constexpr UINT SPEEDUP_CNT_MAX = 4;


////////////////////////
// Player::           //
////////////////////////

constexpr SceneData pl1{3,3,14,14},  pl2{43,3,14,14}, pl3{23,3,14,14},
                    pr1{3,23,14,14}, pr2{43,3,14,14}, pr3{23,23,14,14},
	            pu1{3,43,14,14}, pu2{43,3,14,14}, pu3{23,43,14,14},
	            pd1{3,62,14,14}, pd2{43,3,14,14}, pd3{23,62,14,14};

constexpr SceneData pgg1{3,240,14,14},    pgg2{23,240,14,14},  pgg3{43,240,14,14}, 
                    pgg4{63,240,14,14},   pgg5{83,240,14,14},  pgg6{103,240,14,14}, 
	            pgg7{123,240,14,14},  pgg8{143,240,14,14}, pgg9{163,240,14,14}, 
	            pgg10{183,240,14,14}, pgg11{203,240,14,14};

// the player scene data.
const SceneData Player::scenes[] = {
  pl1,pl1,  pl2,pl2,  pl3, pl3, // left
  pr1,pr1,  pr2,pr2,  pr3,pr3,  // right
  pu1,pu1,  pu2,pu2,  pu3,pu3,  // up
  pd1,pd1,  pd2,pd2,  pd3,pd3,  // down

  // game over..
  pgg1, pgg1, pgg1, pgg1,   
  pgg2, pgg2, pgg2, pgg2,
  pgg3, pgg3, pgg3, pgg3,
  pgg4, pgg4, pgg4, pgg4,
  pgg5, pgg5, pgg5, pgg5,
  pgg6, pgg6, pgg6, pgg6,
  pgg7, pgg7, pgg7, pgg7,
  pgg8, pgg8, pgg8, pgg8,
  pgg9, pgg9, pgg9, pgg9,
  pgg10,pgg10,pgg10,pgg10,
  pgg10,pgg10,pgg10,pgg10,
  pgg10,pgg10,pgg10,pgg10,
  pgg10,pgg10,pgg10,pgg10,
  pgg11,pgg11,pgg11,pgg11
};


// set the source node, destination node, and the direction.
bool Player::SetPosition(UINT srcID, DIR inDir) {
  if(srcID != INVALID) {
    src    = &Node::map[srcID];
    dest   = &Node::map[src->adjacent[(UINT) inDir].nodeID];
    curDir = inDir;
    dx     = src->dx;
    dy     = src->dy;

    curveSrc  = nullptr;
    curveDest = nullptr;
    return true;
  }
  return false;
}


// checks if the player is collided with the cookie on the source node.
bool Player::HitTestCookie(UINT cookieID) const {
  const auto curCookie = Cookie::data[cookieID];
  const UINT distX     = abs(dx - curCookie.dx);
  const UINT distY     = abs(dy - curCookie.dy);

  if( (distX * distX) + (distY * distY) <= 900) {
    return true;
  }
  return false; 
}



// update `*this` position, curving to the destination node.
void Player::CurveTo() {
   if (!curveDone1) {
       UpdatePosition(curDir);

       if (src == curveDest) {
          src        = curveSrc;
          dest       = curveDest;
          curveDone1 = true;
       }
   }
   
   if (!curveDone2) {
       UpdatePosition(reservedDir);

       if (src == curveDest) {
          src        = curveSrc;
          dest       = curveDest;
          curveDone2 = true;
       }
   }

   if (curveDone1 && curveDone2) {
       src       = curveDest;
       dest      = &Node::map[curveDest->adjacent[(UINT)reservedDir].nodeID];
       curveSrc  = nullptr;
       curveDest = nullptr;
       curDir    = reservedDir;
       curScene  = (UINT) reservedDir;
   }
}



// update `*this` game logic.
void Player::Update() {
  PacmanApp& inst = PacmanApp::inst;

  if (curveDest) {
      CurveTo();
      NextFrame();
      return;
  }

  if(inst.GetKey(VK_UP) )    reservedDir = DIR::UP;
  if(inst.GetKey(VK_RIGHT) ) reservedDir = DIR::RIGHT;
  if(inst.GetKey(VK_DOWN) )  reservedDir = DIR::DOWN;
  if(inst.GetKey(VK_LEFT) )  reservedDir = DIR::LEFT;
  
  if(dx==src->dx && dy==src->dy) {
     const auto nextID = src->adjacent[(UINT)reservedDir].nodeID;

     if(nextID != INVALID && nextID != 318) {
        dest     = &Node::map[src->adjacent[(UINT)reservedDir].nodeID];
        curDir   = reservedDir;
        curScene = (UINT) reservedDir;
     }
  }  
  else {
    const DIR reverse[4] = { DIR::DOWN, DIR::LEFT, DIR::UP, DIR::RIGHT };

    if(reservedDir == reverse[(UINT)curDir]) {
       std::swap(src, dest);
       curDir   = reverse[(UINT)curDir];
       curScene = (UINT) curDir;
    }
    else if(reservedDir != curDir) {  
       const auto curveID = dest->adjacent[(UINT)reservedDir].nodeID;

       if(dest != &Node::map[INVALID] && curveID != INVALID  && curveID != 318) {
          const auto distX = abs(dest->dx - dx);
          const auto distY = abs(dest->dy - dy);
          const auto dist  = (distX * distX) + (distY * distY);

          if (dist < 50) {
              curveDest  = &Node::map[curveID];
              curveSrc   = src;
              dest       = curveDest;
              curveDone1 = false;
              curveDone2 = false;
              CurveTo();
              return;
          }
       }
    }
  }

  if(dest != &Node::map[INVALID]) {
    UpdatePosition(curDir);
    NextFrame();
  }
}





////////////////////////
// Ghost::            //
////////////////////////

constexpr SceneData bu1{3,83,14,14},  bu2{23,83,14,14},
	            br1{123,83,14,14},br2{143,83,14,14},
	            bd1{43,83,14,14}, bd2{63,83,14,14},
	            bl1{83,83,14,14}, bl2{103,83,14,14};

constexpr SceneData piu1{3,103,14,14},   piu2{23,103,14,14},
                    pir1{123,103,14,14}, pir2{143,103,14,14},
	            pid1{43,103,14,14},  pid2{63,103,14,14},
	            pil1 {83,103,14,14}, pil2{103,103,14,14};

constexpr SceneData iu1{3,123,14,14},   iu2{23,123,14,14},
                    ir1{123,123,14,14}, ir2{143,123,14,14}, 
                    id1{43,123,14,14},  id2{63,123,14,14},
                    il1{83,123,14,14},  il2{103,123,14,14};

constexpr SceneData cu1{3,143,14,14},   cu2{23,143,14,14},
                    cr1{123,143,14,14}, cr2{143,143,14,14},
                    cd1{43,143,14,14},  cd2{63,143,14,14},
                    cl1{83,143,14,14},  cl2{103,143,14,14};

constexpr SceneData f11{3,163,14,14},  f12{23,163,14,14},
                    f21{43,163,14,14}, f22{63,163,14,14};

constexpr SceneData eu{3,203,14,14}, er{63,203,14,14}, 
	            ed{23,203,14,14},el{43,203,14,14};


// the ghost scene data.
const SceneData Ghost::scenes[] = {
  bu1,bu1,bu1,  bu2,bu2,bu2,  // up    (Blinky)
  br1,br1,br1,  br2,br2,br2,  // right (Blinky)
  bd1,bd1,bd1,  bd2,bd2,bd2,  // down  (Blinky)
  bl1,bl1,bl1,  bl2,bl2,bl2,  // left  (Blinky)

  piu1,piu1,piu1, piu2,piu2,piu2,  // up    (Pinky)
  pir1,pir1,pir1, pir2,pir2,pir2,  // right (Pinky)
  pid1,pid1,pid1, pid2,pid2,pid2,  // down  (Pinky)
  pil1,pil1,pil1, pil2,pil2,pil2,  // left  (Pinky)

  iu1,iu1,iu1,  iu2,iu2,iu2,  // up (Inky)
  ir1,ir1,ir1,  ir2,ir2,ir2,  // right (Inky)
  id1,id1,id1,  id2,id2,id2,  // down  (Inky)
  il1,il1,il1,  il2,il2,il2,  // left (Inky)

  cu1,cu1,cu1,  cu2,cu2,cu2,  // up (Clyde)
  cr1,cr1,cr1,  cr2,cr2,cr2,  // right (Clyde)
  cd1,cd1,cd1,  cd2,cd2,cd2,  // down (Clyde)
  cl1,cl1,cl1,  cl2,cl2,cl2,  // left (Clyde) 

  f11,f11,f11,  f12,f12,f12, // frightened (1)
  f21,f21,f21,  f22,f22,f22, // frightened (2)

  eu, // up    (end)
  er, // right (end)
  ed, // down  (end)
  el, // left  (end)
};



// get priority
UINT Ghost::GetPriority(UINT srcID, UINT destID, bool(&closedList)[323]) const {
  const auto src  = &Node::map[srcID];
  const auto dest = &Node::map[destID];

  const auto x   = (dest->dx - src->dx);
  const auto y   = (dest->dy - src->dy);
  const auto ret = (x * x) + (y * y);

  if(303 <= srcID && srcID <= 312) {
     const auto src2 = (srcID < 308) ? (&Node::map[312]) : (&Node::map[303]);
     const auto x2   = (dest->dx - src2->dx);
     const auto y2   = (dest->dy - src2->dy);
     const auto ret2 = (x2 * x2) + (y2 * y2);

     return (ret < ret2) ? (ret) : (ret2);
  }

  return ret;
}



// replace the contents of the `paths` queue.
void Ghost::SetPath(UINT srcID, UINT destID, Path(&pathDetail)[323]) {
  UINT curID = destID;
  nPath = 0;

  while(curID != srcID) {
    paths[nPath++] = pathDetail[curID].dir;
    curID          = pathDetail[curID].parentID;
  }
}



// find the shortest paths to the node as `destID`, and set `paths` queue.
bool Ghost::FindPath(UINT destID, bool(&closedList)[323]) {
 struct S {
   UINT priority;
   UINT nodeID;

   bool operator<(const S& s) const {
     return (priority > s.priority);
   }
 };

 Path pathDetail[323];
 S    queue[323];
 UINT queueSize = 1;
 UINT srcID     = (src - Node::map);

 queue[0] = { 0, srcID };
 closedList[srcID] = true;


 while(queueSize) {
   S s = queue[--queueSize];
   auto adjacent = Node::map[s.nodeID].adjacent;

   for(int i=0; i<4; ++i) {
     const UINT nodeID = adjacent[i].nodeID;

     if(nodeID==INVALID || closedList[nodeID] ) {
       continue;
     }
     else if(nodeID==destID) {
        finalID = destID; // for debugging
       pathDetail[nodeID] = { DIR(i), s.nodeID };
       SetPath(srcID, destID, pathDetail);
       return true;
     }

     pathDetail[nodeID] = { DIR(i), s.nodeID };
     queue[queueSize++] = { GetPriority(nodeID, destID, closedList), nodeID };
   }
   closedList[s.nodeID] = true;
   std::sort<S*>(queue, queue+queueSize);
 }
 return false;
}



// access the first element of `paths`, and remove it.
void Ghost::NextPath() {
  DIR  dir    = paths[--nPath];
  UINT destID = src->adjacent[(UINT)dir].nodeID;

  dest   = &Node::map[destID];
  curDir = dir;

  if(curState==GhostState::END) {
    curScene = (UINT) GhostScene::END_UP + (UINT) dir;
  }
  else if(nextState!=GhostState::FRIGHTENED) {
    curScene = (UINT) dir;
  }
}



// checks if `*this` found `player`.
bool Ghost::FoundPlayer() const {
  auto curNode = &Node::map[src->adjacent[(UINT) curDir].nodeID];

  for(int i=0; i<8; ++i) {
    if(curNode==&Node::map[INVALID]) {
      break;
    }
    else if(curNode==player.Source() ) {
      return true;
    }
    const auto nextID = curNode->adjacent[(UINT)curDir].nodeID;
    curNode = &Node::map[nextID];
  }
  return false;
}


// set `curDir` toward `toLeft` and `toUp`
void Ghost::NextDir(bool toLeft, bool toUp) {
 UINT candidateID = 0;
 DIR candidate[4] = {
    (toLeft) ? (DIR::LEFT)  : (DIR::RIGHT),
    (toUp)   ? (DIR::UP)    : (DIR::DOWN),
    (toLeft) ? (DIR::RIGHT) : (DIR::LEFT),
    (toUp)   ? (DIR::DOWN)  : (DIR::UP)
 };
 const DIR reverse[4] = { DIR::DOWN, DIR::LEFT, DIR::UP, DIR::RIGHT };
 const DIR prevDir    = reverse[(UINT)curDir];

 const UINT distX = abs(player.dx - dx);
 const UINT distY = abs(player.dy - dy);

 if(distX > distY) {
   std::swap(candidate[0], candidate[1] );
   std::swap(candidate[2], candidate[3] );
 }

 for(const auto i : candidate) {
   const auto nodeID = src->adjacent[(UINT)i].nodeID;

   if(nodeID==INVALID || nodeID==318 || i==prevDir) {
     candidateID++;
     continue;
   }
   break;
 }

 curDir = (candidateID > 3) ? (prevDir) : (candidate[candidateID]);
 dest   = &Node::map[src->adjacent[(UINT)curDir].nodeID];
 
 if (curState != GhostState::FRIGHTENED) {
    SelectScene((UINT)curDir);
 }
}



// 
UINT Ghost::GetNextID(UINT srcID, DIR dir, UINT nNext) {
 for(UINT i=0; i<nNext; ++i) {
   const auto nextID = Node::map[srcID].adjacent[(UINT)dir].nodeID;

   if(nextID==INVALID) {
     break;
   }
   srcID = nextID;
 }

 return srcID;
}




// the update function in the `READY` state.
void Ghost::Ready() {
  if(curState != GhostState::READY) {
    PacmanApp::inst.SetTimeout(
      (UINT) type + 1,
      (UINT) type * 5000 + 5000
    );
    curState = GhostState::READY;
  }


  if(curScene==(UINT)GhostScene::FRIGHTENED1 && PacmanApp::inst.IsTimeout(5) ) {
     curScene = (UINT) GhostScene::FRIGHTENED2;
  }
  else if(curScene==(UINT)GhostScene::FRIGHTENED2 && PacmanApp::inst.IsTimeout(6) ) {
     SelectScene((UINT) curDir);
     nextState = GhostState::NONE;
  }

  
  if(PacmanApp::inst.IsTimeout((UINT)type+1) && dy==src->dy) {
    bool closedList[323] = { 0 };
    FindPath(261, closedList);
    Start();
    return;
  }

  if(curDir==DIR::UP) {
     if((dy-=3) <= (src->dy-8) ) {
        curDir   = DIR::DOWN;
        curScene = (nextState==GhostState::FRIGHTENED) ? (curScene) : UINT(GhostScene::DOWN);
     }
  }
  else {
     if((dy+=3) >= (src->dy+8) ) {
        curDir   = DIR::UP;
        curScene = (nextState==GhostState::FRIGHTENED) ? (curScene) : UINT(GhostScene::UP);
     }
  }
  NextFrame();
}



// the update function in the `START` state.
void Ghost::Start() {
 if(curState != GhostState::START) {
   speed    = 2;
   curState = GhostState::START; 
 }


 if(curScene==(UINT)GhostScene::FRIGHTENED1 && PacmanApp::inst.IsTimeout(5) ) {
     curScene = (UINT) GhostScene::FRIGHTENED2;
 }
 else if(curScene==(UINT)GhostScene::FRIGHTENED2 && PacmanApp::inst.IsTimeout(6) ) {
     SelectScene((UINT) curDir);
     nextState = GhostState::NONE;
 }


 if(dx==src->dx && dy==src->dy) {
   if(nPath==0) {

      if(nextState==GhostState::END) {
        End();
        return;
      }
      else if(nextState==GhostState::FRIGHTENED) {
        Frightened();
        return;
      }
      else {
        Scatter();
        return;
      }
   }
   NextPath();
 }
 
 UpdatePosition(curDir);
 NextFrame();
}



// the update function in the `SCATTER` state.
void Ghost::Scatter() {
  if(curState != GhostState::SCATTER) {
    PacmanApp::inst.SetTimeout((UINT)type +7, dist(gen) );
    curState = GhostState::SCATTER;
    speed    = 3;
    nPath    = 0;
  }

  if(nextState == GhostState::FRIGHTENED) {
     Frightened();
     return;
  } 

  else if(dx==src->dx && dy==src->dy) {
     
    if(nextState == GhostState::END) {
      End();
      return;
    }

    else if(PacmanApp::inst.IsTimeout((UINT)type + 7) ) {
      const auto rand = dist2(gen);

      if(rand < 8) Wander();
      else         Chase();
      return;
    }

    else if(nPath==0) {

      bool closedList[323] = { 0 };
      const DIR reverse[4] = { DIR::DOWN, DIR::LEFT, DIR::UP, DIR::RIGHT };
      const UINT prevDir   = (UINT) reverse[(UINT)curDir];
      const UINT prevID    = src->adjacent[prevDir].nodeID;

      closedList[prevID] = true;
      closedList[318]    = true;

      switch(type) {
        case GhostType::BLINKY: {
           if(src==&Node::map[55]) {
              FindPath(91, closedList);
           }
           else if(!FindPath(55, closedList) ) {
              closedList[prevID] = false;
              FindPath(55, closedList);
           }
           break;
        }

        case GhostType::PINKEY: {
           if(src==&Node::map[0]) {
              FindPath(64, closedList);
           }
           else if(!FindPath(0, closedList) ) {
              closedList[prevID] = false;
              FindPath(0, closedList);
           }
           break;
        }

        case GhostType::INKY: {
           if(src==&Node::map[182]) {
              FindPath(183, closedList);
           }
           else if(!FindPath(182, closedList) ) {
              closedList[prevID] = false;
              FindPath(182, closedList);
           }
           break;
        }

        case GhostType::CLYDE: {
           if(src==&Node::map[237]) {
              FindPath(173, closedList);
           }
           else if(!FindPath(237, closedList) ) {
              closedList[prevID] = false;
              FindPath(237, closedList);
           }
           break;
        }
      };
    }

    NextPath();
  }

  if (speedUpCnt == SPEEDUP_CNT_MAX) {
      speed += 1;
      UpdatePosition(curDir);
      speed -= 1;
      speedUpCnt = 0;
  }
  else {
     UpdatePosition(curDir);
     speedUpCnt++;
  }
  NextFrame();
}



// Update function in `WANDER` state.
void Ghost::Wander() {
  if(nextState == GhostState::FRIGHTENED) {
    Frightened();
    return;
  }

  if(curState != GhostState::WANDER) {
    PacmanApp::inst.SetTimeout((UINT)type + 11, dist3(gen) );
    speed    = 3;
    curState = GhostState::WANDER;
  }

  if(dx==src->dx && dy==src->dy) {

     if(nextState==GhostState::END) {
       End();
       return;
     }
     else if(PacmanApp::inst.IsTimeout((UINT)type + 11) ) {
        const auto rand = dist2(gen);

        if(rand < 2) { 
           Chase(); 
           return; 
        }
        else if(rand < 7) {
           curState = GhostState::NONE; // for setting a new timer.
           Wander();
           return;
        }
        else {
           Scatter();
           return;
        }
     }
     else if(FoundPlayer() ) {
       Chase();
       return;
     }
     
     NextDir(
       player.dx < dx,
       player.dy < dy
     );
  }

  if (speedUpCnt == SPEEDUP_CNT_MAX) {
      speed += 1;
      UpdatePosition(curDir);
      speed -= 1;
      speedUpCnt = 0;
  }
  else {
     UpdatePosition(curDir);
     speedUpCnt++;
  }
  NextFrame();
}



// the update function in the `CHASE` state.
void Ghost::Chase() {
  if(nextState == GhostState::FRIGHTENED) {
    Frightened();
    return;
  }

  if(curState != GhostState::CHASE) {
    UINT playerSrcID = (player.Source() - Node::map);
    bool closedList[323]   = { 0 };
    
    closedList[318] = true;
    speed           = 3;
    curState        = GhostState::CHASE;
    nPath           = 0;
   
    switch(type) {
       case GhostType::BLINKY: {
          FindPath(playerSrcID, closedList);
          break;
       }
       case GhostType::PINKEY: {
          playerSrcID = GetNextID(playerSrcID, player.CurrentDir(), 4);
          FindPath(playerSrcID, closedList);
          break;
       }
       case GhostType::INKY: {
          playerSrcID = GetNextID(playerSrcID, player.CurrentDir(), 2);
          
          DIR dirX = (player.dx > blinky.dx) ? (DIR::RIGHT) : (DIR::LEFT);
          DIR dirY = (player.dy > blinky.dy) ? (DIR::DOWN)  : (DIR::UP);

          const UINT distX = abs(blinky.dx - Node::map[playerSrcID].dx);
          const UINT distY = abs(blinky.dy - Node::map[playerSrcID].dy);

          if(player.Source()->adjacent[(UINT)dirX].nodeID==INVALID) {
             playerSrcID = GetNextID(playerSrcID, dirY, (distX / 23) );
             playerSrcID = GetNextID(playerSrcID, dirX, (distY / 23) );
          }
          else {
             playerSrcID = GetNextID(playerSrcID, dirX, (distX / 23) );
             playerSrcID = GetNextID(playerSrcID, dirY, (distY / 23) );
          }

          FindPath(playerSrcID, closedList);
          break;
       }
       case GhostType::CLYDE: {
          FindPath(playerSrcID, closedList);

          if(nPath <= 8) {
            closedList[playerSrcID] = true;
            
            if(!FindPath(183, closedList) ) {
              FindPath(182, closedList);
            }
          }
          break;
       }
    };

    // case when `FindPath` is failed..
    if (nPath == 0) {
         UINT playerSrcID = (player.Source() - Node::map);
         bool closedList[323]   = { 0 };

         closedList[318] = true;
         FindPath(playerSrcID, closedList); // apply blinky's AI.
    }
  }


  if(dx==src->dx && dy==src->dy) {

     if(nextState==GhostState::END) {
        End();
        return;
     }
     else if(nPath==0) {
        const auto rand = dist2(gen);

        if(rand < 5) {
          Wander();
        }
        else {
          curState = GhostState::NONE; // for setting new paths.
          Chase();
        }
        return;
     }
     else if (type == GhostType::CLYDE && FoundPlayer() ) {
         bool closedList[323] = { 0 };
         UINT playerSrcID = (player.Source() - Node::map);

         closedList[playerSrcID] = true;
        
         if(!FindPath(183, closedList) ) {
            closedList[playerSrcID] = false;
            FindPath(182, closedList);
         }
     }

     NextPath();
  }

  if (speedUpCnt == SPEEDUP_CNT_MAX) {
      speed += 1;
      UpdatePosition(curDir);
      speed -= 1;
      speedUpCnt = 0;
  }
  else {
     UpdatePosition(curDir);
     speedUpCnt++;
  }
  NextFrame();
}



// the update function in the `FRIGHTENED` state.
void Ghost::Frightened() {
  if(curState != GhostState::FRIGHTENED) {
     speed    = 2;
     curState = GhostState::FRIGHTENED;
  }

  if(curScene==(UINT)GhostScene::FRIGHTENED1 && PacmanApp::inst.IsTimeout(5) ) {
     curScene  = (UINT) GhostScene::FRIGHTENED2;
     nextState = GhostState::NONE;
  }

  if(dx==src->dx && dy==src->dy) {
    
     if(nextState == GhostState::END) {
       End();
       return;
     }
     else if(curScene==(UINT)GhostScene::FRIGHTENED2 && PacmanApp::inst.IsTimeout(6) ) {
        SelectScene((UINT) curDir);
        nextState = GhostState::NONE;

        const auto rand = dist2(gen);

        if(rand < 3) {
          Chase();
        }
        else if(rand < 6) {
          Wander();
        }
        else {
          Scatter();
        }
        return;
     }

     bool toLeft, toUp;
     const UINT distX = abs(player.dx - dx);
     const UINT distY = abs(player.dy - dy);

     switch(type) {
        case GhostType::BLINKY: {
           toLeft = false;
           toUp   = true;
           break;
        }
        case GhostType::PINKEY: {
           toLeft = true;
           toUp   = true;
           break;
        }
        case GhostType::INKY: {
           toLeft = true;
           toUp   = false;
           break;
        }
        case GhostType::CLYDE: {
           toLeft = false;
           toUp   = false;
           break;
        }
     };

     if(distX < 69) toLeft = (player.dx > dx) ? (true) : (false);
     if(distY < 69) toUp   = (player.dy > dy) ? (true) : (false);    
     
     NextDir(toLeft, toUp);
  }

  UpdatePosition(curDir);
  NextFrame();
}



// the update function in `END` state.
void Ghost::End() {
  if(curState != GhostState::END) {
    speed     = 10;
    curState  = GhostState::END;
    nextState = GhostState::NONE;

    bool closedList[323] = { 0 };

    if(type < GhostType::PINKEY) {
      FindPath(318, closedList);
    }
    else if(type==GhostType::INKY) {
      FindPath(317, closedList);
    }
    else {
      FindPath(319, closedList);
    }
  }

  if(dx==src->dx && dy==src->dy) {
     if(nPath==0) {
       SelectScene((UINT) curDir);
       Ready();
       return;
     } 
     NextPath();
  }

  UpdatePosition(curDir);
  NextFrame();
}



// update `*this` game logic
void Ghost::Update() {
  const auto state = (curState==GhostState::NONE) ? (nextState) : (curState);

  switch(state) {
    case GhostState::READY: {
      Ready();
      break;
    }
    case GhostState::START: {
      Start();
      break;
    }
    case GhostState::SCATTER: {
      Scatter();
      break;
    }
    case GhostState::WANDER: {
      Wander();
      break;
    }
    case GhostState::CHASE: {
      Chase();
      break;
    }
    case GhostState::FRIGHTENED: {
      Frightened();
      break;
    }
    case GhostState::END: {
      End();
      break;
    }
  };
}



// set `*this` ghost state.
void Ghost::SetGhostState(GhostState newState) {
  
  if (newState == GhostState::NONE) {
      curState = GhostState::NONE;
  }

  else if(newState == GhostState::FRIGHTENED) {
    SelectScene((UINT) GhostScene::FRIGHTENED1);
  }
  else if(newState == GhostState::END) {
    SelectScene((UINT) GhostScene::END_UP + (UINT) curDir);
  }

  nextState = newState;
}


/////////////////////
// player          //
// blinky          //
// pinkey          //
// inky            //
// clyde           //
/////////////////////

Player player = {
     {Player::scenes + 12,  6}, // up
     {Player::scenes + 6,  6},  // right
     {Player::scenes + 18,  6}, // down
     {Player::scenes + 0,  6},  // left
     {Player::scenes + 24, 56}, // gameover
};

Ghost blinky = {
     {Ghost::scenes,      6}, // up
     {Ghost::scenes + 6,  6}, // right
     {Ghost::scenes + 12, 6}, // down
     {Ghost::scenes + 18, 6}, // left

     {Ghost::scenes + 96, 6}, // frightened
     {Ghost::scenes + 96, 12},// frightened 2

     {Ghost::scenes + 108, 1},  // end_up
     {Ghost::scenes + 109, 1},  // end_right
     {Ghost::scenes + 110, 1}, // end_down
     {Ghost::scenes + 111, 1}, // end_left
};


Ghost pinkey = {
     {Ghost::scenes + 24, 6}, // up
     {Ghost::scenes + 30, 6}, // right
     {Ghost::scenes + 36, 6}, // down
     {Ghost::scenes + 42, 6}, // left

     {Ghost::scenes + 96, 6}, // frightened
     {Ghost::scenes + 96, 12},// frightened 2

     {Ghost::scenes + 108, 1},  // end_up
     {Ghost::scenes + 109, 1},  // end_right
     {Ghost::scenes + 110, 1}, // end_down
     {Ghost::scenes + 111, 1}, // end_left
};


Ghost inky = {
     {Ghost::scenes + 48, 6}, // up
     {Ghost::scenes + 54, 6}, // right
     {Ghost::scenes + 60, 6}, // down
     {Ghost::scenes + 66, 6}, // left

     {Ghost::scenes + 96, 6}, // frightened
     {Ghost::scenes + 96, 12},// frightened 2

     {Ghost::scenes + 108, 1},  // end_up
     {Ghost::scenes + 109, 1},  // end_right
     {Ghost::scenes + 110, 1}, // end_down
     {Ghost::scenes + 111, 1}, // end_left
};


Ghost clyde = {
     {Ghost::scenes + 72, 6}, // up
     {Ghost::scenes + 78, 6}, // right
     {Ghost::scenes + 84, 6}, // down
     {Ghost::scenes + 90, 6}, // left

     {Ghost::scenes + 96, 6}, // frightened
     {Ghost::scenes + 96, 12},// frightened 2

     {Ghost::scenes + 108, 1},  // end_up
     {Ghost::scenes + 109, 1},  // end_right
     {Ghost::scenes + 110, 1}, // end_down
     {Ghost::scenes + 111, 1}, // end_left
};




//////////////////
// numberScenes //
//////////////////

const SceneData numberScenes[] = {
  {11, 180, 10, 10}, // 0
  {21, 180, 10, 10}, // 1
  {31, 180, 10, 10}, // 2
  {41, 180, 10, 10}, // 3
  {51, 180, 10, 10}, // 4
  {61, 180, 10, 10}, // 5
  {71, 180, 10, 10}, // 6
  {81, 180, 10, 10}, // 7
  {91, 180, 10, 10}, // 8
  {101, 180, 10, 10} // 9
};


///////////////////////
// scoreEffectScenes //
///////////////////////

const SceneData scoreEffectScenes[] = {
  {3,223,18,14}, // 200
  {23,223,18,14},// 400
  {43,223,18,14},// 800
  {58,223,25,14} // 1600
};


///////////////////////
// powCookieScenes   //
///////////////////////

constexpr SceneData pow1{1, 180, 10, 10},
                    pow2{1, 191, 10, 10};

const SceneData powCookieScenes[] = {
  pow1, pow1, pow1, pow1,   pow1, pow1, pow1, pow1, 
  pow2, pow2, pow2, pow2,   pow2, pow2, pow2, pow2
};


///////////////////////
// _1upScenes        //
///////////////////////

constexpr SceneData _1up1{ 215, 70, 26, 10 },
                    _1up2{ 200, 50, 20, 20 };

const SceneData _1upScenes[] = {
    _1up1,_1up1,_1up1,_1up1,  _1up1,_1up1,_1up1,_1up1,
    _1up2,_1up2,_1up2,_1up2,  _1up2,_1up2,_1up2,_1up2,
};

