#include<vector>
using namespace std;
namespace leetcode338 {
	//���� = ż�� + 1
	//ż�� = ż�� * 2 ������1��
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
				//x &= x - 1�����������Խ����������Ҳ��1��Ϊ0
				res[i] = res[i >> 1] + (i & 1);//�����
			}
			return res;
		}
	};
}