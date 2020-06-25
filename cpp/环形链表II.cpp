namespace leetcode142 {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

//����ָ�룺���ÿ���ָ�룬��������ͷ��������ָ��ÿ������������ָ��һ����һ����
//�����л���һ�������ڻ���ĳ��(����1)������������ָ��ֱ�������������ͷ����
//���߶���Ϊÿ����һ�������������ڻ����(����2)��
//֤������1�����ÿ���ָ��fast��low��fastÿ����������lowÿ����һ����
//�����л�������һ������������Ϊlowһ���������ɿ���fast�ں���׷��low�Ĺ��̣�
//ÿ�����߶��ӽ�һ�������һ����׷�ϣ���
//֤������2��
//	�裺
//		����ͷ������ڳ���Ϊ--a
//		����ڵ������㳤��Ϊ--b
//		�����㵽����ڳ���Ϊ--c

//����ʱ
//��ָ��·�� = a + (b + c)k + b ��k >= 1 ����b + cΪ���ĳ��ȣ�
//kΪ�ƻ���Ȧ����k >= 1, ������һȦ��������0Ȧ����Ȼ����ָ���ߵ�һ������ì�ܣ���
//��ָ��·�� = a + b
//��ָ���ߵ�·������ָ������������ԣ�
//��a + b�� * 2 = a + (b + c)k + b
//����ɵã�
//a = (k - 1)(b + c) + c ���ʽ�ӵ���˼�ǣ�
//����ͷ������ڵľ��� = �����㵽����ڵľ��� + ��k - 1��Ȧ�����ȡ�����k >= 1, ����k - 1 >= 0Ȧ��
//��������ָ��ֱ������ͷ����������������һ�������ڻ���ڡ�
	class Solution {
	public:
		ListNode *detectCycle(ListNode *head) {
			if (head == nullptr) return nullptr;
			ListNode* quick = head;
			ListNode* slow = head;
			while (quick != nullptr&&quick->next != nullptr) {
				slow = slow->next;
				quick = quick->next->next;
				if (quick == slow) {
					slow = head;
					while (quick != slow) {
						slow = slow->next;
						quick = quick->next;
					}
					return quick;
				}
			}
			return nullptr;
		}
	};

}