namespace leetcode25 {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};
	class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {
			if (head == nullptr) return head;
			int len = 0;
			ListNode* node = head;
			while (node != nullptr) {
				++len;
				node = node->next;
			}
			ListNode* dummy = new ListNode(0);
			ListNode* pre = dummy;
			dummy->next = head;
			ListNode* cur = head;
			ListNode* temp;
			if (len < k) return head;
			for (int i = 0; i < len / k; ++i) {
				for (int j = 0; j < k - 1; ++j) {
					temp = cur->next;//2
					cur->next = temp->next;//1-3
					temp->next = pre->next;//2-1-3
					pre->next = temp;//dummy-2-1-3
				}
				pre = cur;//
				cur = cur->next;
			}
			return dummy->next;
		}
	};

}