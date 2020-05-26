#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode39 {
	class Solution {
	public:
		vector<vector<int>> res;
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			//��ϲ����ظ����������
			if (candidates.empty())return vector<vector<int>>();
			sort(candidates.begin(), candidates.end());
			vector<int> child;
			combinationSum_helper(candidates, target, child, 0);
			return res;
		}
		void combinationSum_helper(vector<int> &candidates, int target, vector<int> &child, int start) {
			if (target == 0) {
				res.push_back(child);
				return;
			}
			for (int i = start; i < (int)candidates.size(); ++i) {
				if (candidates[i] > target) continue;
				//��������ʱ����Ҫ�������������±� begin ������һ��������ʹ�ö�Σ���һ��Ľ������������㿪ʼ������
				//��������� begin ֮ǰ������Ϊ��ǰ�ķ�֧�������ˣ�����һ��������ظ���
				child.push_back(candidates[i]);
				combinationSum_helper(candidates, target - candidates[i], child, i);
				child.pop_back();
			}
		}
	};
}
