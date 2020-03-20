#include<vector>
#include<unordered_set>
#include <algorithm>
using namespace std;
namespace leetcode136 {

	class Solution {
	public:
		//没有额外空间，线性时间
		//异或解法的关键是意识到：
		//0与任何数的异或等于那个数
		//相同的两个数异或还是0
		int singleNumber(vector<int>& nums) {
			int res = 0;
			for (int i = 0; i < (int)nums.size(); ++i)
			{
				res ^= nums[i];
			}
			return res;
		}
		//有额外空间、线性时间
		//利用unordered_set或者unordered_map （哈希表）进行判断
		int singleNumber1(vector<int>& nums) {
			unordered_set<int> hashtable;
			int ans=0;
			for (auto i : nums) {
				if (hashtable.count(i))   hashtable.erase(i);
				else    hashtable.insert(i);
			}
			for (auto j : hashtable)  ans = j;
			return ans;
		}
		//sort之后，根据两个相同的数是挨着的，第一遍遍历相同的置-1
		//第二遍如果不是-1的就是结果，如果走完第二个循环还没有结果，说明
		//出现一次的数为-1
		int singleNumber3(vector<int>& nums) {
			int len = (int)nums.size();
			sort(nums.begin(), nums.end());
			for (int i = 0; i < len - 1; i++)
			{
				if (nums[i] != -1 && nums[i] == nums[i + 1])
				{
					nums[i] = -1;
					nums[i + 1] = -1;
				}
			}
			for (int i = 0; i < len; i++)
			{
				if (nums[i] != -1)
					return nums[i];
			}
			return -1;
		}
	};
}