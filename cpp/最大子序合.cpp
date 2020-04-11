#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode53 {
	class Solution {
	public:
		//�Լ��ı��취,ʵ���ϵȼۣ�����û���ö�̬�滮��׼��ʽ
		int maxSubArray(vector<int>& nums) {
			if (nums.empty()) return 0;
			if ((int)nums.size() == 1) return nums[0];
			int count = nums[0];
			int sumMax = nums[0];
			for (int i = 1; i < (int)nums.size(); ++i)
			{
				//������Ǹ��� ������£����nums[i]����count�Ļ�������û����
				//���nums[i]С��count��+=���С������ֱ�Ӹ���
				if (count < 0)
					count = nums[i];
				else
					count += nums[i];
				sumMax = max(sumMax, count);
			}
			return sumMax;
		}

		//��̬�滮-̰��
		//��ǰԪ��λ�õ�����
		//����Ϊֹ������
		int maxSubArray1(vector<int>& nums) {
			if (nums.empty()) return 0;
			if ((int)nums.size() == 1) return nums[0];
			int count = nums[0];
			int sumMax = nums[0];
			for (int i = 1; i < (int)nums.size(); ++i)
			{
				//Ҳ����count<0��ʱ�����
				count = max(nums[i], count + nums[i]);
				sumMax = max(sumMax, count);
			}
			return sumMax;
		}

		//����
		int maxSubArray2(vector<int>& nums) {
			return maxSubArray_Helper(nums, 0, (int)nums.size() - 1);
		}
		int maxSubArray_Helper(vector<int>& nums, int start, int end) {
			if (start == end) return nums[start];
			int mid = start + (end - start) / 2;
			int leftMax = maxSubArray_Helper(nums, start, mid);// ����������������ֵ
			int rightMax = maxSubArray_Helper(nums, mid + 1, end);//�����Ҳ����������ֵ
			//�����Ǻ�����������е����ֵ
			int _leftmax = INT_MIN;
			int leftsum = 0;
			int _rightmax = INT_MIN;
			int rightsum = 0;
			// �������������������һ��Ԫ�ص����������ֵ
			for (int i = mid; i >= 0; --i) {
				leftsum += nums[i];
				_leftmax = max(_leftmax, leftsum);
			}
			// ��������Ҳ������е�һ��Ԫ�ص����������ֵ
			for (int i = mid + 1; i <= end; ++i) {
				rightsum += nums[i];
				_rightmax = max(_rightmax, rightsum);
			}
			// ��������ĵ������е����ֵ
			int crossMax = _rightmax + _leftmax;
			return max(crossMax, max(leftMax, rightMax));
		}
	};
}
