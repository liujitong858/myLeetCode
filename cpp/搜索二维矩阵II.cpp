#include<vector>
using namespace std;
namespace leetcode240 {
	class Solution {
	public:
		//���������ռ��˼��
		//ͬ ����֮��II-�����������У�ʢˮ��������
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			if (matrix.empty() || matrix[0].empty()) return false;
			//ֻ�����ϽǺ����½ǵ�Ԫ�ؿ�ʼ����ֻѡ��һ��
			//��������½ǿ�ʼ�Ļ������С��target��ô������++
			//�������target��ô������--
			int row = matrix.size() - 1;
			int col = matrix[0].size() - 1;
			int cur_row = row, cur_col = 0;//���½�Ԫ��
			while (cur_row >= 0 && cur_row <= row && cur_col >= 0 && cur_col <= col) {
				if (matrix[cur_row][cur_col] < target) ++cur_col;
				else if (matrix[cur_row][cur_col] > target) --cur_row;
				else return true;
			}
			return false;
		}
	};
}