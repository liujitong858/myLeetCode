#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode53 {
	class Solution {
	public:
		//自己的本办法,实际上等价，但是没采用动态规划标准形式
		int maxSubArray(vector<int>& nums) {
			if (nums.empty()) return 0;
			if ((int)nums.size() == 1) return nums[0];
			int count = nums[0];
			int sumMax = nums[0];
			for (int i = 1; i < (int)nums.size(); ++i)
			{
				//如过和是负数 ，则更新，如果nums[i]大于count的话，更新没问题
				//如果nums[i]小于count，+=会更小，所以直接更新
				if (count < 0)
					count = nums[i];
				else
					count += nums[i];
				sumMax = max(sumMax, count);
			}
			return sumMax;
		}

		//动态规划-贪心
		//当前元素位置的最大和
		//迄今为止的最大和
		int maxSubArray1(vector<int>& nums) {
			if (nums.empty()) return 0;
			if ((int)nums.size() == 1) return nums[0];
			int count = nums[0];
			int sumMax = nums[0];
			for (int i = 1; i < (int)nums.size(); ++i)
			{
				//也就是count<0的时候更新
				count = max(nums[i], count + nums[i]);
				sumMax = max(sumMax, count);
			}
			return sumMax;
		}

		//分治
		int maxSubArray2(vector<int>& nums) {
			return maxSubArray_Helper(nums, 0, (int)nums.size() - 1);
		}
		int maxSubArray_Helper(vector<int>& nums, int start, int end) {
			if (start == end) return nums[start];
			int mid = start + (end - start) / 2;
			int leftMax = maxSubArray_Helper(nums, start, mid);// 计算左侧子序列最大值
			int rightMax = maxSubArray_Helper(nums, mid + 1, end);//计算右侧子序列最大值
			//下面是横跨两个子序列的最大值
			int _leftmax = INT_MIN;
			int leftsum = 0;
			int _rightmax = INT_MIN;
			int rightsum = 0;
			// 计算包含左侧子序列最后一个元素的子序列最大值
			for (int i = mid; i >= 0; --i) {
				leftsum += nums[i];
				_leftmax = max(_leftmax, leftsum);
			}
			// 计算包含右侧子序列第一个元素的子序列最大值
			for (int i = mid + 1; i <= end; ++i) {
				rightsum += nums[i];
				_rightmax = max(_rightmax, rightsum);
			}
			// 计算跨中心的子序列的最大值
			int crossMax = _rightmax + _leftmax;
			return max(crossMax, max(leftMax, rightMax));
		}
	};
}
