#include<vector>
using namespace std;
namespace leetcode62 {
	class Solution {
	public:
		//超出时间限制
		int uniquePaths(int m, int n) {
			if (m < 1 || m>100 || n < 1 || n>100) return 0;
			int sum = 0;
			uniquePaths_helper(m, n, 1, 1, sum);
			return sum;
		}
		void uniquePaths_helper(int m, int n, int row, int col, int& sum) {
			if (row == m && col == n) {
				sum++;
				return;
			}
			if (row < m) uniquePaths_helper(m, n, row + 1, col, sum);
			if (col < n) uniquePaths_helper(m, n, row, col + 1, sum);
		}
		//动态规划 双百
		int uniquePaths1(int m, int n) {
			if (m < 1 || m>100 || n < 1 || n>100) return 0;
			int sum = 0;
			vector<vector<int>>dp(m, vector<int>(n));
			dp[0][0] = 1;
			for (int i = 1; i < n; ++i) {
				dp[0][i] = 1;
			}
			for (int i = 1; i < m; ++i) {
				dp[i][0] = 1;
			}
			for (int i = 1; i < m; ++i) {
				for (int j = 1; j < n; ++j) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
			return dp[m - 1][n - 1];
		}
	};
}