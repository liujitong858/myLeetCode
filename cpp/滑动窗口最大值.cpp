#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
namespace leetcode239 {
	class Solution {
	public:
		//超出时间限制
		vector<int> maxSlidingWindow(vector<int>& nums, int k) {
			if (nums.empty() || k > (int)nums.size()) return vector<int>();
			vector<int> res;
			vector<int>::iterator it = nums.begin();
			for (; it <= nums.end() - k; ++it) {
				int tempMax = *max_element(it, it + k);
				res.push_back(tempMax);
			}
			return res;
		}
		vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
			if (nums.empty() || k > (int)nums.size()) return vector<int>();
			deque<int> index;
			vector<int> res;
			for (unsigned int i = 0; i < k; ++i) {
				while (!index.empty() && nums[i] >= nums[index.back()]) {
					index.pop_back();
				}
				index.push_back(i);
			}
			for (unsigned int i = k; i < nums.size(); ++i) {
				res.push_back(nums[index.front()]);
				while (!index.empty() && nums[i] >= nums[index.back()]) {
					index.pop_back();
				}
				if (!index.empty() && index.front() <= (int)(i - k)) {
					index.pop_front();
				}
				index.push_back(i);
			}
			res.push_back(nums[index.front()]);
			return res;
		}
	};
	class MonotonicQueue {
	private:
		deque<int> data;
	public:
		void push(int n) {
			while (!data.empty() && data.back() < n)
				data.pop_back();
			data.push_back(n);
		}

		int max() { return data.front(); }

		void pop(int n) {
			if (!data.empty() && data.front() == n)
				data.pop_front();
		}
	};

	vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
		MonotonicQueue window;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			if (i < k - 1) { //先填满窗口的前 k - 1
				window.push(nums[i]);
			}
			else { // 窗口向前滑动
				window.push(nums[i]);
				res.push_back(window.max());
				window.pop(nums[i - k + 1]);
			}
		}
		return res;
	}

	vector<int> maxSlidingWindow3(vector<int>& nums, int k) {
		vector<int> res;
		deque<int> deq;
		for (int i = 0; i < (int)nums.size(); ++i) {
			if (!deq.empty() && deq.front() == i - k) {
				deq.pop_front();
			}
			while (!deq.empty() && nums[i] > nums[deq.back()]) {
				deq.pop_back();
			}
			deq.push_back(i);
			if (i >= k - 1) res.push_back(nums[deq.front()]);
		}
		return res;
	}
}