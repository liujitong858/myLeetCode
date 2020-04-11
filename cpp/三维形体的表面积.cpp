#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode892 {
	class Solution {
	public:
		int surfaceArea(vector<vector<int>>& grid) {
			if (grid.empty())return 0;
			int res = 0;
			int blocks = 0;//方块个数
			int cover = 0;//遮住的面数
			for (int i = 0; i < (int)grid.size(); ++i)
			{
				for (int j = 0; j < (int)grid[i].size(); ++j)
				{
					blocks += grid[i][j];
					//这个是统计当前格子中因为堆叠而盖住了几个面
					cover += grid[i][j] > 1 ? grid[i][j] - 1 : 0;
					if (i > 0) {
						//看看上一行同一列盖住了多少个面
						cover += min(grid[i - 1][j], grid[i][j]);
					}
					if (j > 0) {
						//看看同一行前一列盖住了几个面
						cover += min(grid[i][j - 1], grid[i][j]);
					}
				}
			}
			res = blocks * 6 - cover * 2;
			return res;
		}
	};
}