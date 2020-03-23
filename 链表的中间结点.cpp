#include<vector>
using namespace std;
namespace leetcode876 {
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

	class Solution {
	public:
		//简单的遍历两次链表
		//时间复杂度 O(n),空间复杂度O(1)
		//这种方法需要遍历链表两遍。有没有可能用一次遍历就找到中点呢？答案是用快慢指针。
		ListNode* middleNode(ListNode* head) {
			int length = 1;
			ListNode* node = head;
			while (node->next != nullptr) {
				++length;
				node = node->next;
			}
			node = head;
			int middle = length / 2;
			while (middle != 0) {
				--middle;
				node = node->next;
			}
			return node;
		}
		//典型的快慢指针法,非常简洁
		//时间复杂度 O(n),空间复杂度O(1)
		//画图表示非常清晰
		ListNode* middleNode1(ListNode* head) {
			ListNode* fast = head;
			ListNode* slow = head;
			while (fast != nullptr&&fast->next != nullptr) {
				fast = fast->next->next;
				slow = slow->next;
			}
			return slow;
		}
		//时间复杂度 O(n),空间复杂度O(n)
		ListNode* middleNode2(ListNode* head) {
			vector<ListNode*> vec = { head };
			while (vec.back()->next!=nullptr) {
				vec.push_back(vec.back()->next);
			}
			return vec[vec.size()/2];
		}
	};
}