#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode55 {
	class Solution {
	public:
		//���ĳһ����Ϊ ������ �ĸ��ӿ�����Ծ�ľ����� 3����ô��ʾ���� 3 �����Ӷ�������Ϊ �����㡣
		//���Զ�ÿһ������Ϊ ������ �ĸ��Ӷ�������һ�Σ��� ��������Զ�ľ��� ���ϸ��¡�
		//�������һֱ������󣬾ͳɹ��ˡ�

		bool canJump(vector<int>& nums) {
			int can_reach = 0;
			for (int i = 0; i < nums.size(); ++i) {
				if (i > can_reach) return false;//˵����λ�õ�����
				can_reach = max(can_reach, i + nums[i]);
			}
			return true;
		}
	};
}