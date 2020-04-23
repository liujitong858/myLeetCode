#include<vector>
#include<stack>
using namespace std;
namespace leetcode200 {
	class Point {
	public:
		int x;
		int y;
		Point(int i, int j) :x(i), y(j) {};
	};
	//参考的传染算法，实际上是广度优先搜索
	int numIslands(vector<vector<char>>& grid) {
		
		vector<vector<int>> visited(grid.size());
		for (size_t i = 0; i < grid.size(); ++i)
		{
			for (size_t j = 0; j < grid[0].size(); ++j)
			{
				visited[i].push_back(0);
			}
		}
		int count = 0;
		stack<Point> pointStack;
		Point seed(0, 0), neighbor(0, 0);
		for (size_t i = 0; i < grid.size(); ++i)
		{
			for (size_t j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == '1'&&visited[i][j] == 0)
				{
					visited[i][j] = 1;
					seed = Point(i, j);
					pointStack.push(seed);
					++count;
					while (!pointStack.empty())
					{
						neighbor = Point(seed.x + 1, seed.y);
						if ((seed.x != (grid.size() - 1)) && grid[seed.x + 1][seed.y] == '1'&&visited[seed.x + 1][seed.y] == 0)
						{
							visited[seed.x + 1][seed.y] = 1;
							pointStack.push(neighbor);
						}
						neighbor = Point(seed.x - 1, seed.y);
						if ((seed.x != 0) && grid[seed.x - 1][seed.y] == '1'&&visited[seed.x - 1][seed.y] == 0)
						{
							visited[seed.x - 1][seed.y] = 1;
							pointStack.push(neighbor);
						}
						neighbor = Point(seed.x, seed.y + 1);
						if ((seed.y != (grid[0].size() - 1)) && grid[seed.x][seed.y + 1] == '1'&&visited[seed.x][seed.y + 1] == 0)
						{
							visited[seed.x][seed.y + 1] = 1;
							pointStack.push(neighbor);
						}
						neighbor = Point(seed.x, seed.y - 1);
						if ((seed.y != 0) && grid[seed.x][seed.y - 1] == '1'&&visited[seed.x][seed.y - 1] == 0)
						{
							visited[seed.x][seed.y - 1] = 1;
							pointStack.push(neighbor);
						}
						seed = pointStack.top();
						pointStack.pop();
					}
				}
			}
		}
		return count;
	}

	//参考官方解答的优化解法
	//直接在原来的数组中做标记；
	//但是面试的时候需要问一下面试官是否可以改变原来的数组
	int numIslands1(vector<vector<char>>& grid) {
		int count = 0;
		stack<Point> pointStack;
		Point seed(0, 0), neighbor(0, 0);
		for (size_t i = 0; i < grid.size(); ++i)
		{
			for (size_t j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == '1')
				{
					seed = Point(i, j);
					pointStack.push(seed);
					++count;
					while (!pointStack.empty()) {
						neighbor = Point(seed.x + 1, seed.y);
						if ((seed.x != (grid.size() - 1)) && grid[seed.x + 1][seed.y] == '1') {
							grid[seed.x + 1][seed.y] = '0';
							pointStack.push(neighbor);
						}
						neighbor = Point(seed.x - 1, seed.y);
						if ((seed.x != 0) && grid[seed.x - 1][seed.y] == '1') {
							grid[seed.x - 1][seed.y] = '0';
							pointStack.push(neighbor);
						}
						neighbor = Point(seed.x, seed.y + 1);
						if ((seed.y != (grid[0].size() - 1)) && grid[seed.x][seed.y + 1] == '1') {
							grid[seed.x][seed.y + 1] = '0';
							pointStack.push(neighbor);
						}
						neighbor = Point(seed.x, seed.y - 1);
						if ((seed.y != 0) && grid[seed.x][seed.y - 1] == '1') {
							grid[seed.x][seed.y - 1] = '0';
							pointStack.push(neighbor);
						}
						seed = pointStack.top();
						pointStack.pop();
					}
				}
			}
		}
		return count;
	}

	//深度优先搜索
	void dfs(vector<vector<char>>& grid, int r, int c) {
			int nr = grid.size();//垂直长度
			int nc = grid[0].size();//水平长度
			grid[r][c] = '0';
			if (r  > 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
			if (r  < nr-1 && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
			if (c  > 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
			if (c  < nc-1 && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
		}
	int numIslands2(vector<vector<char>>& grid) {
		int nr = grid.size();
		if (!nr) return 0;
		int nc = grid[0].size();

		int num_islands = 0;
		for (int r = 0; r < nr; ++r) {
			for (int c = 0; c < nc; ++c) {
				if (grid[r][c] == '1') {
					++num_islands;
					dfs(grid, r, c);
				}
			}
		}

		return num_islands;
	}

}