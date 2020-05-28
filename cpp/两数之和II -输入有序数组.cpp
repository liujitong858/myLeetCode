#include<vector>
using namespace std;
namespace leetcode167 {
	class Solution {
	public:
		//缩减搜索空间的思想
		//双指针解法
		vector<int> twoSum(vector<int>& numbers, int target) {
			if (numbers.empty() || numbers.size() < 2) return vector<int>();
			int left = 0;
			int right = numbers.size() - 1;
			int sum = 0;
			while (left < right) {
				sum = numbers[left] + numbers[right];
				if (sum > target) --right;
				else if (sum < target) ++left;
				else return { left + 1,right + 1 };
			}
			return vector<int>();
		}
	};
}