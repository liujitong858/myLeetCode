
#include<vector>
using namespace std;
namespace leetcode77 {
	class Solution {
	public:
		//使用了回溯模板
		vector<vector<int>> res;
		vector<vector<int>> combine(int n, int k) {
			vector<int> track;
			combine_helper(n, k, track, 1);
			return res;
		}
		//函数和计算子集的差不多，区别在于，更新 res 的地方是树的底端。
		void combine_helper(int n, int k, vector<int>& track, int start)
		{
			if (track.size() == k) {
				res.push_back(track);
				return;
			}
			for (int i = start; i <= n; ++i)
			{
				track.push_back(i);
				combine_helper(n, k, track, i + 1);
				track.pop_back();
			}
		}
	};
}