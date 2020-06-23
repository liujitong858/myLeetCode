#include<unordered_map>
#include<string>
using namespace std;
namespace leetcode76 {
	class Solution {
	public:
		//labuladong 的滑动窗口模板
		string minWindow(string s, string t) {
			if (s.size() < t.size()) return "";
			unordered_map<char, int> need, window;
			for (auto ch : t) {
				need[ch]++;
			}
			int left = 0;
			int right = 0;
			int vaild = 0;
			// 记录最小覆盖子串的起始索引及长度
			int start = 0, len = INT_MAX;
			while (right < s.size()) {
				char ch = s[right];//即将移入窗口的字符
				++right;
				if (need.count(ch)) {
					window[ch]++;
					if (need[ch] == window[ch]) vaild++;
				}

				while (vaild == need.size()) {
					// 在这里更新最小覆盖子串
					if (right - left < len) {
						start = left;
						len = right - left;
					}
					char char_ = s[left];//即将移除窗口的字符
					left++;
					if (need.count(char_)) {
						if (need[char_] == window[char_]) vaild--;
						window[char_]--;
					}
				}
			}
			return len == INT_MAX ? "" : s.substr(start, len);
		}
	};
}