#include<vector>
using namespace std;
namespace leetcode96 {
	class Solution {
	public:
		////令G(n)表示n个节点二叉排序树的个数，f(i)表示以i作为根节点的二叉排序树的个数
        //因此有：G(n) = f(1)+f(2)+f(3)+...+f(n)
        //以i为根节点的左子树有i-1个节点，因此右子树有G(i-1)种二叉排序树
        //右子树有n-i个节点，因此右子树有G(n-i)种二叉排序树
        //从而得到：f(i) = G(i-1)*G(n-i)
        //最后得到G(n) = G(0)*G(n-1)+G(1)G(n-2)+G(2)G(n-3)+...+G(n-1)G(0)
		//卡特兰数
		//递归+动态规划
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

		//方法2
		//标准动态规划
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