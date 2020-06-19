#include<vector>
using namespace std;
namespace leetcode51 {
	class Solution {
	public:
		vector<vector<string>> res;
		vector<vector<string>> solveNQueens(int n) {
			if (n == 0) return res;
			vector<string> board(n, string(n, '.'));//初始化棋盘
			solveNQueens_helper(board, 0);
			return res;
		}
		void solveNQueens_helper(vector<string>& board, int row) {
			if (row == board.size()) {
				res.push_back(board);
				return;
			}
			int n = board[row].size();
			for (int col = 0; col < n; ++col) {
				if (!isVaild(board, row, col)) continue;//剪枝
				board[row][col] = 'Q';
				solveNQueens_helper(board, row + 1);
				board[row][col] = '.';
			}
		}
		bool isVaild(vector<string>& board, int row, int col) {
			int n = board[row].size();
			//检查列是否有皇后冲突
			for (int i = 0; i < n; ++i) {
				if (board[i][col] == 'Q') return false;
			}
			//检查左上是否有皇后冲突
			for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
				if (board[i][j] == 'Q') return false;
			}
			//检查右上是否有皇后冲突
			for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
				if (board[i][j] == 'Q') return false;
			}
			return true;
		}
	};
}