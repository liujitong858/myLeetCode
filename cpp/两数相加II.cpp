#include<string>
#include<stack>
using namespace std;
namespace leetcode445 {
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
	class Solution {
	public:
		//���ף�ԭ�����������иı�
		//�������Ҫ�ѵ�������������λ��˳�����������ӷ���˳�����෴�ģ�
		//Ϊ��������������λ�����ǿ���ʹ��ջ������������ѹ��ջ�У�
		//������ȡ����ӡ������������Ҫע���λ�������
		//����ջ
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			stack<int> _l1;
			stack<int> _l2;
			ListNode* res = nullptr;
			int carry = 0;//��λ
			while (l1 != nullptr) {
				_l1.push(l1->val);
				l1 = l1->next;
			}
			while (l2 != nullptr) {
				_l2.push(l2->val);
				l2 = l2->next;
			}
			while (!_l1.empty() || !_l2.empty() || carry > 0) {//����ȡ���ֵĹ��̺��½����Ĺ��̽����һ��
				int sum = carry;
				sum += _l1.empty() ? 0 : _l1.top();
				sum += _l2.empty() ? 0 : _l2.top();
				if (!_l1.empty()) _l1.pop();
				if (!_l2.empty()) _l2.pop();
				ListNode* node = new ListNode(sum % 10);
				node->next = res;
				res = node;
				carry = sum / 10;
			}
			return res;
		}
		//������ƴ�ӳ��ַ��������ǽ�λ
		//Ȼ������ַ���
		ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
			ListNode* node;
			ListNode* res = new  ListNode(0);
			string str_l1 = "";
			string str_l2 = "";
			node = l1;
			while (node != nullptr) {//�������ֺ�
				str_l1 += to_string(node->val);
				node = node->next;
			}
			node = l2;
			while (node != nullptr) {//�������ֺ�
				str_l2 += to_string(node->val);
				node = node->next;
			}
			int Index_l1 = (int)str_l1.size() - 1;
			int Index_l2 = (int)str_l2.size() - 1;
			int carry = 0;
			string res_str = "";
			while (Index_l1 >= 0 || Index_l2 >= 0 || carry) {//������ƴ�ӳ��ַ���
				int cur = carry;
				if (Index_l1 >= 0) cur += str_l1[Index_l1--] - '0';
				if (Index_l2 >= 0) cur += str_l2[Index_l2--] - '0';
				res_str = to_string(cur % 10) + res_str;
				carry = cur / 10;
			}
			node = res;
			for (size_t i = 0; i < res_str.size(); ++i)
			{
				if (i == 0) {
					res->val = res_str[i] - '0';
					continue;
				}
				node->next = new ListNode(res_str[i] - '0');
				node = node->next;
			}
			return res;
		}
		//�ַ����汾���Ż��汾
		//��ƴ���ַ����Ĺ��̺ʹ����½��Ĺ��̺϶�Ϊһ
		//�ٶ�������
		ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
			ListNode* node;
			ListNode* res = nullptr;
			string str_l1 = "";
			string str_l2 = "";
			node = l1;
			while (node != nullptr) {//�������ֺ�
				str_l1 += to_string(node->val);
				node = node->next;
			}
			node = l2;
			while (node != nullptr) {//�������ֺ�
				str_l2 += to_string(node->val);
				node = node->next;
			}
			int Index_l1 = (int)str_l1.size() - 1;
			int Index_l2 = (int)str_l2.size() - 1;
			int carry = 0;
			int cur = 0;
			string res_str = "";
			while (Index_l1 >= 0 || Index_l2 >= 0 || carry) {
				cur = carry;
				if (Index_l1 >= 0) cur += str_l1[Index_l1--] - '0';
				if (Index_l2 >= 0) cur += str_l2[Index_l2--] - '0';
				ListNode* temp = new ListNode(cur % 10);
				temp->next = res;
				res = temp;
				carry = cur / 10;
			}
			return res;
		}
		//��ת�������������ϰ��ת����
		ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
			ListNode* pre = nullptr;
			ListNode* next = nullptr;
			while (l1 != nullptr) {//��ת����
				next = l1->next;
				l1->next = pre;
				pre = l1;
				l1 = next;
			}
			l1 = pre;
			pre = nullptr;
			while (l2 != nullptr) {//��ת����
				next = l2->next;
				l2->next = pre;
				pre = l2;
				l2 = next;
			}
			l2 = pre;
			ListNode* res = nullptr;
			int carry = 0;
			while (l1 || l2 || carry) {
				int sum = carry;
				if (l1) {
					sum += l1->val;
					l1 = l1->next;
				}
				if (l2) {
					sum += l2->val;
					l2 = l2->next;
				}
				ListNode* node = new ListNode(sum % 10);
				node->next = res;
				res = node;
				carry = sum / 10;
			}
			return res;
		}
	};
}