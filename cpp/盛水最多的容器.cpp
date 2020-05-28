#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode11 {
	class Solution {
	public:
		//����ʱ������
		int maxArea(vector<int>& height) {
			if (height.empty() || height.size() < 2) return 0;
			int max = 0;
			for (int i = 0; i < (int)height.size(); ++i) {
				for (int j = i; j < (int)height.size(); ++j) {
					int temp = min(height[i], height[j])*abs(j - i);
					if (temp > max) max = temp;
				}
			}
			return max;
		}

		//���������ռ��˼��
		//O��n) ˫ָ��ⷨ
		//һ��ʼ����ָ��һ��ָ��ͷһ��ָ���β����ʱ�����ĵ������ģ�
		//����������ָ�������ƶ�������������ĵױ�С��
		//�������������Ҫ������ʢˮ��࣬��ֻ���������ĸ����¹���
		//�����Ǹ���ξ����ĸ�ָ���ƶ��أ�
		//�����ܹ����ֲ�������ָ�������ƶ�һλ��������ָ�������ƶ�һλ�������ĵ׶���һ���ģ�
		//����ԭ�������� 1��
		//���������������Ҫ��ָ���ƶ��������������󣬾�Ҫʹ�ƶ���������ĸ߾�����
		//����������ѡ��ָ����ָ�ĸ߽�С���Ǹ�ָ������ƶ����������Ǿͱ����������ϸߵ������ߣ������˽�С�������ߣ��Ի���и��ߵıߵĻ��ᡣ
		int maxArea1(vector<int>& height) {
			if (height.empty() || height.size() < 2) return 0;
			int res = 0;
			int left = 0;
			int right = height.size() - 1;
			while (left < right) {
				res = max(res, (right - left)*min(height[left], height[right]));
				if (height[left] < height[right]) ++left;
				else --right;
			}
			return res;
		}
	};
}