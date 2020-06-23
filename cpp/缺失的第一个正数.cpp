#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
namespace leetcode41 {
	class Solution {
	public:
		//原地哈希保证了线性的时间复杂度和常数空间复杂度
		int firstMissingPositive(vector<int>& nums) {
			if (nums.empty()) return 1;
			for (int i = 0; i < nums.size(); ++i) {
				while (nums[i] != i + 1) {
					if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])break;
					int temp = nums[i];
					nums[i] = nums[temp - 1];
					nums[temp - 1] = temp;
				}
			}
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] != i + 1) return i + 1;
			}
			return nums.size() + 1;
		}
		//哈希表
		int firstMissingPositive1(vector<int>& nums) {
			if (nums.empty()) return 1;
			unordered_set<int> hashset;
			for (auto num : nums) {
				hashset.insert(num);
			}
			for (int i = 1; i <= nums.size(); ++i) {
				if (hashset.count(i) == 0) return i;
			}
			return nums.size() + 1;
		}
		//二分法
		int firstMissingPositive2(vector<int>& nums) {
			if (nums.empty()) return 1;
			sort(nums.begin(), nums.end());
			for (int i = 1; i <= nums.size(); ++i) {
				if (binarySearch(nums, i) == -1) return i;
			}
			return nums.size() + 1;
		}
		int binarySearch(vector<int>& nums, int x) {
			int left = 0;
			int right = nums.size();
			int mid = 0;
			while (left < right) {
				mid = left + (right - left) / 2;
				if (nums[mid] == x)return mid;
				else if (nums[mid] < x) left=mid+1;
				else  right=mid;
			}
			return -1;
		}
	};
}