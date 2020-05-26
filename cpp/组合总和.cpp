#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode39 {
	class Solution {
	public:
		vector<vector<int>> res;
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			//组合不能重复，组合问题
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
				//在搜索的时候，需要设置搜索起点的下标 begin ，由于一个数可以使用多次，下一层的结点从这个搜索起点开始搜索；
				//在搜索起点 begin 之前的数因为以前的分支搜索过了，所以一定会产生重复。
				child.push_back(candidates[i]);
				combinationSum_helper(candidates, target - candidates[i], child, i);
				child.pop_back();
			}
		}
	};
}
