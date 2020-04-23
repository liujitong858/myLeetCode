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
	//�ο��Ĵ�Ⱦ�㷨��ʵ�����ǹ����������
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

	//�ο��ٷ������Ż��ⷨ
	//ֱ����ԭ��������������ǣ�
	//�������Ե�ʱ����Ҫ��һ�����Թ��Ƿ���Ըı�ԭ��������
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

	//�����������
	void dfs(vector<vector<char>>& grid, int r, int c) {
			int nr = grid.size();//��ֱ����
			int nc = grid[0].size();//ˮƽ����
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