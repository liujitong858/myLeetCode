#include<vector>
using namespace std;
namespace leetcode70 {
	class Solution {
	public:
		//쳲�������¥��
		//ת�Ʒ���:dp[i] = dp[i-1] + dp[i-2]
		//���������dp[i]ֻ��ǰ�����йأ�����ֻ��Ҫ�����������洢�����Ż�������
		int climbStairs(int n) {
			if (n == 1)return 1;
			if (n == 2)return 2;
			int oneStep = 1;
			int twoStep = 2;
			int nStep = 0;
			for (int i = 3; i <= n; ++i)
			{
				nStep = oneStep + twoStep;
				oneStep = twoStep;
				twoStep = nStep;
			}
			return nStep;
		}
		int climbStairs1(int n) {
			if (n == 1)return 1;
			if (n == 2)return 2;
			vector<int> dp;
			dp.push_back(1);
			dp.push_back(2);
			int nStep = 0;
			for (int i = 2; i < n; ++i)
			{
				nStep = dp[i-2] + dp[i - 1];
				dp.push_back(nStep);
			}
			return dp[n-1];
		}
	};
}