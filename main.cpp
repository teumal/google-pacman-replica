
# include"PacmanApp.hpp"
# include"PacmanObject.hpp"
# include<string>

//////////////////////
// PacmanSinario    //
//////////////////////

enum struct PacmanSinario : UINT {
  READY, INTRO1, INTRO2, PLAYING, HIT_GHOST, GAMEOVER1, GAMEOVER2, WIN, LOSE
};



//////////////////////
// InitPacmanObject //
//////////////////////


void InitPacmanObjects() {
   player.SelectScene((UINT)PlayerScene::LEFT);
   player.SelectFrame(2);
   player.SetPosition(213, DIR::LEFT);
   player.SetSpeed(3);
   player.SetSize(38,38);

   blinky.SetGhostState(GhostState::NONE);
   blinky.SelectScene((UINT)GhostScene::LEFT);
   blinky.SetPosition(261, DIR::LEFT);
   blinky.SetSize(38,38);
   blinky.SetGhostState(GhostState::SCATTER);
   blinky.SetGhostType(GhostType::BLINKY);

   pinkey.SetGhostState(GhostState::NONE);
   pinkey.SelectScene((UINT)GhostScene::DOWN);
   pinkey.SetPosition(318, DIR::DOWN);
   pinkey.SetSize(38,38);
   pinkey.SetGhostState(GhostState::READY);
   pinkey.SetGhostType(GhostType::PINKEY);

   inky.SetGhostState(GhostState::NONE);
   inky.SelectScene((UINT)GhostScene::UP);
   inky.SetPosition(317, DIR::UP);
   inky.SetSize(38,38);
   inky.SetGhostState(GhostState::READY);
   inky.SetGhostType(GhostType::INKY);

   clyde.SetGhostState(GhostState::NONE);
   clyde.SelectScene((UINT)GhostScene::UP);
   clyde.SetPosition(319, DIR::UP);
   clyde.SetSize(38,38);
   clyde.SetGhostState(GhostState::READY);
   clyde.SetGhostType(GhostType::CLYDE);
}


///////////////////////
// wWinMain          //
///////////////////////

