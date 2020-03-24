#include<vector>
using namespace std;
namespace leetcode448 {
	class Solution {
	public:
		//������ʹ�ö���ռ����˼���ǲ�����ʹ�ù�ϣ��
		//����������ѭ��������ÿ���������ֻҪ�������ξ����ҵ���������λ��
		//ע�⣺���ظ����ֵ�λ����-1.��Ч�ʱ��ظ�λ�ò�����Ҫ�죬�ײ⡣
		//����ǲ������Ļ��� ���һ��forѭ��ֻ��Ҫ�ж�nums[i] ��= i+1 ,push_back(i+1)
		vector<int> findDisappearedNumbers(vector<int>& nums) {
			vector<int> res;
			for (int i = 0; i < (int)nums.size(); ++i) {
				while (nums[i] != i + 1 && nums[i] != -1) {
					if (nums[nums[i] - 1] != nums[i]) {
						swap(nums[i], nums[nums[i] - 1]);
					}
					else {
						nums[i] = -1;
						break;
					}
				}
			}
			for (int i = 0; i < (int)nums.size(); ++i) {
				if (nums[i] == -1)res.push_back(i + 1);
			}
			return res;
		}
		//������������Ϊ�����±꣬�ö�Ӧ����ֵΪ��ֵ����ô����Ϊ������λ�ü�Ϊ��δ���ֹ�����ʧ������
		vector<int> findDisappearedNumbers1(vector<int>& nums) {
			for (int i = 0; i < nums.size(); ++i)
				nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
			vector<int> res;
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] > 0)
					res.push_back(i + 1);
			}
			return res;
		}
	};
}