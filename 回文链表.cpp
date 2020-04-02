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
		//方法是可行的，但是慢的离谱！！
		bool isPalindrome(ListNode* head) {
			//空间复杂度被限制为常数，不允许使用哈希表
			//那么只考虑到使用双指针，但是又是单向链表
			//考虑使用一个string去保存前一半的整数
			if (head == nullptr) return true;
			if (head->next == nullptr) return true;
			string res = "";
			int count = 0;
			ListNode* start = head;
			ListNode* end = head;
			while (end != nullptr)//计算总长度
			{
				++count;
				end = end->next;
			}
			int half = count / 2;//前进长度的一半步
			while (half)//前面一半的数字加到字符串中
			{
				--half;
				res.append(" ");
				res.append(to_string(start->val));
				start = start->next;
			}
			//如果是奇数，再走一步，因为中间是什么数都不影响回文结构
			if (count % 2 == 1) start = start->next;
			while (start != nullptr)
			{
				int index = res.rfind(" ");
				string value = res.substr(index + 1);
				if (value == to_string(start->val))
				{
					res.erase(index);//删除最后一个元素
					start = start->next;
				}
				else return false;
			}
			return true;
		}
		//反转链表的后半部分然后双指针判断
		bool isPalindrome1(ListNode* head) {
			if (head == nullptr || head->next == nullptr) return true;
			ListNode* slow = head;
			ListNode* quick = head;
			ListNode* pre = nullptr;
			ListNode* cur = head;
			int count = 1;
			while (quick->next != nullptr)//quick指向最后一个结点
			{
				++count;
				quick = quick->next;
			}
			int mid = count / 2;
			while (mid)//获取中间结点
			{
				--mid;
				cur = cur->next;
			}
			ListNode* nextNode;
			while (cur)//反转中间往后的结点
			{
				nextNode = cur->next;
				cur->next = pre;
				pre = cur;
				cur = nextNode;
			}
			while (quick != slow && quick != nullptr)//对比
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
		//更快的算法，反转链表的前半部分
		//可以与快慢指针一同前进
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
			//如果为奇数，slow落在mid上，Mid不需要判断
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
		//如果对空间复杂度没有要求的话
		//可以将val复制到数组中，然后双指针
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