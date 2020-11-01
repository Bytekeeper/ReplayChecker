[![Build status](https://ci.appveyor.com/api/projects/status/ynmypi6g8s8hfx3e?svg=true)](https://ci.appveyor.com/project/Bytekeeper/replaychecker)

## Replay Checking Tool
This is a tool to check Starcraft Broodwar replays for:
* Who took part
* Who won
* What the scores were
* How long it lasted

## build

    git submodule update --init --recursive
    mkdir build
    cmake .. -DCMAKE_BUILD_TYPE=Release -DOPENBW_DIR=../openbw
    make
