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
		//�򵥵ı�����������
		//ʱ�临�Ӷ� O(n),�ռ临�Ӷ�O(1)
		//���ַ�����Ҫ�����������顣��û�п�����һ�α������ҵ��е��أ������ÿ���ָ�롣
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
		//���͵Ŀ���ָ�뷨,�ǳ����
		//ʱ�临�Ӷ� O(n),�ռ临�Ӷ�O(1)
		//��ͼ��ʾ�ǳ�����
		ListNode* middleNode1(ListNode* head) {
			ListNode* fast = head;
			ListNode* slow = head;
			while (fast != nullptr&&fast->next != nullptr) {
				fast = fast->next->next;
				slow = slow->next;
			}
			return slow;
		}
		//ʱ�临�Ӷ� O(n),�ռ临�Ӷ�O(n)
		ListNode* middleNode2(ListNode* head) {
			vector<ListNode*> vec = { head };
			while (vec.back()->next!=nullptr) {
				vec.push_back(vec.back()->next);
			}
			return vec[vec.size()/2];
		}
	};
}