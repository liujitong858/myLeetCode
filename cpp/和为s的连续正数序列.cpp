#include<vector>
#include<algorithm>
using namespace std;
namespace  offer57 {
	class Solution {
	public:
		vector<vector<int>> findContinuousSequence(int target) {
			if (target <= 2) return { {} };
			int left = 1;
			int right = 2;
			vector<vector<int>> res;
			int curSum = left + right;
			while (left < target / 2 + 1) {
				if (curSum < target) {
					++right;
					curSum += right;
				}
				else if (curSum > target) {
					curSum -= left;
					++left;
				}
				else {
					vector<int>vec;
					for (int i = left; i <= right; ++i) {
						vec.push_back(i);
					}
					res.push_back(vec);
					++right;
					curSum += right;
				}
			}
			return res;
		}
	};
	//某一个大文件被拆成了N个小文件，每个小文件编号从0至N-1，相应大小分别记为S(i)。给定磁盘空间为C，
	//试实现一个函数从N个文件中 连续 选出若干个文件拷贝到磁盘中，使得磁盘剩余空间最小。

	//滑动窗口：每次记录窗口内的总和，和小于C，记录剩余空间，再窗口右端右移，和大于C，就窗口左端右移，小于C情况下比较剩余空间取最小值。
	vector<int> findMin(vector<int> s, int c) {
		int i = 0;
		int j = 0;
		int minValue = INT_MAX;
		int sum = s[0];
		int left = 0;
		int right = 0;
		while (j <= s.size()) {
			if (sum <= c) {//目的是求剩余空间最小值时的范围
				j++;
				sum += s[j];
				minValue = min(minValue, c - sum);
				if (minValue == c - sum) {
					left = i;//更新左值
					right = j;//更新右值
				}
			}
			else {
				i++;
				sum -= s[i];
			}
		}
		vector<int> res(right-left);
		
		for (int i = left; i < right; i++) {
			res[i - left] = s[i];//注意这里的索引
		}
		return res;
	}
		
}