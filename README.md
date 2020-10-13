## Replay Checking Tool
This is a tool to check Starcraft Broodwar replays for:
* Who took part
* Who won
* What the scores were
* How long it lasted

## build

    git submodule init
    mkdir build
    cmake .. -DCMAKE_BUILD_TYPE=Release -DOPENBW_DIR=../openbw
    make