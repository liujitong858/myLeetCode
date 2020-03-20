namespace leetcode206 {
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
  };

	class Solution {
	public:
		//普通迭代 时间复杂度O(n) 空间复杂度0(1)
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

		//递归
		ListNode* reverseList1(ListNode* head) {
			if (head == nullptr || head->next == nullptr) return head;
			ListNode* ret = reverseList(head->next);//最后一层ret是最后一个结点
			head->next->next = head;				//head为倒数第二个结点
			head->next = nullptr;
			return ret;
		}
	};
}