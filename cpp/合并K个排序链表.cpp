#include<vector>
#include<queue>
using namespace std;
namespace leetcode23 {
	class Solution {
	public:
		struct ListNode {
			int val;
			ListNode *next;
			ListNode(int x) : val(x), next(nullptr) {}
		};
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			if (lists.empty()) return nullptr;
			ListNode* newHead = nullptr;
			int countOfList = lists.size();
			for (int i = 0; i < countOfList; ++i) {
				newHead = mergeKLists_helper(newHead, lists[i]);
			}
			return newHead;
		}
		ListNode* mergeKLists_helper(ListNode* l1, ListNode* l2) {
			if (l1 == nullptr) return l2;
			if (l2 == nullptr) return l1;
			ListNode* newHead = (l1->val < l2->val) ? l1 : l2;
			if (newHead == l1) l1 = l1->next;
			else  l2 = l2->next;
			ListNode* cur = newHead;
			while (l1 != nullptr&&l2 != nullptr) {
				if (l1->val <= l2->val) {
					cur->next = l1;
					cur = cur->next;
					l1 = l1->next;
				}
				else {
					cur->next = l2;
					cur = cur->next;
					l2 = l2->next;
				}
			}
			cur->next = (l1 == nullptr) ? l2 : l1;
			return newHead;
		}
		//空间复杂度：递归会使用到 O(logk) 空间代价的栈空间。

		ListNode* merge(vector <ListNode*> &lists, int l, int r) {
			if (l == r) return lists[l];
			if (l > r) return nullptr;
			int mid = (l + r) >> 1;
			return mergeKLists_helper(merge(lists, l, mid), merge(lists, mid + 1, r));
		}

		ListNode* mergeKLists1(vector<ListNode*>& lists) {
			return merge(lists, 0, lists.size() - 1);
		}

		// 小根堆的回调函数
		    struct cmp {
			  bool operator()(ListNode *a, ListNode *b) {
				 return a->val > b->val;
			  }
		    };
			ListNode* mergeKLists2(vector<ListNode*>& lists) {
				priority_queue<ListNode*, vector<ListNode*>, cmp> pri_queue;
				// 建立大小为k的小根堆
				for (auto elem : lists) {
					if (elem) pri_queue.push(elem);
				}
				ListNode dummy(-1);
				ListNode* cur = &dummy;
				while (!pri_queue.empty()) {
					ListNode* top = pri_queue.top();
					pri_queue.pop();
					cur->next = top;
					cur = cur->next;
					if (top->next)pri_queue.push(top->next);
				}
				return dummy.next;
			}
	};
}