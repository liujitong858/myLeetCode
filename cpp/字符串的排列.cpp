#include<string>
#include<unordered_map>
using namespace std;
namespace leetcode567 {
	class Solution {
	public:
		//输入: s1 = "ab" s2 = "eidbaooo"
		//输出 : True
		//解释 : s2 包含 s1 的排列之一("ba").

		//输入: s1= "ab" s2 = "eidboaoo"
		//输出: False
		bool checkInclusion(string s1, string s2) {
			if (s1.size() > s2.size()) return false;
			int length = s1.size();
			//模式串的字典：可以看作一种频率分布
			vector<int> hashmap1(26, 0);
			//动态更新的匹配窗口字典
			vector<int> hashmap2(26, 0);

			for (int i = 0; i < length; ++i) {
				hashmap1[s1[i] - 'a']++;
				hashmap2[s2[i] - 'a']++;
			}
			for (int i = length; i < s2.size(); ++i) {
				if (hashmap1 == hashmap2) return true;
				//如果不相等 ，向右滑窗 滑窗对于 hash 表的操作变为对应频率的增减
				hashmap2[s2[i - length] - 'a']--;
				hashmap2[s2[i] - 'a']++;
			}
			//整个算法采用左闭右开区间，还有最后一个窗口没有判断
			return hashmap1 == hashmap2;
		}
		bool checkInclusion1(string s1, string s2) {
			if (s1.size() > s2.size()) return false;
			unordered_map<char, int> need, windows;
			for (auto ch : s1) {
				need[ch]++;
			}
			int left = 0;
			int right = 0;
			int vaild = 0;
			while (right < s2.size()) {
				char ch = s2[right];
				right++;
				if (need.count(ch)) {
					windows[ch]++;
					if (need[ch] == windows[ch]) {
						vaild++;
					}
				}
				while (right - left >= s1.size()) {
					if (vaild == need.size()) return true;
					char char_ = s2[left];
					left++;
					if (need.count(char_)) {
						if (need[char_] == windows[char_]) {
							vaild--;
						}
						windows[char_]--;
					}
				}
			}
			return false;
		}
	};
}