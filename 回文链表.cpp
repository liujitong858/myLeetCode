#include<string>
#include<vector>
using namespace std;
namespace leetcode234 {

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
	class Solution {
	public:
		//�����ǿ��еģ������������ף���
		bool isPalindrome(ListNode* head) {
			//�ռ临�Ӷȱ�����Ϊ������������ʹ�ù�ϣ��
			//��ôֻ���ǵ�ʹ��˫ָ�룬�������ǵ�������
			//����ʹ��һ��stringȥ����ǰһ�������
			if (head == nullptr) return true;
			if (head->next == nullptr) return true;
			string res = "";
			int count = 0;
			ListNode* start = head;
			ListNode* end = head;
			while (end != nullptr)//�����ܳ���
			{
				++count;
				end = end->next;
			}
			int half = count / 2;//ǰ�����ȵ�һ�벽
			while (half)//ǰ��һ������ּӵ��ַ�����
			{
				--half;
				res.append(" ");
				res.append(to_string(start->val));
				start = start->next;
			}
			//���������������һ������Ϊ�м���ʲô������Ӱ����Ľṹ
			if (count % 2 == 1) start = start->next;
			while (start != nullptr)
			{
				int index = res.rfind(" ");
				string value = res.substr(index + 1);
				if (value == to_string(start->val))
				{
					res.erase(index);//ɾ�����һ��Ԫ��
					start = start->next;
				}
				else return false;
			}
			return true;
		}
		//��ת����ĺ�벿��Ȼ��˫ָ���ж�
		bool isPalindrome1(ListNode* head) {
			if (head == nullptr || head->next == nullptr) return true;
			ListNode* slow = head;
			ListNode* quick = head;
			ListNode* pre = nullptr;
			ListNode* cur = head;
			int count = 1;
			while (quick->next != nullptr)//quickָ�����һ�����
			{
				++count;
				quick = quick->next;
			}
			int mid = count / 2;
			while (mid)//��ȡ�м���
			{
				--mid;
				cur = cur->next;
			}
			ListNode* nextNode;
			while (cur)//��ת�м�����Ľ��
			{
				nextNode = cur->next;
				cur->next = pre;
				pre = cur;
				cur = nextNode;
			}
			while (quick != slow && quick != nullptr)//�Ա�
			{
				if (quick->val == slow->val)
				{
					quick = quick->next;
					slow = slow->next;
				}
				else return false;
			}
			return true;
		}
		//������㷨����ת�����ǰ�벿��
		//���������ָ��һͬǰ��
		bool isPalindrome2(ListNode* head) {
			if (head == nullptr || head->next == nullptr) return true;
			ListNode* slow = head;
			ListNode* quick = head;
			ListNode* pre = nullptr;
			ListNode* cur = head;
			while (quick &&quick->next)
			{
				cur = slow;
				slow = slow->next;
				quick = quick->next->next;

				cur->next = pre;
				pre = cur;
			}
			//���Ϊ������slow����mid�ϣ�Mid����Ҫ�ж�
			if (quick != nullptr) slow = slow->next;
			while (cur && slow)
			{
				if (cur->val == slow->val)
				{
					cur = cur->next;
					slow = slow->next;
				}
				else return false;
			}
			return true;
		}
		//����Կռ临�Ӷ�û��Ҫ��Ļ�
		//���Խ�val���Ƶ������У�Ȼ��˫ָ��
		bool isPalindrome3(ListNode* head) {
			if (head == nullptr || head->next == nullptr) return true;
			ListNode* slow = head;
			vector<int >vec;
			while (slow)
			{
				vec.push_back(slow->val);
				slow = slow->next;
			}
			int start = 0;
			int end = vec.size() - 1;
			for (; start < end; ++start, --end)
			{
				if (vec[start] == vec[end]) continue;
				else return false;
			}
			return true;
		}
	};
}