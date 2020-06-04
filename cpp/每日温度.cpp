#include<vector>
#include<stack>
using namespace std;
namespace leetcode739 {
	class Solution {
	public:
		//����ʱ������
		vector<int> dailyTemperatures(vector<int>& T) {
			if (T.empty()) return vector<int>();
			if (T.size() == 1) return { 0 };
			int length = (int)T.size();
			vector<int> res(length, 0);
			//res���һ��Ԫ�ص�ֵΪ0
			for (int i = 0; i < length - 1; ++i) {
				for (int j = i + 1; j < length; ++j) {
					if (T[j] > T[i]) {
						res[i] = j - i;
						break;
					}
				}
			}
			return res;
		}

		//�����������飬���ջ���գ��ҵ�ǰ���ִ���ջ��Ԫ�أ���ô���ֱ����ջ�Ļ��Ͳ��� �ݼ�ջ ��
		//������Ҫȡ��ջ��Ԫ�أ����ڵ�ǰ���ִ���ջ��Ԫ�ص����֣�����һ���ǵ�һ������ջ��Ԫ�ص�����ֱ������±����Ƕ��ߵľ��롣
		//�������µ�ջ��Ԫ�أ�ֱ����ǰ����С�ڵ���ջ��Ԫ��ֹͣ��Ȼ��������ջ��
		//�����Ϳ���һֱ���ֵݼ�ջ����ÿ�����ֺ͵�һ�������������ľ���Ҳ�����������
		//���� �ݼ�ջ ��ջ��ֻ�еݼ�Ԫ�ء�
		vector<int> dailyTemperatures1(vector<int>& T) {
			if (T.empty()) return vector<int>();
			stack<int> sta;
			vector<int> res(T.size(), 0);
			for (int i = 0; i < (int)T.size(); ++i) {
				while (!sta.empty() && T[sta.top()] < T[i]) {
					res[sta.top()] = i - sta.top();
					sta.pop();
				}
				sta.push(i);
			}
			return res;
		}
	};
}