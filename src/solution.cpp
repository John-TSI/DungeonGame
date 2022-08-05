#include"../inc/solution.hpp"
#include<cmath>
#include<algorithm>


int Solution::calculateMinimumHP(std::vector<std::vector<int>>& dungeon)
{
    const int ROWS = dungeon.size(), COLS = dungeon[0].size();
    // solution traveres backwards from the goal 'room', computing at each position 
    // the minimum required health (MRH) to reach the end from current room.
    for(int row{ROWS-1}; row>-1; --row)
    {
        for(int col{COLS-1}; col>-1; --col)
        {
            if(row == ROWS-1 && col == COLS-1){}  // already at the goal room
            // at each position, best option is maximum value of right and below (damage values are <0) 
            else if(row == ROWS-1){ dungeon[row][col] += dungeon[row][col+1]; }
            else if(col == COLS-1){ dungeon[row][col] += dungeon[row+1][col]; }
            else{ dungeon[row][col] += std::max(dungeon[row][col+1], dungeon[row+1][col]); }
            
            // heals can cause positive value rooms, however these heals cannot be reached without 
            // first surviving current room; they should be considered as targets with zero damage, rather than
            // propagating their positive value backwards to affect rooms earlier along the path  
            if(dungeon[row][col] > 0){ dungeon[row][col] = 0; }
        }
    }
    return std::abs(dungeon[0][0]) + 1;  // MRH is total unavoidable damage ahead, +1 to survive the damage 
}