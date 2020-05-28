#include<vector>
using namespace std;
namespace leetcode240 {
	class Solution {
	public:
		//缩减搜索空间的思想
		//同 两数之和II-输入有序序列；盛水最多的容器
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			if (matrix.empty() || matrix[0].empty()) return false;
			//只有右上角和左下角的元素开始可以只选择一边
			//如果从左下角开始的话，如果小于target那么纵坐标++
			//如果大于target那么横坐标--
			int row = matrix.size() - 1;
			int col = matrix[0].size() - 1;
			int cur_row = row, cur_col = 0;//左下角元素
			while (cur_row >= 0 && cur_row <= row && cur_col >= 0 && cur_col <= col) {
				if (matrix[cur_row][cur_col] < target) ++cur_col;
				else if (matrix[cur_row][cur_col] > target) --cur_row;
				else return true;
			}
			return false;
		}
	};
}