int APIENTRY wWinMain(_In_     HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_     LPWSTR    nCmdLine,
                      _In_     int       nCmdShow)
{
   if(!PacmanApp::inst.Init(hInstance, 1400, 650) ) {
     return 0;
   }


   // initialize background scenes.
   #pragma region INIT

   const UINT bmWidth  = PacmanApp::inst.BmWidth(); 
   const UINT bmHeight = PacmanApp::inst.BmHeight();

   const SceneData bgScene1{322, 0, bmWidth-322, bmHeight/2-2};

   const SceneData bgScene2{322, bmHeight/2-4, bmWidth-322, bmHeight/2-2};

   const SceneData bgScenes[] = {
     bgScene1, bgScene1, bgScene1, bgScene1, bgScene1, bgScene1,
     bgScene2, bgScene2, bgScene2, bgScene2, bgScene2, bgScene2 
   };


   // curScore, scoreEffect, cookie, readyEffect
   Sprite curScore = {
     11, 180, 10, 10,
     3,  50,  40, 40
   };

   Sprite scoreEffect = {
     58, 223, 30, 14,
     0,  0,   38, 38
   };

   Sprite cookie = { 
     1, 180, 10, 10,
     0, 0,   7,  7
   };

   Sprite readyEffect = {
     200, 0,   50,  16,
     763, 341, 200, 40
   };

   Sprite gameoverEffect = {
       11, 192, 82, 10,
       735, 338, 250, 40
   };

   Sprite door = {
       3,   107, 1, 1,
       832, 246, 58,5
   };

   Sprite life = {
       3,3,14,14,
       15, 525, 40, 40
   };

   Sprite clearScreen = {
       1, 1, 1, 1,
       0,0, 1400, 650
   };


   // powCookie, _1up, bg
   SceneContainer powCookie = {
     {powCookieScenes, 16}
   };

   powCookie.SetSize(30,30);
   powCookie.SelectScene(0);

   SceneContainer _1up = {
       {_1upScenes, 16}
   };

   _1up.SetSize(120, 40);
   _1up.SelectScene(0);
   _1up.dx = 10;
   _1up.dy = 5;


   SceneContainer bg = { 
      {bgScenes, 12} 
   };

   bg.SetSize(1384, 411);
   bg.SelectScene(0);
   bg.dx = 0;
   bg.dy = ADJ;


   // 
   PacmanSinario curSinario = PacmanSinario::READY;

   Ghost*      ghosts[] = { &blinky, &pinkey, &inky, &clyde };
   UINT        nScore   = 0;
   std::string strScore = "0";

   UINT leftCookie     = 276;
   UINT nHit           = 0;
   UINT nextScore      = 200;
   UINT frightenedTime1 = 6000;
   UINT frightenedTime2 = 3000;
   UINT nLife        = 3;
   bool hitPowCookie = false;
   bool ghostScared  = false;


   enum struct PacmanSound : UINT {
       INTRO, DEATH, CHOMP, EAT_FRUIT, EAT_GHOST, INTERMISSION, SIREN, GHOST_SCARED
   };

   // render _1up.
   auto Render1up = [&](HDC srcDC, HDC destDC) {
       _1up.Render(srcDC, destDC);
       _1up.NextFrame();
   };


   // render cookies.
   auto RenderCookie = [&](HDC srcDC, HDC destDC) {

      for(auto& i : Cookie::data) {
        if(!i.visible) {
           continue;
        }
        else if(i.type==CookieType::POW) {
          powCookie.dx = i.dx;
          powCookie.dy = i.dy;
          powCookie.Render(srcDC, destDC);
          continue;
        }
        else {
          cookie.dx      = i.dx;
          cookie.dy      = i.dy;
          cookie.Render(srcDC, destDC);
        }
      }

      powCookie.NextFrame();
   };


   // render the current score.
   auto RenderCurScore = [&](HDC srcDC, HDC destDC) {
     curScore.dx = 3;

     for(auto c : strScore) {
       c -= '0';
       curScore.sx = numberScenes[c].sx;
       curScore.sy = numberScenes[c].sy;
       curScore.Render(srcDC, destDC);
       curScore.dx += 40;
     }
   };


   // render the current line.
   auto RenderLife = [&](HDC srcDC, HDC destDC) {
       for (UINT i = 0; i < nLife; ++i) {
           life.Render(srcDC, destDC);
           life.dx += 45;
       }
       life.dx = 15;
   };


   // debug function.
   /*auto Debug = [&](HDC srcDC, HDC destDC) {
		  const wchar_t* ghostName[] = { L"blinky: ", L"pinkey: ",L"inky  : ",L"cylde : "};
		  const wchar_t* ghostState[] = { 
			  L"none         ", L"start        ", 
			  L"ready        ", L"scatter      ", 
			  L"wander       ", L"chase        ", 
			  L"frightened   ", L"end          "
		  };

		  for(int i=0; i<4; ++i) {
			  auto text = std::wstring(ghostName[i])
				              + std::to_wstring(ghosts[i]->Source() - Node::map)
				              + L" -> "
				              + std::to_wstring(ghosts[i]->Dest() - Node::map)
				              + L"  "
				              + ghostState[(UINT) ghosts[i]->CurrentState() ]
				              + L"final destination : ";
			  if (ghosts[i]->CurrentState() == GhostState::CHASE) {
                  const wchar_t* strType[] = { L"B", L"P", L"I", L"C"};
				  const auto destID = ghosts[i]->finalID;
				  const auto id = std::to_wstring(destID);
				  text += id;
				  TextOut(destDC, Node::map[destID].dx+12, Node::map[destID].dy+12, strType[i], 1);
			  }
			  else text += L"none";
			  text += L"                   ";
			  TextOut(destDC, 200, i * 15, text.c_str(), text.size() );
		  }
   };*/


   // hit test cookie.
   auto HitTestCookie = [&](const Node* node) {
       auto& hitCookie = Cookie::data[node->cookieID];

       if(hitCookie.visible && player.HitTestCookie(node->cookieID) ) {
            PacmanApp::inst.StartSound((UINT)PacmanSound::CHOMP, 0.51f);

            if(hitCookie.type == CookieType::NORM) {
              nScore += 10;
            }
            else {
              nScore      += 50;
              nHit         = 0;
              nextScore    = 200;
              hitPowCookie = true;
              ghostScared  = true;

              for(auto i : ghosts) {
                if (!i->IsEnd()) {
                    i->SetGhostState(GhostState::FRIGHTENED);
                }
              }
              PacmanApp::inst.SetTimeout(5, frightenedTime1);
            }

            strScore = std::to_string(nScore);
            hitCookie.visible = false;

            if(--leftCookie==0) {
              curSinario = PacmanSinario::WIN;
              PacmanApp::inst.SetTimeout(35, 3000);
              PacmanApp::inst.StopSound((UINT)PacmanSound::SIREN);
              PacmanApp::inst.StopSound((UINT)PacmanSound::CHOMP);
              PacmanApp::inst.StopSound((UINT)PacmanSound::GHOST_SCARED);
            }
       }
   };


   PacmanApp::inst.LoadSound(L"./Sound/pacman_beginning.wav");
   PacmanApp::inst.LoadSound(L"./Sound/pacman_death.wav");
   PacmanApp::inst.LoadSound(L"./Sound/pacman_chomp.wav");
   PacmanApp::inst.LoadSound(L"./Sound/pacman_eatfruit.wav");
   PacmanApp::inst.LoadSound(L"./Sound/pacman_eatghost.wav");
   PacmanApp::inst.LoadSound(L"./Sound/pacman_intermission.wav");
   PacmanApp::inst.LoadSound(L"./Sound/pacman_siren.wav");
   PacmanApp::inst.LoadSound(L"./Sound/pacman_ghost_scared.wav");

   PacmanApp::inst.SetSoundOverlappedNumber((UINT)PacmanSound::CHOMP, 2);
   #pragma endregion

  

   



   // main loop.
   PacmanApp::inst.Run([&](HDC srcDC, HDC destDC) {

     switch(curSinario) {
       case PacmanSinario::READY: {
         // clear screen.
         clearScreen.Render(srcDC, destDC);

         // initialize the pacman objects.
         InitPacmanObjects();
         ghostScared = false;
         hitPowCookie = false;
         bg.SelectFrame(0);
         PacmanApp::inst.SetTimeout(30, 2000);
         PacmanApp::inst.StartSound((UINT)PacmanSound::INTRO, 1.0f);
         curSinario = PacmanSinario::INTRO1;
         RenderLife(srcDC, destDC);
         break;
       }

       case PacmanSinario::INTRO1: {
          bg.Render(srcDC, destDC);
          door.Render(srcDC, destDC);
          RenderCookie(srcDC, destDC);
          RenderCurScore(srcDC, destDC);
          readyEffect.Render(srcDC, destDC);
          Render1up(srcDC, destDC);
          player.Render(srcDC, destDC);

          if(PacmanApp::inst.IsTimeout(30) ) {
            curSinario = PacmanSinario::INTRO2;
            PacmanApp::inst.SetTimeout(31, 3000);
          }
          break;
       }

       case PacmanSinario::INTRO2: {
          bg.Render(srcDC, destDC);
          door.Render(srcDC, destDC);
          RenderCookie(srcDC, destDC);
          RenderCurScore(srcDC, destDC);
          readyEffect.Render(srcDC, destDC);
          Render1up(srcDC, destDC);
          player.Render(srcDC, destDC);
 
          for(auto i : ghosts) {
             i->Render(srcDC, destDC);
          }

          if(PacmanApp::inst.IsTimeout(31) ) {
            curSinario = PacmanSinario::PLAYING;
          }
          break;
       }

       case PacmanSinario::PLAYING: {
          if (ghostScared) {
              PacmanApp::inst.StartSound((UINT)PacmanSound::GHOST_SCARED, 0.7f);
              PacmanApp::inst.SetVolume((UINT)PacmanSound::GHOST_SCARED, 0.6f);
          }
          else {
              PacmanApp::inst.StartSound((UINT)PacmanSound::SIREN, 0.9f);
          }

          // hit test with cookie.
          HitTestCookie(player.Source() );

          if (player.IsCurveTo() ) {
              const auto nodeID   = player.Source()->adjacent[(UINT)player.CurrentDir() ].nodeID;
              const auto nextNode = &Node::map[nodeID];
              HitTestCookie(nextNode);
          }


          // hit test with ghosts.
          for(auto i : ghosts) {
             if(!i->IsEnd() && player.HitTest(*i) ) {
                if(i->IsFrightened() ) {
                   PacmanApp::inst.SetTimeout(32, 1000);
                   PacmanApp::inst.StartSound((UINT)PacmanSound::EAT_GHOST, 1.0f);
                   i->SetGhostState(GhostState::END);
                   curSinario = PacmanSinario::HIT_GHOST;
                   nScore    += nextScore;
                   nextScore *= 2;
                   break;
                }
                else {
                   curSinario = PacmanSinario::GAMEOVER1;
                   PacmanApp::inst.SetTimeout(33, 1000);
                   PacmanApp::inst.StopSound((UINT)PacmanSound::SIREN);
                   PacmanApp::inst.StopSound((UINT)PacmanSound::CHOMP);
                   PacmanApp::inst.StopSound((UINT)PacmanSound::GHOST_SCARED);
                }
             }
          }

          if(hitPowCookie && PacmanApp::inst.IsTimeout(5) ) {
             hitPowCookie = false;
             PacmanApp::inst.SetTimeout(6, frightenedTime2);
          }         

          if (!hitPowCookie && ghostScared && PacmanApp::inst.IsTimeout(6) ) {
              PacmanApp::inst.StopSound((UINT)PacmanSound::GHOST_SCARED);
              ghostScared = false;
          }

          Render1up(srcDC, destDC);
          bg.Render(srcDC, destDC);
          door.Render(srcDC, destDC);
          RenderCookie(srcDC, destDC);
          RenderCurScore(srcDC, destDC);

          player.Render(srcDC, destDC);
          player.Update();

          for(auto i : ghosts) {
            i->Render(srcDC, destDC);
            i->Update();
          }
          // Debug(srcDC, destDC);
          break;
       }

       case PacmanSinario::HIT_GHOST: {
          bg.Render(srcDC, destDC);
          door.Render(srcDC, destDC);
          Render1up(srcDC, destDC);
          RenderCookie(srcDC, destDC);
          RenderCurScore(srcDC, destDC);

          for(auto i : ghosts) {
            if(!i->IsEnd() ) {
              i->Render(srcDC, destDC);
            }
          }

          scoreEffect.sx      = scoreEffectScenes[nHit].sx;
          scoreEffect.sy      = scoreEffectScenes[nHit].sy;
          scoreEffect.sWidth  = scoreEffectScenes[nHit].sWidth;
          scoreEffect.sHeight = scoreEffectScenes[nHit].sHeight;

          scoreEffect.dx = player.dx;
          scoreEffect.dy = player.dy;
          scoreEffect.Render(srcDC, destDC);

          if(PacmanApp::inst.IsTimeout(32) ) {
             nHit++;
             curSinario = PacmanSinario::PLAYING;
          }
          break;
       }

       case PacmanSinario::GAMEOVER1: {
          bg.Render(srcDC, destDC);
          Render1up(srcDC, destDC);
          door.Render(srcDC, destDC);
          RenderCookie(srcDC, destDC);
          RenderCurScore(srcDC, destDC);
          player.Render(srcDC, destDC);
          
          for(auto i : ghosts) {
            i->Render(srcDC, destDC);
          }

          if(PacmanApp::inst.IsTimeout(33) ) {
             curSinario = PacmanSinario::GAMEOVER2;
             PacmanApp::inst.SetTimeout(34, 4000);
             PacmanApp::inst.StartSound((UINT)PacmanSound::DEATH, 1.0f);
             player.SelectScene((UINT)PlayerScene::GAMEOVER);
             player.SelectFrame(0);
          }
          break;
       }

       case PacmanSinario::GAMEOVER2: {
          bg.Render(srcDC, destDC);
          Render1up(srcDC, destDC);
          door.Render(srcDC, destDC);
          RenderCookie(srcDC, destDC);
          RenderCurScore(srcDC, destDC);
          
          if(player.CurrentFrame() < 55) {
             player.Render(srcDC, destDC);
             player.NextFrame();
          }

          if (PacmanApp::inst.IsTimeout(34) ) {
              if (nLife-- == 0) curSinario = PacmanSinario::LOSE;
              else curSinario = PacmanSinario::READY;
          }
          break;
       }

       case PacmanSinario::WIN: {
          bg.Render(srcDC, destDC);
          player.Render(srcDC, destDC);
          bg.NextFrame();

          if (PacmanApp::inst.IsTimeout(35)) {
              curSinario = PacmanSinario::READY;

              for (auto i : Node::map) {
                  if (i.cookieID != INVALID) {
                      Cookie::data[i.cookieID].visible = true;
                  }
              }
              leftCookie = 276;
              
              if (frightenedTime1 != 0) {
                  frightenedTime1 -= 500;
              }
              if (frightenedTime2 != 0) {
                  frightenedTime2 -= 500;
              }
          }
          break;
       }

       case PacmanSinario::LOSE: {
           bg.Render(srcDC, destDC);
           gameoverEffect.Render(srcDC, destDC);
           break;
       }
     };
   }, nCmdShow, 60);
}











