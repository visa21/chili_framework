#include "Goal.h"

Goal::Goal(std::mt19937_64& rng, const Board& brd, const Snake& snek)
{
    Respawn(rng, brd, snek);
}

void Goal::Draw(Board& brd) const
{
    brd.Draw_Cell(loc, c);
}

void Goal::Respawn(std::mt19937_64& rng, const Board& brd, const Snake& snek)
{
    std::uniform_int_distribution<int> xDist(0, brd.Get_Grid_W() - 1);
    std::uniform_int_distribution<int> yDist(0, brd.Get_Grid_H() - 1);
    Location newLoc;
    do {
        newLoc.x = xDist(rng);
        newLoc.y = yDist(rng);
    } while (snek.IllegalLocation(newLoc));
    loc = newLoc;
}

Location Goal::GetLocation() const
{
    return loc;
}
 