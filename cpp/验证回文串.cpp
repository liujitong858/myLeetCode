#include<vector>
#include<string>
#include<algorithm>
using namespace std;
namespace leetcode125 {
	class Solution {
	public:
		//字母和数字：isalnum();
		//字母     ：isalpha();
		//数字     ：isdigit();
		//大写字母：isupper();
		//小写字母：islower();
		//转化为大写：toupper();
		//转化为小写：tolower();
		bool isPalindrome(string s) {
			if (s.empty()) return true;
			int left = 0;
			string str = "";
			for (int i = 0; i < s.length(); ++i) {
				if (isalnum(s[i])) {
					str += tolower(s[i]);
				}
			}
			int right = str.size() - 1;
			while (left < right) {
				if (str[left] == str[right]) {
					left++;
					right--;
				}
				else return false;
			}
			return true;
		}
		bool isPalindrome1(string s) {
			if (s.empty()) return true;
			string str = "";
			for (int i = 0; i < s.length(); ++i) {
				if (isalnum(s[i])) {
					str += tolower(s[i]);
				}
			}
			string restr = str;
			reverse(str.begin(), str.end());
			return restr == str ? true : false;
		}
		bool isPalindrome2(string s) {
			if (s.empty()) return true;
			int left = 0;
			int right = s.size() - 1;
			while (left < right) {
				while (!isalnum(s[left]) && left < right) {
					++left;
				}
				while (!isalnum(s[right]) && left < right) {
					--right;
				}
				if (left < right) {
					if (tolower(s[left]) != tolower(s[right]))return false;
					++left;
					--right;
				}
			}
			return true;
		}
	};
}