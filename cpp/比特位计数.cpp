#include<vector>
using namespace std;
namespace leetcode338 {
	//奇数 = 偶数 + 1
	//偶数 = 偶数 * 2 （左移1）
	class Solution {
	public:
		vector<int> countBits(int num) {
			vector<int> res(num + 1);
			for (int i = 0; i <= num; ++i)
			{
				/*if (i % 2 == 0) {
					res[i] = res[i >> 1];
				}
				else res[i] = res[i >> 1] + 1;*/
				//x &= x - 1这样操作可以将二进制最右侧的1变为0
				res[i] = res[i >> 1] + (i & 1);//更简洁
			}
			return res;
		}
	};
}