namespace leetcode160 {
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
	class Solution {
	public:
		//利用长度差，长的先走长度差，然后同时走
		//时间复杂度O(m+n)
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
		//可以理解成两个人速度一致， 走过的路程一致。
		//那么肯定会同一个时间点到达终点。
		//如果到达终点的最后一段路两人都走的话，
		//那么这段路上俩人肯定是肩并肩手牵手的。
	    //A和B两个链表长度可能不同，但是A + B和B + A的长度是相同的，
	    //所以遍历A + B和遍历B + A一定是同时结束。
	    //如果A, B相交的话A和B有一段尾巴是相同的，
	    //所以两个遍历的指针一定会同时到达交点 
	    //如果A, B不相交的话两个指针就会同时到达A + B（B + A）的尾节点
		//时间复杂度O（m+n）空间复杂度 O(1)
		ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
			if (headA == nullptr || headB == nullptr) return nullptr;
			ListNode* curA = headA;
			ListNode* curB = headB;
			while (curA!=curB)//如果不相交同时到达尾节点，都是Nullptr
			{
				curA = curA == nullptr ? headB : curA->next;
				curB = curB == nullptr ? headA : curB->next;
			}
			return curA;
		}
	};
}