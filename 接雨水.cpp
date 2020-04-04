#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode41 {
	class Solution {
	public:
		//时间复杂度为O(n2)数组中的每个元素都需要向左向右扫描。
		//超出了时间限制
		int trap(vector<int>& height) {
			int max_left = 0;
			int max_right = 0;
			int res = 0;
			for (int i = 1; i < (int)height.size() - 1; ++i)
			{
				max_left = 0;
				max_right = 0;
				//从当前元素向左扫描并更新
				for (int j = i; j >= 0; --j)
				{
					max_left = max(max_left, height[j]);
				}
				//从当前元素向右扫描并更新
				for (int k = i; k < (int)height.size(); ++k)
				{
					max_right = max(max_right, height[k]);
				}
				//因为在计算左侧最大和右侧最大的时候
				//首先与自己进行比较，不会出现负数
				res += min(max_left, max_right) - height[i];
			}
			return res;
		}
		int trap1(vector<int>& height) {
			vector<int> max_left(height.size(), 0);
			vector<int> max_right(height.size(), 0);
			int res = 0;
			//初始化别忘记了
			max_left[0] = height[0];
			max_right[height.size() - 1] = height[height.size() - 1];
			for (int j = 1; j <= (int)height.size() - 2; ++j)
			//不记录两边的元素，两边元素装不了水
			{
				max_left[j] = max(max_left[j - 1], height[j]);
			}
			for (int j = (int)height.size() - 2; j >= 1; --j)
			{
				max_right[j] = max(max_right[j + 1], height[j]);
			}
			for (int i = 1; i <= (int)height.size() - 2; ++i)
			{
				res += min(max_left[i], max_right[i]) - height[i];
			}
			return res;
		}
		//定理一：在某个位置i处，它能存的水，取决于它左右两边的最大值中较小的一个。
		//定理二：当我们从左往右处理到left下标时，左边的最大值left_max对它而言是可信的，但right_max对它而言是不可信的。
		//定理三：当我们从右往左处理到right下标时，右边的最大值right_max对它而言是可信的，但left_max对它而言是不可信的。
		//对于位置left而言，它左边最大值一定是left_max，右边最大值“大于等于”right_max，
		//这时候，如果left_max<right_max成立，那么它就知道自己能存多少水了。
		//无论右边将来会不会出现更大的right_max，都不影响这个结果。 
		//所以当left_max<right_max时，我们就希望去处理left下标，反之，我们希望去处理right下标。
		//双指针
		int trap2(vector<int>& height)
		{
			int left = 0, right = height.size() - 1;
			int ans = 0;
			int left_max = 0, right_max = 0;
			while (left < right) {
				if (height[left] < height[right]) {
					height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
					++left;
				}
				else {
					height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
					--right;
				}
			}
			return ans;
		}
	};
}