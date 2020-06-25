#include<vector>
#include<queue>
using namespace std;
namespace heapsort {
		//时间 O(nlogk) 最多需要插入n次，每次插入要对k个数进行维护
		//空间 O(k) 堆上最多k个
		//利用最大堆的思想，没有修改原来的数组，比较适合处理海量数据
		//堆排序
		//求k个最小用 最大堆	less<int>
		//求k个最大用 最小堆 greater<int>
	vector<int> getLeastNumbers1(vector<int>& arr, int k) {
		if (arr.empty() || k <= 0)return vector<int>();
		vector<int> res(k, 0);
		priority_queue<int> bigHeap;//默认建立最大堆
		//priority_queue <int, vector<int>, less<int> 正常定义
		for (int i = 0; i < k; ++i) {
			bigHeap.push(arr[i]);
		}
		for (int i = k; i < (int)arr.size(); ++i) {
			if (bigHeap.top() > arr[i]) {
				bigHeap.pop();
				bigHeap.push(arr[i]);
			}
		}
		for (int i = 0; i < k; ++i) {
			res[i] = bigHeap.top();
			bigHeap.pop();
		}
		return res;
	}
	void adjust(vector<int>& nums, int len, int index)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		int maxIndex = index;
		if (left<len&&nums[left]>nums[maxIndex]) maxIndex = left;
		if (right<len&&nums[right]>nums[maxIndex]) maxIndex = right; // maxIdx是3个数中最大数的下标
		if (maxIndex != index)//maxIndex的值有更新的话
			if (maxIndex != index)                 // 如果maxIdx的值有更新
			{
				swap(nums[maxIndex], nums[index]);
				adjust(nums, len, maxIndex);       // 递归调整其他不满足堆性质的部分
			}
	}
	//手写堆排序
	void heapSort(vector<int>& nums, int size)
	{
		for (int i = size / 2 - 1; i >= 0; i--)  // 对每一个非叶结点进行堆调整(从最后一个非叶结点开始)
		{
			adjust(nums, size, i);
		}
		for (int i = size - 1; i >= 1; i--)
		{
			swap(nums[0], nums[i]);           // 将当前最大的放置到数组末尾
			adjust(nums, i, 0);              // 将未完成排序的部分继续进行堆排序
		}
	}
	
}