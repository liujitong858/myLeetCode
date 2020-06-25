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
			head = new ListNode(-1);//��ʼ��һ��ͷ����ǹؼ�
		}
		void push(int x) {
			ListNode* node = new ListNode(x);
			node->next = head->next;//�����ŵ�head��һ�����
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