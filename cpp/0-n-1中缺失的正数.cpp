#include<vector>
using namespace std;
namespace offer53 {
	class Solution {
		//˫100%��ֻҪ�Ƚ������±�͸��±��Ӧ��ֵ���ɣ����ų�ȱʧ0��ȱʧ���һ���������������
		 int missingNumber(vector<int>& nums) {
			if (nums[0] == 1) return 0;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] != i) return i;
			}
			return nums.size();//����ע�⣬���ȫ��û���ҵ���������n
		}
		 //���������е��������⣬�����뵽���ַ��������getһ���¼���
		 //����ʱ������ i �� j �ֱ�ָ�� �������������λԪ�ء� ����˷��� i ���ɡ�
		 int missingNumber1(vector<int>& nums) {
			 int left = 0;
			 int right = nums.size();
			 int middle = 0;
			 while (left < right) {
				 middle = left + (right - left) / 2;
				 if (nums[middle] == middle) {//˵��ȱʧ���������Ҳ�
					 left = middle + 1;
				 }
				 else right = middle ;
			 }
			 return left;
		 }
	};
}

