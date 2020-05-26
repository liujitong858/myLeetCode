#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode40 {
	class Solution {
	public:
		//这道题与上一问的区别在于：
		//第 39 题：candidates 中的数字可以无限制重复被选取。
		//第 40 题：candidates 中的每个数字在每个组合中只能使用一次。
			
		//编码的不同在于下一层递归的起始索引不一样。
		//第 39 题：还从候选数组的当前索引值开始。
		//第 40 题：从候选数组的当前索引值的下一位开始。
		//相同之处：解集不能包含重复的组合。

		//注意，我用的是find判断是否去重，这里也可以通过剪枝去重，详见Leetcode40高票评论1
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