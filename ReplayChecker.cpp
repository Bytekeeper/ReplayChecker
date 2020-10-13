#include "replay.h"
#include <iostream>

using namespace bwgame;
using namespace std;

struct my_replay_funcs : bwgame::replay_functions
{
    explicit my_replay_funcs(bwgame::state &st, bwgame::action_state &action_st, bwgame::replay_state &replay_st) : bwgame::replay_functions(st, action_st, replay_st) {}
};

int main(int argc, char **argv)
{
    if (argc != 3 && argc != 2)
    {
        cout << "Parameters: [<directory with *.mpq files>] <replay file>\n";
        return -1;
    }
    const char *data_dir = argc == 3 ? argv[1] : ".";

    bwgame::game_player player(data_dir);
    auto &st = player.st();
    bwgame::action_state action_st;

    bwgame::replay_state replay_state;
    my_replay_funcs replay(st, action_st, replay_state);
    replay.load_replay_file(argv[argc - 1]);

    while (!replay.is_done())
    {
        replay.next_frame();
    }
    cout << "won;player;unit score; building score; frame\n";
    for (int i : replay.active_players())
    {
        if (replay.player_won(i))
        {
            cout << "won";
        }
        else if (replay.player_defeated(i))
        {
            cout << "lost";
        }
        else
        {
            cout << "undetermined";
        }
        cout << ", \"" << replay_state.player_name[i] << "\", " << st.unit_score[i] << ", " << st.building_score[i] << ", " << replay_state.end_frame << "\n";
    }
}
