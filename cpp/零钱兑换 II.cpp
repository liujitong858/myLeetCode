#include<vector>
using namespace std;
namespace leetcode518 {
	class Solution {
	public:
		//��򵥵Ķ�̬�滮
		//��ά����
		//����ѭ��
		
		int change(int amount, vector<int>& coins) {
			int type_count = (int)coins.size();
			vector<vector<int>> dp(type_count + 1, vector<int>(amount + 1));
			dp[0][0] = 1; //����dp[1][1]��ʱ��
			for (int i = 1; i <= type_count; ++i)
			{
				for (int j = 0; j <= amount; ++j) {//��С���󣻶��ر���    
					for (int k = 0; k*coins[i - 1] <= j; ++k)
					{
						//coins[i-1]���ǵ�i��Ӳ�ҵ���ֵ
						dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
					}
				}
			}
			return dp[type_count][amount];
		}
		//dp[i][j] =dp[i-1][j]+  dp[i-1][j - 2*coins[i-1]]+ dp[i-1][j - 3*coins[i-1]]+...; 
		//dp[i][j - coins[i-1]]=dp[i-1][j - coins[i-1]] +dp[i-1][j - 2*coins[i-1]]+ dp[i-1][j - 3*coins[i-1]]+...; 
		//dp[i][j]=dp[i-1][j]+dp[i][j - coins[i-1]]
		int change1(int amount, vector<int>& coins) {
			int type_count = (int)coins.size();
			vector<vector<int>> dp(type_count + 1, vector<int>(amount + 1));
			dp[0][0] = 1; //����dp[1][1]��ʱ��
						 //amount=0˵����ϳ�0Ԫ��������պþ��ǲ����κ���Ǯ�� Ҳ��һ�ַ���
			for (int i = 1; i <= type_count; ++i)
			{
				for (int j = 0; j <= amount; ++j) {//��С���󣻶��ر��� 
					dp[i][j] = dp[i - 1][j];
					if (coins[i - 1] <= j)
						dp[i][j] += dp[i][j - coins[i - 1]];
				}
			}
			return dp[type_count][amount];
		}
		//�Ż�Ϊ1ά����
		//��Ϊ���� dp ֻ������i�� i-1�� ��ת̬�����Կ�����һά�����������Ż���
		//��ȫ��������j�Ǵ�С���������ԭ���ǣ�ÿ��ѡ�����ѡ���
		//�� dp[j] ������dp[j -coins[i]] Ҫ�������������dp[j -coins[i]]���Ѿ�����ѡ�˵�ǰiӲ�ҵ����
		int change2(int amount, vector<int>& coins) {
			int type_count = (int)coins.size();
			vector<int> dp(amount + 1, 0);//�����Ϊamount��ʱ�����ϸ���
			dp[0] = 1; //����dp[1][1]��ʱ��
						 //amount=0˵����ϳ�0Ԫ��������պþ��ǲ����κ���Ǯ�� Ҳ��һ�ַ���
			for (int i = 1; i <= type_count; ++i)
			{
				for (int j = coins[i - 1]; j <= amount; ++j) {//��С���󣻶��ر��� 
					dp[j] += dp[j - coins[i - 1]];
				}
			}
			return dp[amount];
		}
	};
}