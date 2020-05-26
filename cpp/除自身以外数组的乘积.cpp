#include<vector>
using namespace std;
namespace leetcode238 {
	class Solution {
	public:
		//����ʱ�����Ƶ�����
		vector<int> productExceptSelf(vector<int>& nums) {
			if (nums.empty()) return vector<int>();
			vector<int> res(nums.size());
			for (int i = 0; i < (int)nums.size(); ++i) {
				res[i] = productExceptSelf_helper(nums, i);
			}
			return res;
		}
		int productExceptSelf_helper(vector<int>& nums, int index) {
			int mul = 1;
			for (int i = 0; i < (int)nums.size(); ++i) {
				if (i != index) mul *= nums[i];
			}
			return mul;
		}

		//�ֳ�ǰ׺�ͺ�׺
		//Ȼ��˻�
		vector<int> productExceptSelf1(vector<int>& nums) {
			if (nums.empty()) return vector<int>();
			int length = nums.size();
			vector<int> left(length);
			vector<int> right(length);
			left[0] = 1;
			right[length - 1] = 1;
			for (int i = 1; i < length; ++i) {
				left[i] = left[i - 1] * nums[i - 1];
			}
			for (int j = length - 2; j >= 0; --j) {
				right[j] = right[j + 1] * nums[j + 1];
			}
			for (int k = 0; k < length; ++k) {
				left[k] *= right[k];
			}
			return left;
		}
		//��������ķ����Ѿ��ܹ��ܺõĽ��������⣬���ǲ��ǳ����Ŀռ临�Ӷȡ�
		//����������鲻���ڿռ临�Ӷ��ڣ�
		//��ô���ǿ��Խ� L �� R ��������������������㣬Ȼ���ٶ�̬������һ�����������������������˼����㷨��
		//�Ż���һ������İ汾
		vector<int> productExceptSelf2(vector<int>& nums) {
			if (nums.empty()) return vector<int>();
			int length = nums.size();
			vector<int> left(length);
			vector<int> right(length);
			left[0] = 1;
			right[length - 1] = 1;
			for (int i = 1; i < length; ++i) {
				left[i] = left[i - 1] * nums[i - 1];
			}
			int R = 1;
			for (int j = length - 1; j >= 0; --j) {
				left[j] = R * left[j];
				R *= nums[j];
			}
			return left;
		}
	};
}