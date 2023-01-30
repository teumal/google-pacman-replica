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
고스트들은 일반적으로 팩맨보다 이동속도가 조금 빠르지만, 커브를 돌 때 항상 절도 있게, 직각으로 돕니다. 반면, 팩맨은 곡선으로 돌기 때문에 미로에서 커브를 여러 번 돌면 고스트들을 따돌리는게 가능합니다. <br>

<img src="https://github.com/teumal/google-pacman-replica/blob/main/ghost%20curve%20to.gif?raw=true"></img><br>
또한, 팩맨이 일반 쿠키보다 3배 큰 파워 쿠키를 먹게 되면  모든 고스트들이 **겁먹음(Frightened)** 상태가 됩니다. 




