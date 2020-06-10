#include<vector>
using namespace std;
namespace leetcode75 {
	class Solution {
	public:
		//��·����˼��
		//�������� ��ɫ����
		void sortColors(vector<int>& nums) {
			int head = 0, tail = nums.size() - 1;
			int cur = 0;
			while (cur <= tail) {
				switch (nums[cur]) {//��Ϊcurr��ߵ�ֵ�Ѿ�ɨ����ˣ�����currҪ++����ɨ����һλ������p2������ֵ��currδɨ�裬Ҫͣ����ɨ��һ�£�����curr����++��
				case 0: swap(nums[cur++], nums[head++]);
					break;
				case 1: cur++;
					break;
				case 2: swap(nums[cur], nums[tail--]);
					break;
				}
			}
		}
	};
}