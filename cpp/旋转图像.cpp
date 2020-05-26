#include<vector>
using namespace std;
namespace leetcode48 {
	class Solution {
	public:
		void rotate(vector<vector<int>>& matrix) {
			int len = matrix.size();
			int mid = (len - 1) / 2;
			//左右翻转
			//flip over x = len/2
			for (int i = 0; i < len; ++i) {
				for (int j = 0; j <= mid; ++j) {
					swap(matrix[i][j], matrix[i][len - 1 - j]);
				}
			}
			//沿主对角线反转
			//flip over diag
			for (int i = 0; i < len; ++i) {
				for (int j = 0; j < len - 1 - i; ++j) {
					swap(matrix[i][j], matrix[len - 1 - j][len - 1 - i]);
				}
			}
		}
	};
}