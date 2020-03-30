#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode198 {
	class Solution {
	public:
		//动态规划
		int rob(vector<int>& nums) {
			if (nums.empty()) return 0;
			if ((int)nums.size() == 1) return nums[0];
			if ((int)nums.size() == 2) return max(nums[0], nums[1]);
			vector<int> dp((int)nums.size());
			dp[0] = nums[0];
			dp[1] = max(nums[0], nums[1]);
			for (int i = 2; i < (int)nums.size(); ++i)
			{
				dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
			}
			return dp[(int)nums.size() - 1];
		}
		//因为当前的状态只跟前两个状态有关，所以可以进行优化
		int rob1(vector<int>& nums) {
			if (nums.empty()) return 0;
			if ((int)nums.size() == 1) return nums[0];
			if ((int)nums.size() == 2) return max(nums[0], nums[1]);
			int dp_i2 = nums[0];
			int dp_i1 = max(nums[0], nums[1]);
			for (int i = 2; i < (int)nums.size(); ++i)
			{
				int temp = dp_i1;
				dp_i1 = max(dp_i2 + nums[i], dp_i1);
				dp_i2 = temp;
			}
			return dp_i1;
		}
	};
}