#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode148 {

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
	class Solution {
	public:
		//常规的做法
		ListNode* sortList(ListNode* head) {
			if (head == nullptr) return nullptr;
			vector<int> vec;
			ListNode* node = head;
			while (node != nullptr) {
				vec.push_back(node->val);
				node = node->next;
			}
			sort(vec.begin(), vec.end());
			node = head;
			for (int i = 0; i < (int)vec.size(); ++i) {
				node->val = vec[i];
				node = node->next;
			}
			return head;
		}

		//要考虑在 O(nlog n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
		//根据时间复杂度我们自然想到二分法，从而联想到归并排序
		//对数组做归并排序的空间复杂度为 O(n)，分别由新开辟数组O(n)和递归函数调用O(logn)组成，而根据链表特性：

		//数组额外空间：链表可以通过修改引用来更改节点顺序，无需像数组一样开辟额外空间；
	    //递归额外空间：递归调用函数将带来O(logn)的空间复杂度，因此若希望达到O(1)空间复杂度，则不能使用递归。
		//双指针+归并排序
		ListNode* sortList1(ListNode* head) {
			if (head == nullptr || head->next == nullptr) return head;
			ListNode* pre = head;;
			ListNode* slow = head;
			ListNode* fast = head;
			while (fast&&fast->next) {
				pre = slow;
				slow = slow->next;
				fast = fast->next->next;
			}
			pre->next = nullptr;//用于切断链
			return merge(sortList(head), sortList(slow));
		}
		ListNode* merge(ListNode* ls1, ListNode* ls2) {
			if (ls1 == nullptr) return ls2;
			if (ls2 == nullptr) return ls1;
			ListNode* dummyhead = new ListNode(-1);
			ListNode* p = dummyhead;
			while (ls1&&ls2) {
				if (ls1->val < ls2->val) {
					p->next = ls1;
					ls1 = ls1->next;
				}
				else {
					p->next = ls2;
					ls2 = ls2->next;
				}
				p = p->next;
			}
			p->next = ls1 == nullptr ? ls2 : ls1;
			return dummyhead->next;
		}

	};


}
