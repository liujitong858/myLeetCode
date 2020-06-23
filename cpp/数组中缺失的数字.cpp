#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
namespace leetcode268 {
	class Solution {
	public:
		//数学方法
		int missingNumber(vector<int>& nums) {
			if (nums.empty()) return 0;
			int sum = 0;
			for (int i = 1; i <= nums.size(); ++i) {
				sum += i;
				sum -= nums[i - 1];
			}
			return sum;
		}
		//排序
		int missingNumber1(vector<int>& nums) {
			if (nums.empty()) return 0;
			sort(nums.begin(), nums.end());
			for (int i = 0; i < nums.size(); ++i) {
				if (i != nums[i]) return i;
			}
			return 0;
		}
		//哈希表
		int missingNumber2(vector<int>& nums) {
			if (nums.empty()) return 0;
			unordered_set<int> hashset;
			for (auto num : nums) hashset.insert(num);
			for (int i = 0; i <= nums.size(); ++i) {
				if (hashset.count(i)==0) return i;
			}
			return 0;
		}

		//一个无序数组，从小到大找到第一个缺的数，比如[8 2 4 3 6 9 7 11 12],第一个缺的就是5 （2）
		//1.排序，时间复杂度O(NlogN)
		//2.用数组作为哈希表，将数字i放入数组中的i索引处，然后找中间没有存入数字的位置。时间和空间复杂度都是O(N)
		//先求出最大最小值，确定数组整体范围
		//然后初始化为负数
		//遍历原数组 填充辅助数组 nums[i]=i;
		//扫描辅助数组，第一个 num[i]!=i 的输出 i
	};
}