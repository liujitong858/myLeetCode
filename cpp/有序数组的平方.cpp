#include<vector>
using namespace std;
namespace leetcode977 {
	class Solution {
	public:
		//双指针
		vector<int> sortedSquares(vector<int>& A) {
			if (A.empty()) return {};
			int left = 0;
			int right = A.size() - 1;
			int cur = A.size() - 1;
			vector<int> res(A.size());
			while (cur >= 0) {
				int left_ = A[left] * A[left];
				int right_ = A[right] * A[right];
				if (left_ > right_) {
					left++;
					res[cur] = left_;
				}
				else {
					right--;
					res[cur] = right_;
				}
				cur--;
			}
			return res;
		}

		//如果不是排序数组，可以使用hashset来保存数字的平方，重复就存不进去，
		//那么最后就可以直接返回set的大小size即可。时间空间复杂度都是O（n)。
		//双指针遍历：这里是排序数组，既然有重复，肯定是有负数，0, 1这些数字。平方后两头大，
		//中间小，可以用首尾指针共同向中间扫描，扫描时去掉重复元素，同时用一个sum来记录有多少个不同数字。
		//时间复杂度O(N)，空间复杂度O(1)。
		int sortedSquares1(vector<int>& A) {
			if (A.empty()) return 0;
			int length = A.size();
			int left = 0;
			int right = length - 1;
			int sum = 0;
			while (left <= right) {
				if (A[left]+A[right]==0) {
					sum++;
					int temp = A[left];
					while (left <= right&&A[left] == temp) {
						left++;
					}
					while (left <= right&&A[right] == -temp) {
						right--;
					}
				}
				else if (A[left] + A[right] > 0) {
					sum++;
					int temp = A[right];
					while (left <= right && A[right] == temp) {
						right--;
					}
				}
				else {
					sum++;
					int temp = A[left];
					while (left<=right&&A[left]==temp)		{
						left++;
					}
				}
			}
			return sum;
		}

		//一个数据先递增再递减，找出数组不重复的个数，比如 [1, 3, 9, 1]，结果为3，不能使用额外空间，复杂度o(n)
		//解法和上述一样，双指针向中间逼近
	};
}