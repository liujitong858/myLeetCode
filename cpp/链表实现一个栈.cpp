namespace ListCompleteStack {
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode(int x) :val(x), next(nullptr){}
	};
	class ListToStack
	{
	public:
		ListToStack() {
			head = new ListNode(-1);//初始化一个头结点是关键
		}
		void push(int x) {
			ListNode* node = new ListNode(x);
			node->next = head->next;//将结点放到head下一个结点
			head->next = node;
		}
		int pop() {
			if (head->next) {
				ListNode* node = head->next;
				head->next = node->next;
				node->next = nullptr;
				return node->val;
			}
			else return -1;
		}
		int top() {
			if (head->next) {
				return head->next->val;
			}
			else return -1;
		}
		bool empty() {
			return head->next == nullptr ? true : false;
		}
	private:
		ListNode* head;
	};
}