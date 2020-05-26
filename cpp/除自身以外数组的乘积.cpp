#include<vector>
using namespace std;
namespace leetcode238 {
	class Solution {
	public:
		//超出时间限制的做法
		vector<int> productExceptSelf(vector<int>& nums) {
			if (nums.empty()) return vector<int>();
			vector<int> res(nums.size());
			for (int i = 0; i < (int)nums.size(); ++i) {
				res[i] = productExceptSelf_helper(nums, i);
			}
			return res;
		}
		int productExceptSelf_helper(vector<int>& nums, int index) {
			int mul = 1;
			for (int i = 0; i < (int)nums.size(); ++i) {
				if (i != index) mul *= nums[i];
			}
			return mul;
		}

		//分成前缀和后缀
		//然后乘积
		vector<int> productExceptSelf1(vector<int>& nums) {
			if (nums.empty()) return vector<int>();
			int length = nums.size();
			vector<int> left(length);
			vector<int> right(length);
			left[0] = 1;
			right[length - 1] = 1;
			for (int i = 1; i < length; ++i) {
				left[i] = left[i - 1] * nums[i - 1];
			}
			for (int j = length - 2; j >= 0; --j) {
				right[j] = right[j + 1] * nums[j + 1];
			}
			for (int k = 0; k < length; ++k) {
				left[k] *= right[k];
			}
			return left;
		}
		//尽管上面的方法已经能够很好的解决这个问题，但是不是常数的空间复杂度。
		//由于输出数组不算在空间复杂度内，
		//那么我们可以将 L 或 R 数组在用输出数组来计算，然后再动态构造另一个。让我们来看看基于这个思想的算法。
		//优化成一个数组的版本
		vector<int> productExceptSelf2(vector<int>& nums) {
			if (nums.empty()) return vector<int>();
			int length = nums.size();
			vector<int> left(length);
			vector<int> right(length);
			left[0] = 1;
			right[length - 1] = 1;
			for (int i = 1; i < length; ++i) {
				left[i] = left[i - 1] * nums[i - 1];
			}
			int R = 1;
			for (int j = length - 1; j >= 0; --j) {
				left[j] = R * left[j];
				R *= nums[j];
			}
			return left;
		}
	};
}