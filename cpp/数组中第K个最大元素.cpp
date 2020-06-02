#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
namespace leetcode215 {
	class Solution {
	public:
		//时间复杂度O(NlogN)，这里 N 是数组的长度，
		//算法的性能消耗主要在排序，JDK 默认使用快速排序，因此时间复杂度为O(NlogN)。
		//空间复杂度：O(1)，这里是原地排序，没有借助额外的辅助空间。
		//调用库函数的笨方法
		int findKthLargest(vector<int>& nums, int k) {
			if (nums.empty() || nums.size() < k) return -1;
			int size = nums.size();
			sort(nums.begin(), nums.end());
			return nums[size - k];
		}
		//时间复杂度: 平均情况O(N)，最坏情况 O(N^2)
		//空间复杂度 : O(1)。
		//快速排序虽然快，但是如果实现得不好，在遇到特殊测试用例的时候，
		//时间复杂度会变得很高。如果你使用 partition 的方法完成这道题，时间排名不太理想，可以考虑一下是什么问题，这个问题很常见。
		int findKthLargest1(vector<int>& nums, int k) {
			if (nums.empty()) return -1;
			int low = 0;
			int high = nums.size() - 1;
			int Kmax = nums.size() - k;//第k大的索引
			int index = _partition1(nums, low, high);
			while (index != Kmax) {
				if (index > Kmax) high = index - 1;
				else low = index + 1;
				index = _partition1(nums, low, high);
			}
			return nums[index];
		}

		int _partition1(vector<int>& vec, int low, int high) {
			//因为不加随机，当测试用例是近乎有序的情况，
			//递归树会退化成链表，时间复杂度从O(NlogN)编程O(N^2)
			swap(vec[low], vec[low + rand() % (high - low + 1)]);
			int base = vec[low];
			int left = low;
			while (low < high) {
				while (low < high&&vec[high] >= base) {
					--high;
				}
				while (low < high&&vec[low] <= base) {
					++low;
				}
				if (low < high) {
					swap(vec[high], vec[low]);
				}
			}
			swap(vec[left], vec[low]);
			return low;
		}
	    //时间复杂度: O(Nlogk)。
		//空间复杂度 :O(k)，用于存储堆元素。
		int findKthLargest2(vector<int>& nums, int k) {
			if (nums.empty()) return -1;
			priority_queue<int, vector<int>, greater<int>> smallHeap;//默认建立小顶堆
			for (int i = 0; i < k; ++i) {
				smallHeap.push(nums[i]);
			}
			for (int i = k; i < nums.size(); ++i) {
				if (smallHeap.top() < nums[i]) {
					smallHeap.pop();
					smallHeap.push(nums[i]);
				}
			}
			return smallHeap.top();
		}
	};
}
