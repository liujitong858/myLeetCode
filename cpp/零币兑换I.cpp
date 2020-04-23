#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	//最简单的二维数组
	//除了第一个元素都要初始化为无穷大
	int coinChange(vector<int>& coins, int amount) {
		int type_count = (int)coins.size();
		//使用前i种硬币组合成amount金额的最小个数
		vector<vector<int>> dp(type_count + 1, vector<int>(amount + 1, INT_MAX));
		dp[0][0] = 0;
		for (int i = 1; i <= (int)coins.size(); ++i) {
			for (int j = 0; j <= amount; ++j) {
				dp[i][j] = dp[i - 1][j];
				if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] != INT_MAX)
				{
					dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
				}
			}
		}
		//这里需要注意，如果最后输出是无穷大的话，代表
		if (dp[type_count][amount] == INT_MAX) return -1;
		else  return dp[type_count][amount];

	}
	//因为之和前一个状态有关
	//所以使用滚动数组
	int coinChange1(vector<int>& coins, int amount) {
		int type_count = (int)coins.size();
		//使用前i种硬币组合成amount金额的最小个数
		vector<int> dp( amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= (int)coins.size(); ++i) {
			for (int j = 0; j <= amount; ++j) {
				if (j >= coins[i - 1] && dp[j - coins[i - 1]] != INT_MAX)
				{
					dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
				}
			}
		}
		//这里需要注意，如果最后输出是无穷大的话，代表
		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}
	//也可以将INT_MAX的位置换成amount+1
	//为什么将 dp 数组的所有元素都初始化为 amount + 1：
	//	vector<int> dp(amount + 1, amount + 1);
	//这是由于 dp[amount] 最大不可能超过 amount（最小面值为 1 元），所以 amount + 1 就是一个无意义的数了。
	//因为之和前一个状态有关
	//所以使用滚动数组
	//j的取值还可以继续优化
	int coinChange2(vector<int>& coins, int amount) {
		int type_count = (int)coins.size();
		//使用前i种硬币组合成amount金额的最小个数
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= (int)coins.size(); ++i) {
			for (int j = coins[i - 1]; j <= amount; ++j) {
				if (dp[j - coins[i - 1]] != INT_MAX) {
					dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
				}
			}
		}
		//这里需要注意，如果最后输出是无穷大的话，代表
		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}
	//贪心 + dfs
	int coinChange3(vector<int>& coins, int amount) {
		int ans = INT_MAX;
		//利用尾迭代器可以实现从大到小的排序
		sort(coins.rbegin(), coins.rend());
		coinChange_helper(coins, amount, 0, 0, ans);
		return ans == INT_MAX ? -1 : ans;
	}
	void coinChange_helper(vector<int>& coins, int amount, int c_index, int count, int& ans)
	{
		//递归终止条件
		if (amount == 0) {
			ans = min(ans, count);
			return;
		}
		if (c_index == (int)coins.size()) return;
		int _count = amount / coins[c_index];
		//这里加上i+count<ans是关键，
		//如果不在这里进行剪纸的话，就超时
		for (int i = _count; i >= 0 && i + count < ans; --i)
		{
			coinChange_helper(coins, amount - coins[c_index] * i, c_index + 1, count + i, ans);
		}
	}
};