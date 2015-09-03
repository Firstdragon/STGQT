#include <ctime>

#include "Player.h"
#include "Map.h"


class bot
{
public:
        int m;
        int s;
        int z;
        int x;
        int l;
        int isherei;
        int isherej;
        bool reset;

        int move(map &map, player &playerbot, int k, int len, int wid);
};
