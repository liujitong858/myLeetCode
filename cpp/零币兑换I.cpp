#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	//��򵥵Ķ�ά����
	//���˵�һ��Ԫ�ض�Ҫ��ʼ��Ϊ�����
	int coinChange(vector<int>& coins, int amount) {
		int type_count = (int)coins.size();
		//ʹ��ǰi��Ӳ����ϳ�amount������С����
		vector<vector<int>> dp(type_count + 1, vector<int>(amount + 1, INT_MAX));
		dp[0][0] = 0;
		for (int i = 1; i <= (int)coins.size(); ++i) {
			for (int j = 0; j <= amount; ++j) {
				dp[i][j] = dp[i - 1][j];
				if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] != INT_MAX)
				{
					dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
				}
			}
		}
		//������Ҫע�⣬����������������Ļ�������
		if (dp[type_count][amount] == INT_MAX) return -1;
		else  return dp[type_count][amount];

	}
	//��Ϊ֮��ǰһ��״̬�й�
	//����ʹ�ù�������
	int coinChange1(vector<int>& coins, int amount) {
		int type_count = (int)coins.size();
		//ʹ��ǰi��Ӳ����ϳ�amount������С����
		vector<int> dp( amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= (int)coins.size(); ++i) {
			for (int j = 0; j <= amount; ++j) {
				if (j >= coins[i - 1] && dp[j - coins[i - 1]] != INT_MAX)
				{
					dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
				}
			}
		}
		//������Ҫע�⣬����������������Ļ�������
		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}
	//Ҳ���Խ�INT_MAX��λ�û���amount+1
	//Ϊʲô�� dp ���������Ԫ�ض���ʼ��Ϊ amount + 1��
	//	vector<int> dp(amount + 1, amount + 1);
	//�������� dp[amount] ��󲻿��ܳ��� amount����С��ֵΪ 1 Ԫ�������� amount + 1 ����һ������������ˡ�
	//��Ϊ֮��ǰһ��״̬�й�
	//����ʹ�ù�������
	//j��ȡֵ�����Լ����Ż�
	int coinChange2(vector<int>& coins, int amount) {
		int type_count = (int)coins.size();
		//ʹ��ǰi��Ӳ����ϳ�amount������С����
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 1; i <= (int)coins.size(); ++i) {
			for (int j = coins[i - 1]; j <= amount; ++j) {
				if (dp[j - coins[i - 1]] != INT_MAX) {
					dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
				}
			}
		}
		//������Ҫע�⣬����������������Ļ�������
		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}
	//̰�� + dfs
	int coinChange3(vector<int>& coins, int amount) {
		int ans = INT_MAX;
		//����β����������ʵ�ִӴ�С������
		sort(coins.rbegin(), coins.rend());
		coinChange_helper(coins, amount, 0, 0, ans);
		return ans == INT_MAX ? -1 : ans;
	}
	void coinChange_helper(vector<int>& coins, int amount, int c_index, int count, int& ans)
	{
		//�ݹ���ֹ����
		if (amount == 0) {
			ans = min(ans, count);
			return;
		}
		if (c_index == (int)coins.size()) return;
		int _count = amount / coins[c_index];
		//�������i+count<ans�ǹؼ���
		//�������������м�ֽ�Ļ����ͳ�ʱ
		for (int i = _count; i >= 0 && i + count < ans; --i)
		{
			coinChange_helper(coins, amount - coins[c_index] * i, c_index + 1, count + i, ans);
		}
	}
};