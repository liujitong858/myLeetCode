#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode152 {
	
	class Solution {
	public:
		//这题是求数组中子区间的最大乘积，
		//对于乘法，我们需要注意，负数乘以负数，会变成正数，
		//所以解这题的时候我们需要维护两个变量，当前的最大值，以及最小值，
		//最小值可能为负数，但没准下一步乘以一个负数，当前的最大值就变成最小值，而最小值则变成最大值了。
		int maxProduct(vector<int>& nums) {
			if ((int)nums.size() == 1) return nums[0];
			int maxNum = nums[0], minNum = nums[0], curMulti = nums[0];
			for (int i = 1; i < (int)nums.size(); ++i)
			{
				int MAX = maxNum, MIN = minNum;//i-1的最大值//i-1的最小值
				maxNum = max(MAX*nums[i], max(MIN*nums[i], nums[i]));//这里加上Nums[i]的原因是因为如果maxNum为0.那么需要从Nums[i]开始算起
				minNum = min(MIN*nums[i], min(MAX*nums[i], nums[i]));//否则就一直是0
				curMulti = max(maxNum, curMulti);
			}
			return curMulti;
		}
	};
}