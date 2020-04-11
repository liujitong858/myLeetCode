#include<vector>
#include<algorithm>
using namespace std;

namespace leetcode121 {
	class Solution {
	public:
		//��̬�滮 ����һ�鼴�� ʱ�临�Ӷ�O(n).
		//ǰi���������� = max{ǰi-1���������棬��i��ļ۸�-ǰi-1���е���С�۸�}
		//��Ŀ�У�����ֻҪ��һ��������¼һ����ʷ��ͼ۸� minprice�����ǾͿ��Լ����Լ��Ĺ�Ʊ�����������
		//����ô�����ڵ� i ��������Ʊ�ܵõ���������� prices[i] - minprice��
		//��ˣ�����ֻ��Ҫ�����۸�����һ�飬��¼��ʷ��͵㣬Ȼ����ÿһ�쿼����ôһ�����⣺
		//�����������ʷ��͵�����ģ���ô�ҽ���������׬����Ǯ������������������֮ʱ�����Ǿ͵õ�����õĴ𰸡�
		int maxProfit(vector<int>& prices) {
			if (prices.size() <= 1) return 0;
			int MaxProfit = 0;//ǰi-1����������
			int minPrice = prices[0];//ǰi-1�����С�۸�
			for (int Day_sell = 1; Day_sell < (int)prices.size(); ++Day_sell)
			{
				MaxProfit = max(MaxProfit, prices[Day_sell] - minPrice);
				minPrice = min(minPrice, prices[Day_sell]);
			}
			return MaxProfit;
		}
		//������������ʱ������ ʱ�临�Ӷȣ�O(n^2)
		int maxProfit1(vector<int>& prices) {
			if (prices.size() <= 1) return 0;
			int n = (int)prices.size();
			int MaxProfit = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					MaxProfit = max(MaxProfit, prices[j] - prices[i]);
				}
			}
			return MaxProfit;
		}
		//ʹ��״̬ת�Ʒ���
		int maxProfit2(vector<int>& prices) {
			if (prices.size() <= 1) return 0;
			int dp_i_0 = 0;//Max_profit
			int dp_i_1 = INT_MIN;//-minprices
			for (int i = 0; i < (int)prices.size(); ++i)
			{
				dp_i_0 = max(dp_i_0, prices[i]+dp_i_1);
				dp_i_1 = max(dp_i_1, -prices[i]);
			}
			return dp_i_0;
		}
	};
}