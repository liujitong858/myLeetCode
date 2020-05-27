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
		//���������
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

		//Ҫ������ O(nlog n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£��������������
		//����ʱ�临�Ӷ�������Ȼ�뵽���ַ����Ӷ����뵽�鲢����
		//���������鲢����Ŀռ临�Ӷ�Ϊ O(n)���ֱ����¿�������O(n)�͵ݹ麯������O(logn)��ɣ��������������ԣ�

		//�������ռ䣺�������ͨ���޸����������Ľڵ�˳������������һ�����ٶ���ռ䣻
	    //�ݹ����ռ䣺�ݹ���ú���������O(logn)�Ŀռ临�Ӷȣ������ϣ���ﵽO(1)�ռ临�Ӷȣ�����ʹ�õݹ顣
		//˫ָ��+�鲢����
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
			pre->next = nullptr;//�����ж���
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
