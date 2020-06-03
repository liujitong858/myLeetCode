#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>
using namespace std;
namespace leetcode3 {
	class Solution {
	public:
		//自己的方法感觉相对好理解一些
		//本质上还是滑动窗口
		int lengthOfLongestSubstring(string s) {
			if (s.empty()) return 0;
			string res = "";
			int count = 0;
			for (int i = 0; i < s.size(); ++i) {
				int j = res.find(s[i]);
				if (j == -1) {//不存在s[i]
					res += s[i];
				}
				else {//存在相同的s[i]
					res.erase(0, j + 1);//滑动窗口
					res += s[i];
				}
				count = max(count, (int)res.size());
			}
			return count;
		}
		//使用哈希数组的方法
		int lengthOfLongestSubstring1(string s) {
			if (s.empty()) return 0;
			vector<int> vec(256, -1); //字符有256个
			int left = 0;//查找的左边界
			int maxLength = 0;
			for (int i = 0; i < (int)s.size(); ++i) {
				if (vec[s[i]] != -1 && vec[s[i]] >= left) {
					left = vec[s[i]] + 1;//重新设定左边界
				}
				else {//更新maxLength
					maxLength = max(maxLength, i - left + 1);
				}
				vec[s[i]] = i;//将字符的位置设定为下标
			}
			return maxLength;
		}
		//效果最差
		int lengthOfLongestSubstring2(string s) {
			if (s.empty()) return 0;
			unordered_set<char> hashset;
			int left = 0;//查找的左边界
			int maxLength = 0;
			for (int i = 0; i < (int)s.size(); ++i) {
				while (hashset.find(s[i]) != hashset.end()) {
					hashset.erase(s[left]);
					left++;
				}
				hashset.insert(s[i]);
				maxLength = max(maxLength, (int)hashset.size());
			}
			return maxLength;
		}
	};
}