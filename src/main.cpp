// https://leetcode.com/problems/dungeon-game/

#include<iostream>
#include"../inc/solution.hpp"

int main()
{
	//std::vector<std::vector<int>> dungeon{{-2,-3,3},{-5,-10,1},{10,30,-5}};  // 7
	//std::vector<std::vector<int>> dungeon{{-2,-3,3},{-5,0,1},{10,30,-5}};  // 6
	std::vector<std::vector<int>> dungeon{{-2,-3,3},{-5,-10,1},{10,30,-40},{-100,-100,0}};  // 8
	std::cout << Solution().calculateMinimumHP(dungeon);
	return 0;
}

