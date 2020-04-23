#include<vector>
using namespace std;
namespace leetcode518 {
	class Solution {
	public:
		//最简单的动态规划
		//二维数组
		//三层循环
		
		int change(int amount, vector<int>& coins) {
			int type_count = (int)coins.size();
			vector<vector<int>> dp(type_count + 1, vector<int>(amount + 1));
			dp[0][0] = 1; //计算dp[1][1]的时候
			for (int i = 1; i <= type_count; ++i)
			{
				for (int j = 0; j <= amount; ++j) {//从小到大；多重背包    
					for (int k = 0; k*coins[i - 1] <= j; ++k)
					{
						//coins[i-1]就是第i种硬币的面值
						dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
					}
				}
			}
			return dp[type_count][amount];
		}
		//dp[i][j] =dp[i-1][j]+  dp[i-1][j - 2*coins[i-1]]+ dp[i-1][j - 3*coins[i-1]]+...; 
		//dp[i][j - coins[i-1]]=dp[i-1][j - coins[i-1]] +dp[i-1][j - 2*coins[i-1]]+ dp[i-1][j - 3*coins[i-1]]+...; 
		//dp[i][j]=dp[i-1][j]+dp[i][j - coins[i-1]]
		int change1(int amount, vector<int>& coins) {
			int type_count = (int)coins.size();
			vector<vector<int>> dp(type_count + 1, vector<int>(amount + 1));
			dp[0][0] = 1; //计算dp[1][1]的时候
						 //amount=0说明组合成0元的情况，刚好就是不用任何零钱， 也算一种方法
			for (int i = 1; i <= type_count; ++i)
			{
				for (int j = 0; j <= amount; ++j) {//从小到大；多重背包 
					dp[i][j] = dp[i - 1][j];
					if (coins[i - 1] <= j)
						dp[i][j] += dp[i][j - coins[i - 1]];
				}
			}
			return dp[type_count][amount];
		}
		//优化为1维数组
		//因为本体 dp 只依赖于i和 i-1的 的转态，所以可以用一维滚动数组来优化。
		//完全背包问题j是从小到达遍历的原因是：每个选项可以选多次
		//即 dp[j] 依赖的dp[j -coins[i]] 要先算出来，而在dp[j -coins[i]]种已经包含选了当前i硬币的情况
		int change2(int amount, vector<int>& coins) {
			int type_count = (int)coins.size();
			vector<int> dp(amount + 1, 0);//当金额为amount的时候的组合个数
			dp[0] = 1; //计算dp[1][1]的时候
						 //amount=0说明组合成0元的情况，刚好就是不用任何零钱， 也算一种方法
			for (int i = 1; i <= type_count; ++i)
			{
				for (int j = coins[i - 1]; j <= amount; ++j) {//从小到大；多重背包 
					dp[j] += dp[j - coins[i - 1]];
				}
			}
			return dp[amount];
		}
	};
}