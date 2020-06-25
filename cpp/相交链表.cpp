namespace leetcode160 {
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
	class Solution {
	public:
		//���ó��Ȳ�������߳��ȲȻ��ͬʱ��
		//ʱ�临�Ӷ�O(m+n)
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			if (headA == nullptr || headB == nullptr)return nullptr;
			int lengthA = 0;
			int lengthB = 0;
			ListNode* curA = headA;
			ListNode* curB = headB;
			while (curA != nullptr) {
				curA = curA->next;
				++lengthA;
			}
			while (curB != nullptr) {
				curB = curB->next;
				++lengthB;
			}
			curA = headA;
			curB = headB;
			int minusLength = 0;
			if (lengthA >= lengthB) {
				minusLength = lengthA - lengthB;
				while (minusLength != 0) {
					curA = curA->next;
					--minusLength;
				}
			}
			else {
				minusLength = lengthB - lengthA;
				while (minusLength != 0) {
					curB = curB->next;
					--minusLength;
				}
			}
			while (curA&&curB) {
				if (curA == curB) return curA;
				curB = curB->next;
				curA = curA->next;
			}
			return nullptr;
		}
		//���������������ٶ�һ�£� �߹���·��һ�¡�
		//��ô�϶���ͬһ��ʱ��㵽���յ㡣
		//��������յ�����һ��·���˶��ߵĻ���
		//��ô���·�����˿϶��Ǽ粢����ǣ�ֵġ�
	    //A��B���������ȿ��ܲ�ͬ������A + B��B + A�ĳ�������ͬ�ģ�
	    //���Ա���A + B�ͱ���B + Aһ����ͬʱ������
	    //���A, B�ཻ�Ļ�A��B��һ��β������ͬ�ģ�
	    //��������������ָ��һ����ͬʱ���ｻ�� 
	    //���A, B���ཻ�Ļ�����ָ��ͻ�ͬʱ����A + B��B + A����β�ڵ�
		//ʱ�临�Ӷ�O��m+n���ռ临�Ӷ� O(1)
		ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
			if (headA == nullptr || headB == nullptr) return nullptr;
			ListNode* curA = headA;
			ListNode* curB = headB;
			while (curA!=curB)//������ཻͬʱ����β�ڵ㣬����Nullptr
			{
				curA = curA == nullptr ? headB : curA->next;
				curB = curB == nullptr ? headA : curB->next;
			}
			return curA;
		}
	};
}