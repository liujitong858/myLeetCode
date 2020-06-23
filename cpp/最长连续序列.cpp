#include<algorithm>
#include<unordered_map>
using namespace std;
namespace leetcode128 {
	class Solution {
	public:
		//O(nlogn)
		int longestConsecutive(vector<int>& nums) {
			if (nums.empty()) return 0;
			if (nums.size() == 1) return 1;
			int maxLength = 1;//记得初始化的时候为1
			int left = 0;
			int right = 0;
			sort(nums.begin(), nums.end());//还要去重
			nums.erase(unique(nums.begin(), nums.end()), nums.end());
			for (int i = 1; i < nums.size(); ++i) {
				if (nums[i] == nums[right] + 1) {
					right++;
				}
				else {
					left = i;
					right = i;
				}
				maxLength = max(maxLength, right - left + 1);
			}
			return maxLength;
		}
		//使用哈希表辅助
		int longestConsecutive1(vector<int>& nums) {
			if (nums.empty()) return 0;
			if (nums.size() == 1) return 1;
			int maxLength = 1;//注意初始值
			unordered_map<int, int> hashmap;
			for (auto num : nums) {
				hashmap[num]++;
			}
			for (int i = 0; i < nums.size(); ++i) {
				if (hashmap.count(nums[i] - 1) == 0) {//找到开头元素
					int num = nums[i] + 1;
					int Length = 1;
					while (hashmap.count(num)) {
						num++;
						Length++;
					}
					maxLength = max(maxLength, Length);
				}
			}
			return maxLength;
		}
	};
}