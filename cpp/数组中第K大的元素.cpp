#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
namespace leetcode215 {
	class Solution {
	public:
		//排序之后再找的方法
		int findKthLargest(vector<int>& nums, int k) {
			if (nums.empty() || nums.size() < k) return -1;
			sort(nums.begin(), nums.end());
			for (int i = nums.size() - 1; i >= 0; --i) {
				if (i + k == nums.size()) return nums[i];
				else continue;
			}
			return -1;
		}

		//使用自定义的快速排序
		//但是这样会出现一种问题
		////因为不加随机，当测试用例是近乎有序的情况，
        //递归树会退化成链表，时间复杂度从O(NlogN)变成O(N^2)
		int findKthLargest1(vector<int>& nums, int k) {
			if (nums.empty() || nums.size() < k) return -1;
			int start = 0;
			int end = nums.size()-1;
			int index = partition(nums, start, end);
			int maxkIndex = nums.size() - k-1;//排序后，第K大元素的索引
			while (index != maxkIndex) {
				if (index < maxkIndex) start = index + 1;
				else end = index - 1;
				partition(nums, start, end);
			}
			return nums[index];
		}
		int partition(vector<int>& nums, int low, int high) {
			//swap(nums[low], nums[low + rand() % (high - low + 1)]);
			//上面那一句是为了防止递归树退化成链表
			int left = low;
			int base = nums[low];
			while (low < high) {
				while (low < high&&nums[high] >= base) {
					--high;
				}
				while (low < high&&nums[low] <= base) {
					++low;
				}
				if (low < high) {
					swap(nums[low], nums[high]);
				}
			}
			nums[left] = nums[low];
			nums[low] = base;
			return low;
		}

		int findKthLargest2(vector<int>& nums, int k) {
			if (nums.empty() || nums.size() < k) return -1;
			priority_queue<int, vector<int>, greater<int>> heap;
			for (int i = 0; i < k; ++i) {
				heap.push(nums[i]);
			}
			for (int i = k; i < nums.size() - 1; ++i) {
				if (nums[i] > heap.top()) {
					heap.pop();
					heap.push(nums[i]);
				}
			}
			return heap.top();
		}
		//优化成一个循环也可以
		//for(int i=0;i<nums.size();++i){
		//smallHeap.push(nums[i]);
		//if (smallHeap.size() > k) {
		//	smallHeap.pop();//一定是最小的，因为优先队列自动排序
		//}
	};
}