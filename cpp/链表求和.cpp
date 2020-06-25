namespace mianshi0205{
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* head = new ListNode(-1);
			ListNode* curA = l1;
			ListNode* curB = l2;
			ListNode* p = head;
			int sum = 0;
			int carry = 0;
			while (curA || curB || carry) {
				sum = 0;
				if (curA) {
					sum += curA->val;
					curA = curA->next;
				}
				if (curB) {
					sum += curB->val;
					curB = curB->next;
				}
				sum += carry;
				p->next = new ListNode(sum % 10);
				sum = sum / 10;
				carry = sum;//进位保留在carry中
				p = p->next;
			}
			return head->next;
		}
	};
}