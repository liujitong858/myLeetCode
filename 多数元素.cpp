#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
namespace leetcode169 {
	class Solution {
	public:
		//排序之后，输出中位数
		//时间复杂度O(nlogn) 空间复杂度O(logn)
		int majorityElement(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			return nums[(int)nums.size() / 2];
		}
		//哈希表的方法 空间0（n）时间O（n）
		int maiorityElement1(vector<int>& nums) {
			unordered_map<int, int> hash;
			for (auto elem : nums) {
				++hash[elem];
				if (hash[elem] > (int)nums.size()/2) return elem;
			}
			return -1;
		}
		//摩尔投票法
		//时间复杂度O(n),空间复杂度O（1
		//摩尔投票法，遇到相同的数，就投一票，遇到不同的数，就减一票，最后还存在票的数就是众数）
		int majorityElement2(vector<int>& nums) {
			int candidate = -1;
			int count = 0;
			for (int num : nums) {
				if(count==0)candidate = num;//count=0的时候重新换数
			    if (num == candidate) ++count;	
				else --count;
			}
			return candidate;
		}
	};
}
