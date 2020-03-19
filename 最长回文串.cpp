using namespace std;
#include<string>
#include <unordered_map>
class Solution {
public:
	//在一个回文串中，只有最多一个字符出现了奇数次，其余的字符都出现偶数次。
	//使用了哈希表、一个标志位
	int longestPalindrome(string s) {
		if (s.empty()) return 0;
		int maxCount = 0;
		unordered_map<int, int> hashtable;
		for (auto i = 0; i < s.size(); ++i) {
			hashtable[s[i]]++;
		}
		bool first = true;
		for (auto iter = hashtable.begin(); iter != hashtable.end(); ++iter) {
			if (iter->second % 2 == 0) maxCount += iter->second;
			else {
				if (first) {
					maxCount += iter->second;
					first = false;
				}
				else maxCount += iter->second - 1;
			}
		}
		return maxCount;
	}
	//更加简洁的办法
	//使用了C++11中 类foreach的遍历方法
	//利用了整数向下取整的办法，同时只要判断合为奇偶 +1
	int longestPalindrome1(string s) {
		unordered_map<char, int> count;
		int ans = 0;
		for (char c : s)
			++count[c];
		for (auto p : count) {
			int v = p.second;
			ans += v / 2 * 2;				//先向下取整再*2
			if (v % 2 == 1 and ans % 2 == 0)//如果是奇数，且合为偶数
				++ans;
		}
		return ans;
	}
};