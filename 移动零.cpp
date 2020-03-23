#include<vector>
using namespace std;
namespace leetcode283 {
	class Solution {
	public:
		void moveZeroes(vector<int>& nums) {
			//1��������Կ�����������Ļ������԰ѷ�0�ŵ�һ�����飬Ȼ�����ԭ����,0�ӵ����������
			//2������ɨ�裬ɨ�赽0��erase��ͬʱ��¼����������0push_back
			if (nums.empty()) return;
			int countOf0 = 0;
			for (auto iter = nums.begin(); iter != nums.end();)	{
				if (*iter == 0)	{	
					iter = nums.erase(iter);
					++countOf0;
				}
				else ++iter;
			}
			for (int i = 0; i < countOf0; ++i){
				nums.push_back(0);
			}
		}
		//ɨ�赽��0��Ԫ��ֱ�ӷŵ���ǰ�棬Ȼ���¼һ�����һ������Ԫ�ص�λ��
		//�ٴα��������ӷ���Ԫ����һλһֱ������������С��ȫ����Ϊ0
		//  ����˫ָ��ķ������ɱ��� ��cur�� ��ʾ�Ŀ���ָ�븺������Ԫ�ء�
		//	������ҵ���Ԫ�ز��� 0�����Ǿ�������ҵ��ķ� 0 Ԫ��֮���¼����
		//	����ҵ��ķ� 0 Ԫ�ص�λ������ָ�� ��lastnonzerofoundat�� ������ʾ
		//	�������ǲ��Ϸ����µķ� 0 Ԫ��ʱ������ֻ���� ��lastnonzerofoundat + 1�� 
		//	�ڸ��������������ǡ��˸��ǲ��ᵼ���κ����ݶ�ʧ����Ϊ�����Ѿ����������е����ݣ�
		//	������Ƿ� 0 �ģ����������Ѿ�д������Ӧ������������������� 0�����Ժ󽫽��д�����
		//	�� ��cur�� �������������ĩβ֮����������֪�����з� 0 Ԫ�ض��Ѱ�ԭʼ˳���ƶ�������Ŀ�ͷ��
		//	������ʱ����������Ҫ���ˣ��������� 0 �ƶ���ĩβ����
		//	��������ֻ��Ҫ�� ��lastnonzerofoundat�� ����֮���� 0 �������������
		void moveZeroes1(vector<int>& nums) {
			int lastNonZeroFoundAt = 0;
			for (int cur = 0; cur < nums.size(); cur++) {
				if (nums[cur] != 0) {
					nums[lastNonZeroFoundAt++] = nums[cur];
				}
			}
			for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
				nums[i] = 0;
			}
		}	
		//�������������˫ָ�룬ֻ��Ҫ����һ��
		//��ˣ�����������һ������Ԫ��ʱ��
     	//������Ҫ������ǰָ�������ָ��ָ���Ԫ�أ�
     	//Ȼ��ǰ������ָ�롣���������Ԫ�أ�����ֻǰ����ǰָ�롣
		 void moveZeroes2(vector<int>& nums) {
			for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
				if (nums[cur] != 0) {
					swap(nums[lastNonZeroFoundAt++], nums[cur]);
				}
			}
		}
	};
}





