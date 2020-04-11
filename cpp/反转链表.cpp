namespace leetcode206 {
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
  };

	class Solution {
	public:
		//��ͨ���� ʱ�临�Ӷ�O(n) �ռ临�Ӷ�0(1)
		ListNode* reverseList(ListNode* head) {
			if (head == nullptr) return head;
			ListNode* pre = nullptr;
			ListNode* cur = head;
			ListNode* temp;
			while (cur != nullptr) {
				temp = cur->next;
				cur->next = pre;
				pre = cur;
				cur = temp;
			}
			return pre;
		}

		//�ݹ�
		ListNode* reverseList1(ListNode* head) {
			if (head == nullptr || head->next == nullptr) return head;
			ListNode* ret = reverseList(head->next);//���һ��ret�����һ�����
			head->next->next = head;				//headΪ�����ڶ������
			head->next = nullptr;
			return ret;
		}
	};
}