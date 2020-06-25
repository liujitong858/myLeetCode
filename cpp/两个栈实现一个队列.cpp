#include<stack>
#include<vector>
using namespace std;
namespace offer09 {
	class CQueue {
	public:
		CQueue() {
			//��ӵ���һ��ջ��
			//ȡ��head��ʱ���㵹���ڶ���ջ��
			//�ȵڶ���ջΪ�յ�ʱ���ٴ��㵹
		}

		void appendTail(int value) {
			sta1.push(value);
		}

		int deleteHead() {
			if (!sta2.empty()) {
				int head = sta2.top();
				sta2.pop();
				return head;
			}
			else {//sta2�ǿյ�
				while (!sta1.empty()) {
					int num = sta1.top();
					sta1.pop();
					sta2.push(num);
				}
				if (!sta2.empty()) {
					int head = sta2.top();
					sta2.pop();
					return head;
				}
				else return -1;
			}
		}
	private:
		stack<int> sta1;
		stack<int> sta2;
	};

	/**
	 * Your CQueue object will be instantiated and called as such:
	 * CQueue* obj = new CQueue();
	 * obj->appendTail(value);
	 * int param_2 = obj->deleteHead();
	 */
}