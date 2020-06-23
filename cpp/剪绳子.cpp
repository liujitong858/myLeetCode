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
			下面3行是n>=4的情况，跟n<=3不同，4可以分很多段，比如分成1、3，
			这里的3可以不需要再分了，因为3分段最大才2，不分就是3。记录最大的。
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