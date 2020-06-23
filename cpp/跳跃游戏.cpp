#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode55 {
	class Solution {
	public:
		//如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
		//可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。
		//如果可以一直跳到最后，就成功了。

		bool canJump(vector<int>& nums) {
			int can_reach = 0;
			for (int i = 0; i < nums.size(); ++i) {
				if (i > can_reach) return false;//说明有位置到不了
				can_reach = max(can_reach, i + nums[i]);
			}
			return true;
		}
	};
}