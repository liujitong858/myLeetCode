#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode122{
	class Solution {
	public:
		//状态转移
		int maxProfit(vector<int>& prices) {
			if (prices.size() <= 1) return 0;
			int dp_i_0 = 0; //第一维表示第i天能获得的最大利润
			int dp_i_1 = INT_MIN;//第二维表示第i天是持有股票还是持有现金
			for (int i = 0; i < (int)prices.size(); ++i) {
				int temp = dp_i_0;//昨天没有持有股票的情况
				dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
				dp_i_1 = max(dp_i_1, temp - prices[i]);
			}
			return dp_i_0;
		}
		//贪心算法
		//从第 i 天（这里 i >= 0）开始，与第 i+1 的股价进行比较，如果股价有上升（严格上升），
		//就将升高的股价（ prices[i+1] - prices[i]）记入总利润，按照这种算法，得到的结果就是符合题意的最大利润。
		int maxProfit1(vector<int>& prices) {
			if (prices.size() <= 1) return 0;
			int diff = 0;
			int profit = 0;
			for (int i = 0; i < (int)prices.size()-1; ++i)
			{
				diff = prices[i + 1] - prices[i];
				if (diff > 0) profit += diff;
			}
			return profit;
		}

	};
}
