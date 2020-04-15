namespace leetcode2 {
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* new_l1 = l1;
			ListNode* new_l2 = l2;
			ListNode* cur = nullptr;
			ListNode* res = nullptr;
			int carry = 0;
			bool isHead = true;
			while (new_l1 != nullptr || new_l2 != nullptr || carry) {
				int sum = carry;
				if (new_l1) {
					sum += new_l1->val;
					new_l1 = new_l1->next;
				}
				if (new_l2) {
					sum += new_l2->val;
					new_l2 = new_l2->next;
				}
				if (isHead) {
					ListNode* node = new ListNode(sum % 10);
					res = node;
					cur = res;
					isHead = false;
					carry = sum / 10;
					continue;
				}
				ListNode* node = new ListNode(sum % 10);
				cur->next = node;
				cur = cur->next;
				carry = sum / 10;
			}
			return res;
		}
	};
}