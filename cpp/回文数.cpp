#include<vector>
#include<string>
#include<algorithm>
using namespace std;
namespace leetcode9 {
	class Solution {
	public:
		//对于回文类
		//1、暴力
		//2、先考虑使用字符串的情况
		bool isPalindrome(int x) {
			string x_string = to_string(x);
			if (x_string.size() == 0 || x_string.size() == 1) return true;
			return isPalindrome_helper(x_string, 0, x_string.size() - 1);
		}
		bool isPalindrome_helper(string& x_string, int left, int right) {
			while (left < right) {
				if (x_string[left] == x_string[right]) {
					++left;
					--right;
				}
				else return false;
			}
			return true;
		}

		//字符串反转后直接比较
		bool isPalindrome1(int x) {
			string x_string = to_string(x);
			string ori_string = x_string;
			if (x_string.size() == 0 || x_string.size() == 1) return true;
			reverse(x_string.begin(), x_string.end());//反转
			return ori_string == x_string ? true : false;
		}

		bool isPalindrome2(int x) {
			if (x < 0) return false;
			int div = 1;
			while (x / div >= 10) div *= 10;//获取千位数字需要的除数
			while (x > 0) {
				int left = x / div;//最左侧数字
				int right = x % 10;//最右侧数字
				if (left != right) return false;
				x = (x % div) / 10;//或者中间百位和十位的新数字
				div /= 100;//除以100，以在下一个循环获取到十位的数字
			}
			return true;
		}
		//使用vector
		bool isPalindrome3(int x) {
			if (x < 0) return false;
			if (x / 10 == 0) return true;//0-9
			vector<int> tmp;
			while (x > 0) {
				tmp.emplace_back(x % 10);
				x /= 10;
			}
			for (int i = tmp.size() - 1, j = 0; i > 0, j < i; i--, j++)
				if (tmp[i] != tmp[j]) return false;
			return true;
		}
	};
}