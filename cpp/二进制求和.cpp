#include<string>
using namespace std;
namespace leetcode67 {
	class Solution {
	public:
		string addBinary(string a, string b) {
			if (a.size() == 0) return b;
			if (b.size() == 0) return a;
			int push = 0;
			string ans = "";
			int i = a.size() - 1;
			int j = b.size() - 1;
			while (i >= 0 || j >= 0 || push) {
				int res = push;
				if (i >= 0) {
					res += a[i] - '0';
					--i;
				}
				if (j >= 0) {
					res += b[j] - '0';
					--j;
				}
				push = res / 2;//½øÎ»
				ans.push_back('0' + res % 2);
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
	};
}