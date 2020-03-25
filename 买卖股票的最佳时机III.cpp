#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode123 {
	class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			if (prices.size() <= 1) return 0;
		    int days = prices.size();
			//int dp[days][3][2];//���ر�����ͨ�����ˣ���������ֻ�ܲ��ö�̬����ͳ�ʼ��
			/*memset(dp, 0, sizeof(dp));*/
			int *** dp;
		   	for (int i = 0; i < days; i++) {
				dp[i] = new int*[3];
		   		for (int j = 0; j < 3; j++) {
					dp[i][j] = new int[2];
		   		}
		   	}
			for (int i = 0; i < days; i++) {
				for (int j = 0; j < 3; j++) {
					memset(dp[i][j], 0, sizeof(int) * 2);
				}
			}
			//�����n*k*2�����
			//��ѭ�����˾ʹ���
			//�ǵó�ʼ�� base case
			for (int i = 0; i < days; ++i)
			{
				for (int k = 2; k > 0; --k)
				{
					if (i == 0)
					{
						dp[i][k][0] = 0;
						dp[i][k][1] = -prices[0];
						continue;
					}
					dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
					dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
				}
			}
			return dp[days - 1][2][0];
			/*for (i = 0; i < days; i++) {
				for (j = 0; j < 3; j++) {
					delete[] dp[i][j];
				}
				delete[] dp[i];
			}
			delete[] dp;
			dp=nullptr */
		}
	};
}