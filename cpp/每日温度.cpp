#include<vector>
#include<stack>
using namespace std;
namespace leetcode739 {
	class Solution {
	public:
		//超出时间限制
		vector<int> dailyTemperatures(vector<int>& T) {
			if (T.empty()) return vector<int>();
			if (T.size() == 1) return { 0 };
			int length = (int)T.size();
			vector<int> res(length, 0);
			//res最后一个元素的值为0
			for (int i = 0; i < length - 1; ++i) {
				for (int j = i + 1; j < length; ++j) {
					if (T[j] > T[i]) {
						res[i] = j - i;
						break;
					}
				}
			}
			return res;
		}

		//遍历整个数组，如果栈不空，且当前数字大于栈顶元素，那么如果直接入栈的话就不是 递减栈 ，
		//所以需要取出栈顶元素，由于当前数字大于栈顶元素的数字，而且一定是第一个大于栈顶元素的数，直接求出下标差就是二者的距离。
		//继续看新的栈顶元素，直到当前数字小于等于栈顶元素停止，然后将数字入栈，
		//这样就可以一直保持递减栈，且每个数字和第一个大于它的数的距离也可以算出来。
		//它是 递减栈 ：栈里只有递减元素。
		vector<int> dailyTemperatures1(vector<int>& T) {
			if (T.empty()) return vector<int>();
			stack<int> sta;
			vector<int> res(T.size(), 0);
			for (int i = 0; i < (int)T.size(); ++i) {
				while (!sta.empty() && T[sta.top()] < T[i]) {
					res[sta.top()] = i - sta.top();
					sta.pop();
				}
				sta.push(i);
			}
			return res;
		}
	};
}