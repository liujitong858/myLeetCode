#include<vector>
using namespace std;
namespace leetcode96 {
	class Solution {
	public:
		////��G(n)��ʾn���ڵ�����������ĸ�����f(i)��ʾ��i��Ϊ���ڵ�Ķ����������ĸ���
        //����У�G(n) = f(1)+f(2)+f(3)+...+f(n)
        //��iΪ���ڵ����������i-1���ڵ㣬�����������G(i-1)�ֶ���������
        //��������n-i���ڵ㣬�����������G(n-i)�ֶ���������
        //�Ӷ��õ���f(i) = G(i-1)*G(n-i)
        //���õ�G(n) = G(0)*G(n-1)+G(1)G(n-2)+G(2)G(n-3)+...+G(n-1)G(0)
		//��������
		//�ݹ�+��̬�滮
		int numTrees_Helper(int n, vector<int> &dp) {
			if (n <= 1) return dp[n];
			int res = 0;
			for (int i = 0; i < n; ++i)
			{
				res += (dp[i] == 0 ? numTrees_Helper(i, dp) : dp[i])
					*(dp[n - i - 1] == 0 ? numTrees_Helper(n - i - 1, dp) : dp[n - i - 1]);
			}
			dp[n] = res;
			return res;
		}
		int numTrees(int n) {
			vector<int> dp(n + 1, 0);
			dp[0] = 1, dp[1] = 1;
			return numTrees_Helper(n, dp);
		}

		//����2
		//��׼��̬�滮
		int numTrees1(int n) {
			vector<int> dp(n + 1, 0);
			dp[0] = 1;
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j < i; ++j) {
					dp[i] += dp[j] * dp[i - 1 - j];
				}
			}
			return dp[n];
		}
	};
}