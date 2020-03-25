#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode892 {
	class Solution {
	public:
		int surfaceArea(vector<vector<int>>& grid) {
			if (grid.empty())return 0;
			int res = 0;
			int blocks = 0;//�������
			int cover = 0;//��ס������
			for (int i = 0; i < (int)grid.size(); ++i)
			{
				for (int j = 0; j < (int)grid[i].size(); ++j)
				{
					blocks += grid[i][j];
					//�����ͳ�Ƶ�ǰ��������Ϊ�ѵ�����ס�˼�����
					cover += grid[i][j] > 1 ? grid[i][j] - 1 : 0;
					if (i > 0) {
						//������һ��ͬһ�и�ס�˶��ٸ���
						cover += min(grid[i - 1][j], grid[i][j]);
					}
					if (j > 0) {
						//����ͬһ��ǰһ�и�ס�˼�����
						cover += min(grid[i][j - 1], grid[i][j]);
					}
				}
			}
			res = blocks * 6 - cover * 2;
			return res;
		}
	};
}