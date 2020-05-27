#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode64 {
	class Solution {
	public:
		//超时的做法
		int minPathSum(vector<vector<int>>& grid) {
			//路径问题
			int m = grid.size();//行数
			int n = grid[0].size();//列数
			vector<int> res;
			int sum = grid[0][0];
			minPathSum_helper(res, grid, m, n, 0, 0, sum);
			return *min_element(res.begin(), res.end());
		}

		void minPathSum_helper(vector<int>& res, vector<vector<int>>& grid, int m, int n, int row, int col, int sum) {
			if (row == m - 1 && col == n - 1) {
				res.push_back(sum);
				return;
			}
			if (row < m - 1) minPathSum_helper(res, grid, m, n, row + 1, col, sum + grid[row + 1][col]);
			if (col < n - 1) minPathSum_helper(res, grid, m, n, row, col + 1, sum + grid[row][col + 1]);
		}

		//正确的解法是动态规划
		int minPathSum1(vector<vector<int>>& grid) {
			int m = grid.size();//行数
			int n = grid[0].size();//列数
			vector<vector<int>> dp(m, vector<int>(n));
			dp[0][0] = grid[0][0];
			//首先将第一行第一列的最小路径算出，因为是唯一的
			for (int i = 1; i < n; ++i) {//将第一行的min路径算出
				dp[0][i] = dp[0][i - 1] + grid[0][i];
			}
			for (int j = 1; j < m; ++j) {//将第一列的min路径算出
				dp[j][0] = dp[j - 1][0] + grid[j][0];
			}
			for (int i = 1; i < m; ++i) {//将到达每个位置的min路径算出
				for (int j = 1; j < n; ++j) {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
				}
			}
			return dp[m - 1][n - 1];
		}
	};
}