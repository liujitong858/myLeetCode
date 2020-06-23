#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode31 {
	class Solution {
	public:
		void nextPermutation(vector<int>& nums) {
			if (nums.empty() || nums.size() == 1) return;
			int length = nums.size();
			int i = length - 2;
			int j = length - 1;
			int k = length - 1;
			while (i >= 0 && nums[i] >= nums[j]) {
				--i;
				--j;
			}
			if (i >= 0) {
				while (k > 0 && nums[i] >= nums[k]) {
					--k;
				}
				int temp = nums[k];
				nums[k] = nums[i];
				nums[i] = temp;
			}
			sort(nums.begin() + j, nums.end());
		}
		//直接使用stl库中的permutation函数
		void nextPermutation1(vector<int>& nums) {
			next_permutation(nums.begin(), nums.end());
		}
	};
}