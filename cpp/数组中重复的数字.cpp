#include<vector>
using namespace std;
namespace leetcode287 {
	class Solution {
	public:
		//1�����ܸ���ԭ���飨����������ֻ���ģ���
		//2��ֻ��ʹ�ö���� O(1) �Ŀռ䡣
		//�����뵽�ķ����У�

		//ʹ�ù�ϣ�����أ���Υ�������� 2��
		//��ԭʼ�������������Ժ��ظ��������ڣ����ҵ����ظ�������Υ�������� 1��
		//ʹ�����ơ����ۡ��� 41 �⣺ȱʧ�ĵ�һ������ ��ԭ�ع�ϣ����˼·��������������Ҫ����ͬһ���ط���ʱ�򣬾ͷ���������ظ���Ԫ�أ���Υ�������� 1��
		//��ȻҪ��λ���������ǡ����һ�������������ڡ���������Ч��Χ�ڡ������ֲ��ң����ǱȽϷ���һ���ǵ÷�������������ü��Σ������ͽ���ͨ�����ַ���λһ���з�Χ��������
		
		//offer����Ľⷨ
		int findDuplicate(vector<int>& nums) {
			//�����Ը���ԭ����
			//ֻ��ʹ�ö���O(1)�Ŀռ�
			//������ʹ�ñ�����
			//ʱ�临�Ӷȣ�O(N \log N)O(NlogN)�����ַ���ʱ�临�Ӷ�Ϊ O(\log N)O(logN)��
			//�ڶ��ַ����ڲ���ִ����һ�� for ѭ����ʱ�临�Ӷ�Ϊ O(N)O(N)����ʱ�临�Ӷ�Ϊ O(N \log N)O(NlogN)��

			if (nums.empty()) return -1;
			int start = 1;
			int end = nums.size() - 1;
			while (start <= end) {
				int middle = (end - start) / 2 + start;
				int count = count_helper(nums, start, middle);
				if (start == end) {
					if (count > 1) return start;
					else return -1;
				}
				if (count > middle - start + 1) {//�ϸ����
					end = middle;
				}
				else start = middle + 1;
			}
			return -1;
		}
		int count_helper(vector<int>& nums, int start, int end) {
			int count = 0;
			for (int i = 0; i < (int)nums.size(); ++i) {
				if (nums[i] >= start && nums[i] <= end) {
					++count;
				}
			}
			return count;
		}

		//������ʹ�á�����ָ�롹�����
		//1.��������һ���ظ������� <= = > �����д��ڻ�
		//2.�ҵ������е��ظ����� <= = > �ҵ�����Ļ����
		//142������ָ����һ��slow = slow.next == > ���� slow = nums[slow]
		//142���п�ָ��������fast = fast.next.next == > ���� fast = nums[nums[fast]]

		int findDuplicate1(vector<int>& nums) {
			int slow = 0;
			int fast = 0;
			slow = nums[slow];
			fast = nums[nums[fast]];
			while (slow!=fast){
				slow = nums[slow];
				fast = nums[nums[fast]];
			}
			//��ʱ�Ѿ����뻷�ڣ������ڻ�����ڲ����ظ�������
			//���Դ�ʱӦ���һ������
			//�軷���ܳ���c�������뻷�����m
			//��fast��slow������ʱ��fast����2n,slow����n
			//fast,����n��ȫ�������ڻ���ѭ����n%c==0����
			//fast��slow����ʱ��slow�ڻ����н��ľ�����n-m������n%c==0��
			//��ʱ��������slowǰ��m������Ҳ�����ڻ�������n���ˡ�
			//��n%c==0��slow�ڻ������ߵľ����ǻ����ܳ������������ͻص��˻�������ˣ�����ھ����ظ������֡�
			//���ǲ�֪����㵽��ڵĳ���m������Ū��finder��slowһ���ߣ����Ǳض�������ڴ�������
			int slow1 = 0;
			int fast1 = slow;
			while (slow1 != fast1) {
				slow1 = nums[slow1];
				fast1 = nums[nums[fast1]];
			}
			return slow1;
		}
		//ԭ�ع�ϣ
		int findDuplicate2(vector<int>& nums) {
			//�����Ը���ԭ����
			//ֻ��ʹ�ö���O(1)�Ŀռ�
			//������ʹ�ñ�����
			if (nums.empty()) return -1;
			for (int i = 0; i < (int)nums.size(); ++i) {
				while (nums[i] != i) {
					if (nums[i] == nums[nums[i]]) {
						return nums[i];
					}
					int temp = nums[nums[i]];
					nums[nums[i]] = nums[i];
					nums[i] = temp;
				}
			}
			return -1;
		}

	};
}