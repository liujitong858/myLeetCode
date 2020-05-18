#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode152 {
	
	class Solution {
	public:
		//������������������������˻���
		//���ڳ˷���������Ҫע�⣬�������Ը���������������
		//���Խ������ʱ��������Ҫά��������������ǰ�����ֵ���Լ���Сֵ��
		//��Сֵ����Ϊ��������û׼��һ������һ����������ǰ�����ֵ�ͱ����Сֵ������Сֵ�������ֵ�ˡ�
		int maxProduct(vector<int>& nums) {
			if ((int)nums.size() == 1) return nums[0];
			int maxNum = nums[0], minNum = nums[0], curMulti = nums[0];
			for (int i = 1; i < (int)nums.size(); ++i)
			{
				int MAX = maxNum, MIN = minNum;//i-1�����ֵ//i-1����Сֵ
				maxNum = max(MAX*nums[i], max(MIN*nums[i], nums[i]));//�������Nums[i]��ԭ������Ϊ���maxNumΪ0.��ô��Ҫ��Nums[i]��ʼ����
				minNum = min(MIN*nums[i], min(MAX*nums[i], nums[i]));//�����һֱ��0
				curMulti = max(maxNum, curMulti);
			}
			return curMulti;
		}
	};
}