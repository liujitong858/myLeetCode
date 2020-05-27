#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode64 {
	class Solution {
	public:
		//��ʱ������
		int minPathSum(vector<vector<int>>& grid) {
			//·������
			int m = grid.size();//����
			int n = grid[0].size();//����
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

		//��ȷ�Ľⷨ�Ƕ�̬�滮
		int minPathSum1(vector<vector<int>>& grid) {
			int m = grid.size();//����
			int n = grid[0].size();//����
			vector<vector<int>> dp(m, vector<int>(n));
			dp[0][0] = grid[0][0];
			//���Ƚ���һ�е�һ�е���С·���������Ϊ��Ψһ��
			for (int i = 1; i < n; ++i) {//����һ�е�min·�����
				dp[0][i] = dp[0][i - 1] + grid[0][i];
			}
			for (int j = 1; j < m; ++j) {//����һ�е�min·�����
				dp[j][0] = dp[j - 1][0] + grid[j][0];
			}
			for (int i = 1; i < m; ++i) {//������ÿ��λ�õ�min·�����
				for (int j = 1; j < n; ++j) {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
				}
			}
			return dp[m - 1][n - 1];
		}
	};
}