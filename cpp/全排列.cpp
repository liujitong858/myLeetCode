#include<vector>
using namespace std;
namespace leetcode46 {
	class Solution {
	public:
		vector<vector<int>> res;
		vector<vector<int>> permute(vector<int>& nums) {
			vector<int> track;
			permute_helper(nums, track);
			return res;
		}
		void permute_helper(vector<int>& nums, vector<int>& track)
		{
			if (track.size() == nums.size()) {
				res.push_back(track);
			}
			for (int i = 0; i < nums.size(); ++i) {
				if (find(track.begin(), track.end(), nums[i]) == track.end()) {
					track.push_back(nums[i]);
				}
				else continue;
				permute_helper(nums, track);
				track.pop_back();
			}
		}
	};
}