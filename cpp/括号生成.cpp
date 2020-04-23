#include<vector>
#include<queue>
using namespace std;
namespace leetcode22 {
	class Solution {
	public:
		vector<string> res;
		//回溯算法（深度优先遍历） 构造树+剪枝
		vector<string> generateParenthesis(int n) {
			if (n == 0) return  vector<string>();
			string str = "";
			generateParenthesis_helper(n, n, str);
			return res;
		}
		void generateParenthesis_helper(int left_left, int left_right, string str) {
			if (left_left == 0 && left_right == 0) {
				res.push_back(str);
				return;
			}
			if (left_left > 0) {//只要左括号还有剩余就可以继续分出左子树
				generateParenthesis_helper(left_left - 1, left_right, str + '(');
			}
			if (left_right > left_left) {//只要右括号剩余量大于左括号剩余量就可以分除右子树
				generateParenthesis_helper(left_left, left_right - 1, str + ')');
			}
		}
		//广度优先搜索
		//空间节省，时间增加
		vector<string> generateParenthesis1(int n) {
			if (n == 0) return  vector<string>();
			vector<string> res;
			queue<pair<string, pair<int, int>>> que;
			que.push({ "",{n,n} });//列表初始化
			while (!que.empty()) {
				auto top = que.front();
				que.pop();
				string str = top.first;
				int left_left = top.second.first;
				int left_right = top.second.second;
				if (left_right == 0 && left_left == 0) {
					res.push_back(str);
				}
				if (left_left > 0) {
					que.push({ str + '(',{left_left - 1,left_right} });
				}
				if (left_right > left_left) {
					que.push({ str + ')',{left_left,left_right - 1} });
				}
			}
			return res;
		}
		//动态规划
		vector<string> generateParenthesis2(int n) {
			if (n == 0) return {};
			if (n == 1) return { "()" };
			vector<vector<string>> dp(n + 1);
			dp[0] = { "" };
			dp[1] = { "()" };
			for (int i = 2; i <= n; i++) {
				for (int j = 0; j < i; j++) {
					for (string p : dp[j])//p个括号在内 q个括号在外，然后排列组合
						for (string q : dp[i - j - 1]) {//p+q=i-1
							string str = "(" + p + ")" + q;
							dp[i].push_back(str);
						}
				}
			}
			return dp[n];
		}
	};
}