#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode122{
	class Solution {
	public:
		//״̬ת��
		int maxProfit(vector<int>& prices) {
			if (prices.size() <= 1) return 0;
			int dp_i_0 = 0; //��һά��ʾ��i���ܻ�õ��������
			int dp_i_1 = INT_MIN;//�ڶ�ά��ʾ��i���ǳ��й�Ʊ���ǳ����ֽ�
			for (int i = 0; i < (int)prices.size(); ++i) {
				int temp = dp_i_0;//����û�г��й�Ʊ�����
				dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
				dp_i_1 = max(dp_i_1, temp - prices[i]);
			}
			return dp_i_0;
		}
		//̰���㷨
		//�ӵ� i �죨���� i >= 0����ʼ����� i+1 �Ĺɼ۽��бȽϣ�����ɼ����������ϸ���������
		//�ͽ����ߵĹɼۣ� prices[i+1] - prices[i]�����������󣬰��������㷨���õ��Ľ�����Ƿ���������������
		int maxProfit1(vector<int>& prices) {
			if (prices.size() <= 1) return 0;
			int diff = 0;
			int profit = 0;
			for (int i = 0; i < (int)prices.size()-1; ++i)
			{
				diff = prices[i + 1] - prices[i];
				if (diff > 0) profit += diff;
			}
			return profit;
		}

	};
}
