#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode209 {
	class Solution {
	public:
		//时间复杂度：O(n)
		//滑动窗口
		//类双指针
		int minSubArrayLen(int s, vector<int>& nums) {
			if (nums.empty()) return 0;
			int cur = 0;
			int minLength = INT_MAX;
			int left = 0;
			for (int i = 0; i < (int)nums.size(); ++i) {
				cur += nums[i];
				while (cur >= s) {
					minLength = min(minLength, i - left + 1);//长度
					cur -= nums[left];
					++left;
				}
			}
			return minLength == INT_MAX ? 0 : minLength;
		}
	};
}