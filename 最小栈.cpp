#include<stack>
using namespace std;
namespace leetcode155 {
	//双栈解法
	class MinStack {
	public:
		/** initialize your data structure here. */
		MinStack() {

		}
		void push(int x) {
			minStack.push(x);
			if (supStack.empty() || x < supStack.top()) supStack.push(x);
			else supStack.push(supStack.top());
		}
		void pop() {
			minStack.pop();
			supStack.pop();
		}
		int top() {
			return minStack.top();
		}
		int getMin() {
			return supStack.top();
		}
	private:
		stack<int> minStack;
		stack<int> supStack;
	};
	class MinStack1 {
	public:
		/** initialize your data structure here. */
		MinStack1() {

		}
		//push的时候判断是否更新Minvalue
		void push(int x) {
			if (minStack.empty()|| x < minValue)
			{
				minValue = x;
			}
			minStack.push(make_pair(x, minValue));
		}
		//弹出之后，最小元素需要更新
		void pop() {
			minStack.pop();
			if (minStack.empty()) {
				minValue = INT_MAX;
			}
			else {
				minValue = minStack.top().second;
			}
		}
		int top() {
			return minStack.top().first;
		}
		int getMin() {
			return minStack.top().second;
		}
	private:
		stack<pair<int,int>> minStack;
		int minValue = INT_MAX;
	};
}