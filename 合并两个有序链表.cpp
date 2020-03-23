
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
  };
class Solution {
public:
	//迭代的方法
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		else if (l2 == nullptr) return l1;
		ListNode* newHead = (l1->val <= l2->val) ? l1 : l2;
		if (newHead == l1) l1 = l1->next;
		else l2 = l2->next;
		ListNode* cur = newHead;
		while (l1 != nullptr&&l2 != nullptr)
		{
			if (l1->val <= l2->val) {
				cur->next = l1;
				l1 = l1->next;
				cur = cur->next;
			}
			else if (l1->val > l2->val) {
				cur->next = l2;
				l2 = l2->next;
				cur = cur->next;
			}
		}
		if (l1 != nullptr) cur->next = l1;
		else cur->next = l2;
		return newHead;
	}
	//递归 If条件中的返回是关键，最后必须返回才能穿起来链表
	 ListNode* mergeTwoLists1( ListNode* l1,  ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		if (l1->val < l2->val) {
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else {
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};