#include<string>
#include<vector>
#include<algorithm>
using namespace std;
namespace leetcodeMiANSHI46 {
	class Solution {
	public:
		//动态规划+滚动数组
		int translateNum(int num) {
			string src = to_string(num);
			int p = 0;//f(n-2)
			int q = 1;//f(n-1)
			int r = 1;//f(n)
			for (int i = 1; i < src.size(); ++i) {
				p = q;
				q = r;
				r = 0;
				r += q;//f(n)=f(n-1)
				string pre = src.substr(i - 1, 2);
				if (pre <= "25"&&pre >= "10") {
					r += p;//f(n)=f(n-1)+f(n-2)
				}
			}
			return r;
		}
	};
}