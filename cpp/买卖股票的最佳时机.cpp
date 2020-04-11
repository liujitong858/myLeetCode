#include<vector>
#include<algorithm>
using namespace std;

namespace leetcode121 {
	class Solution {
	public:
		//动态规划 遍历一遍即可 时间复杂度O(n).
		//前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
		//题目中，我们只要用一个变量记录一个历史最低价格 minprice，我们就可以假设自己的股票是在那天买的
		//。那么我们在第 i 天卖出股票能得到的利润就是 prices[i] - minprice。
		//因此，我们只需要遍历价格数组一遍，记录历史最低点，然后在每一天考虑这么一个问题：
		//如果我是在历史最低点买进的，那么我今天卖出能赚多少钱？当考虑完所有天数之时，我们就得到了最好的答案。
		int maxProfit(vector<int>& prices) {
			if (prices.size() <= 1) return 0;
			int MaxProfit = 0;//前i-1天的最大收益
			int minPrice = prices[0];//前i-1天得最小价格
			for (int Day_sell = 1; Day_sell < (int)prices.size(); ++Day_sell)
			{
				MaxProfit = max(MaxProfit, prices[Day_sell] - minPrice);
				minPrice = min(minPrice, prices[Day_sell]);
			}
			return MaxProfit;
		}
		//暴力法，超出时间限制 时间复杂度：O(n^2)
		int maxProfit1(vector<int>& prices) {
			if (prices.size() <= 1) return 0;
			int n = (int)prices.size();
			int MaxProfit = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					MaxProfit = max(MaxProfit, prices[j] - prices[i]);
				}
			}
			return MaxProfit;
		}
		//使用状态转移方程
		int maxProfit2(vector<int>& prices) {
			if (prices.size() <= 1) return 0;
			int dp_i_0 = 0;//Max_profit
			int dp_i_1 = INT_MIN;//-minprices
			for (int i = 0; i < (int)prices.size(); ++i)
			{
				dp_i_0 = max(dp_i_0, prices[i]+dp_i_1);
				dp_i_1 = max(dp_i_1, -prices[i]);
			}
			return dp_i_0;
		}
	};
}