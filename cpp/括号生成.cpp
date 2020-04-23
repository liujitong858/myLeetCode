#include<vector>
#include<queue>
using namespace std;
namespace leetcode22 {
	class Solution {
	public:
		vector<string> res;
		//�����㷨��������ȱ����� ������+��֦
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
			if (left_left > 0) {//ֻҪ�����Ż���ʣ��Ϳ��Լ����ֳ�������
				generateParenthesis_helper(left_left - 1, left_right, str + '(');
			}
			if (left_right > left_left) {//ֻҪ������ʣ��������������ʣ�����Ϳ��Էֳ�������
				generateParenthesis_helper(left_left, left_right - 1, str + ')');
			}
		}
		//�����������
		//�ռ��ʡ��ʱ������
		vector<string> generateParenthesis1(int n) {
			if (n == 0) return  vector<string>();
			vector<string> res;
			queue<pair<string, pair<int, int>>> que;
			que.push({ "",{n,n} });//�б��ʼ��
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
		//��̬�滮
		vector<string> generateParenthesis2(int n) {
			if (n == 0) return {};
			if (n == 1) return { "()" };
			vector<vector<string>> dp(n + 1);
			dp[0] = { "" };
			dp[1] = { "()" };
			for (int i = 2; i <= n; i++) {
				for (int j = 0; j < i; j++) {
					for (string p : dp[j])//p���������� q���������⣬Ȼ���������
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