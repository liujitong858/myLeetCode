#include<vector>
#include<algorithm>
using namespace std;
namespace offer14 {
	class Solution {
	public:
		int cuttingRope(int n) {
			if (n <= 1) return 0;
			if (n == 2) return 1;
			if (n == 3) return 2;
			if (n == 4) return 4;
			vector<int> dp(n + 1, 0);
			dp[1] = 1;
			dp[2] = 2;
			dp[3] = 3;
			/*
			����3����n>=4���������n<=3��ͬ��4���Էֺܶ�Σ�����ֳ�1��3��
			�����3���Բ���Ҫ�ٷ��ˣ���Ϊ3�ֶ�����2�����־���3����¼���ġ�
			 */
			for (int i = 4; i <= n; ++i) {
				for (int j = 1; j <= i / 2; ++j) {
					dp[i] = max(dp[i], dp[i - j] * dp[j]);
				}
			}
			return dp[n];
		}
	};
}