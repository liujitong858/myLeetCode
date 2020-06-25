#include<queue>
using namespace std;
namespace leetcode225 {
	//˫�˶���
	class MyStack {
	public:
		MyStack() {
			//���ȿ���ʹ��dequeʵ��
		}
		/** Push element x onto stack. */
		void push(int x) {
			queue.push_back(x);
		}
		/** Removes the element on top of the stack and returns that element. */
		int pop() {
			if (!queue.empty()) {
				int staHead = queue.back();
				queue.pop_back();
				return staHead;
			}
			else return -1;
		}
		/** Get the top element. */
		int top() {
			if (!queue.empty()) {
				return queue.back();
			}
			else return -1;
		}
		/** Returns whether the stack is empty. */
		bool empty() {
			return queue.empty();
		}
	private:
		deque<int> queue;
	};
	//��������
	class MyStack1 {
	public:
		/** Initialize your data structure here. */
		MyStack1() {
		}
		/** Push element x onto stack. */
		void push(int x) {
			que1.push(x);
		}
		/** Removes the element on top of the stack and returns that element. */
		int pop() {
			while (que1.size() != 1) {
				if (!que1.empty()) {
					int num = que1.front();
					que1.pop();
					que2.push(num);
				}
				else break;
			}
			if (que1.size() == 1) {
				int num = que1.front();
				que1.pop();
				queue<int> temp = que1;//������ַ
				que1 = que2;
				que2 = temp;
				return num;
			}
			else return -1;
		}

		/** Get the top element. */
		int top() {
			if (!que1.empty()) return que1.back();
			else return -1;
		}

		/** Returns whether the stack is empty. */
		bool empty() {
			return que1.empty();
		}
	private:
		queue<int> que1;
		queue<int> que2;
	};
	//һ������
	class MyStack2 {
	public:
		/** Initialize your data structure here. */
		MyStack2() {
			//������ʵ��
		}
		/** Push element x onto stack. */
		void push(int x) {
			que1.push(x);
			while (x != que1.front()) {//��ת����
				int temp = que1.front();
				que1.pop();
				que1.push(temp);
			}
		}
		/** Removes the element on top of the stack and returns that element. */
		int pop() {
			if (!que1.empty()) {
				int num = que1.front();
				que1.pop();
				return num;
			}
			else return -1;
		}
		/** Get the top element. */
		int top() {
			if (!que1.empty()) return que1.front();
			else return -1;
		}
		/** Returns whether the stack is empty. */
		bool empty() {
			return que1.empty();
		}
	private:
		queue<int> que1;
	};
}