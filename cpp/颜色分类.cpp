#include<vector>
using namespace std;
namespace leetcode75 {
	class Solution {
	public:
		//三路快排思想
		//荷兰国旗 颜色问题
		void sortColors(vector<int>& nums) {
			int head = 0, tail = nums.size() - 1;
			int cur = 0;
			while (cur <= tail) {
				switch (nums[cur]) {//因为curr左边的值已经扫描过了，所以curr要++继续扫描下一位，而与p2交换的值，curr未扫描，要停下来扫描一下，所以curr不用++。
				case 0: swap(nums[cur++], nums[head++]);
					break;
				case 1: cur++;
					break;
				case 2: swap(nums[cur], nums[tail--]);
					break;
				}
			}
		}
	};
}