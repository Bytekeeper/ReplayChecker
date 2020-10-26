#include "replay.h"
#include "json.hpp"
#include <iostream>

using namespace bwgame;
using namespace std;
using namespace nlohmann;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Parameters: [<directory with *.mpq files>] <replay file>...\n";
        return -1;
    }
    const char *data_dir = argc == 3 ? argv[1] : ".";

    bwgame::game_player player(data_dir);
    auto &st = player.st();
    bwgame::action_state action_st;
    bwgame::replay_state replay_state;
    replay_functions replay(st, action_st, replay_state);
    replay.load_replay_file(argc == 3 ? argv[2] : argv[1]);

    json j = {
        {"end_frame", replay_state.end_frame},
        {"map", replay_state.map_name}};

    vector<json> players;

    for (int i : replay.active_players())
    {
        auto race = st.players[i].race;
        std::string race_name;
        switch (race)
        {
        case race_t::zerg:
            race_name = "zerg";
            break;
        case race_t::terran:
            race_name = "terran";
            break;
        case race_t::protoss:
            race_name = "protoss";
            break;
        }
        players.push_back({{"name", replay_state.player_name[i]}, {"race", race_name}});
    }
    j["players"] = players;
    cout << j.dump();
}