#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode41 {
	class Solution {
	public:
		//ʱ�临�Ӷ�ΪO(n2)�����е�ÿ��Ԫ�ض���Ҫ��������ɨ�衣
		//������ʱ������
		int trap(vector<int>& height) {
			int max_left = 0;
			int max_right = 0;
			int res = 0;
			for (int i = 1; i < (int)height.size() - 1; ++i)
			{
				max_left = 0;
				max_right = 0;
				//�ӵ�ǰԪ������ɨ�貢����
				for (int j = i; j >= 0; --j)
				{
					max_left = max(max_left, height[j]);
				}
				//�ӵ�ǰԪ������ɨ�貢����
				for (int k = i; k < (int)height.size(); ++k)
				{
					max_right = max(max_right, height[k]);
				}
				//��Ϊ�ڼ�����������Ҳ�����ʱ��
				//�������Լ����бȽϣ�������ָ���
				res += min(max_left, max_right) - height[i];
			}
			return res;
		}
		int trap1(vector<int>& height) {
			vector<int> max_left(height.size(), 0);
			vector<int> max_right(height.size(), 0);
			int res = 0;
			//��ʼ����������
			max_left[0] = height[0];
			max_right[height.size() - 1] = height[height.size() - 1];
			for (int j = 1; j <= (int)height.size() - 2; ++j)
			//����¼���ߵ�Ԫ�أ�����Ԫ��װ����ˮ
			{
				max_left[j] = max(max_left[j - 1], height[j]);
			}
			for (int j = (int)height.size() - 2; j >= 1; --j)
			{
				max_right[j] = max(max_right[j + 1], height[j]);
			}
			for (int i = 1; i <= (int)height.size() - 2; ++i)
			{
				res += min(max_left[i], max_right[i]) - height[i];
			}
			return res;
		}
		//����һ����ĳ��λ��i�������ܴ��ˮ��ȡ�������������ߵ����ֵ�н�С��һ����
		//������������Ǵ������Ҵ���left�±�ʱ����ߵ����ֵleft_max���������ǿ��ŵģ���right_max���������ǲ����ŵġ�
		//�������������Ǵ���������right�±�ʱ���ұߵ����ֵright_max���������ǿ��ŵģ���left_max���������ǲ����ŵġ�
		//����λ��left���ԣ���������ֵһ����left_max���ұ����ֵ�����ڵ��ڡ�right_max��
		//��ʱ�����left_max<right_max��������ô����֪���Լ��ܴ����ˮ�ˡ�
		//�����ұ߽����᲻����ָ����right_max������Ӱ���������� 
		//���Ե�left_max<right_maxʱ�����Ǿ�ϣ��ȥ����left�±꣬��֮������ϣ��ȥ����right�±ꡣ
		//˫ָ��
		int trap2(vector<int>& height)
		{
			int left = 0, right = height.size() - 1;
			int ans = 0;
			int left_max = 0, right_max = 0;
			while (left < right) {
				if (height[left] < height[right]) {
					height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
					++left;
				}
				else {
					height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
					--right;
				}
			}
			return ans;
		}
	};
}