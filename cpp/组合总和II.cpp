#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode40 {
	class Solution {
	public:
		//���������һ�ʵ��������ڣ�
		//�� 39 �⣺candidates �е����ֿ����������ظ���ѡȡ��
		//�� 40 �⣺candidates �е�ÿ��������ÿ�������ֻ��ʹ��һ�Ρ�
			
		//����Ĳ�ͬ������һ��ݹ����ʼ������һ����
		//�� 39 �⣺���Ӻ�ѡ����ĵ�ǰ����ֵ��ʼ��
		//�� 40 �⣺�Ӻ�ѡ����ĵ�ǰ����ֵ����һλ��ʼ��
		//��֮ͬ�����⼯���ܰ����ظ�����ϡ�

		//ע�⣬���õ���find�ж��Ƿ�ȥ�أ�����Ҳ����ͨ����֦ȥ�أ����Leetcode40��Ʊ����1
		vector<vector<int>> res;
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			if (candidates.empty()) return vector<vector<int>>();
			sort(candidates.begin(), candidates.end());
			vector<int> vec;
			combinationSum2_helper(candidates, vec, target, 0);
			return res;
		}
		void combinationSum2_helper(vector<int>& candidates, vector<int>& vec, int target, int start) {
			if (target == 0 && find(res.begin(), res.end(), vec) == res.end()) {
				res.push_back(vec);
				return;
			}
			for (int i = start; i < (int)candidates.size(); ++i) {
				if (target < candidates[i]) return;
				vec.push_back(candidates[i]);
				combinationSum2_helper(candidates, vec, target - candidates[i], i + 1);
				vec.pop_back();
			}
		}
	};
 }