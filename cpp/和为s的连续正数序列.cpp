#include<vector>
#include<algorithm>
using namespace std;
namespace  offer57 {
	class Solution {
	public:
		vector<vector<int>> findContinuousSequence(int target) {
			if (target <= 2) return { {} };
			int left = 1;
			int right = 2;
			vector<vector<int>> res;
			int curSum = left + right;
			while (left < target / 2 + 1) {
				if (curSum < target) {
					++right;
					curSum += right;
				}
				else if (curSum > target) {
					curSum -= left;
					++left;
				}
				else {
					vector<int>vec;
					for (int i = left; i <= right; ++i) {
						vec.push_back(i);
					}
					res.push_back(vec);
					++right;
					curSum += right;
				}
			}
			return res;
		}
	};
	//ĳһ�����ļ��������N��С�ļ���ÿ��С�ļ���Ŵ�0��N-1����Ӧ��С�ֱ��ΪS(i)���������̿ռ�ΪC��
	//��ʵ��һ��������N���ļ��� ���� ѡ�����ɸ��ļ������������У�ʹ�ô���ʣ��ռ���С��

	//�������ڣ�ÿ�μ�¼�����ڵ��ܺͣ���С��C����¼ʣ��ռ䣬�ٴ����Ҷ����ƣ��ʹ���C���ʹ���������ƣ�С��C����±Ƚ�ʣ��ռ�ȡ��Сֵ��
	vector<int> findMin(vector<int> s, int c) {
		int i = 0;
		int j = 0;
		int minValue = INT_MAX;
		int sum = s[0];
		int left = 0;
		int right = 0;
		while (j <= s.size()) {
			if (sum <= c) {//Ŀ������ʣ��ռ���Сֵʱ�ķ�Χ
				j++;
				sum += s[j];
				minValue = min(minValue, c - sum);
				if (minValue == c - sum) {
					left = i;//������ֵ
					right = j;//������ֵ
				}
			}
			else {
				i++;
				sum -= s[i];
			}
		}
		vector<int> res(right-left);
		
		for (int i = left; i < right; i++) {
			res[i - left] = s[i];//ע�����������
		}
		return res;
	}
		
}