#include<vector>
#include<queue>
using namespace std;
namespace leetcode40 {
	class Solution {
	public:
		//利用快速排序的思想，修改原来的数组   平均时间复杂度O(n)
		vector<int> getLeastNumbers(vector<int>& arr, int k) {
			if (arr.empty() || k <= 0)return vector<int>();
			int start = 0;
			int end = (int)arr.size() - 1;
			int index = Partition(arr, start, end);
			vector<int> res;
			while (index != k - 1) {
				if (index > k - 1) {
					end = index - 1;
					index = Partition(arr, start, end);
				}
				else if (index < k - 1) {
					start = index + 1;
					index = Partition(arr, start, end);
				}
			}
			for (int i = 0; i < k; ++i) {
				res.push_back(arr[i]);
			}
			return res;
		}
		int Partition(vector<int>& arr, int low, int high) {
			int base = arr[low];
			int left = low;
			while (low < high)
			{
				while (low < high&&arr[high] >=base) {
					--high;
				}
				while (low < high&&arr[low] <=base) {
					++low;
				}
				if (low < high) {
					int temp = arr[high];
					arr[high] = arr[low];
					arr[low] = temp;
				}
			}
			arr[left] = arr[low];
			arr[low] = base;
			return low;
		}

		//时间 O(nlogk) 最多需要插入n次，每次插入要对k个数进行维护
		//空间 O(k) 堆上最多k个
		//利用最大堆的思想，没有修改原来的数组，比较适合处理海量数据
		//堆排序
		vector<int> getLeastNumbers1(vector<int>& arr, int k) {
			if (arr.empty() || k <= 0)return vector<int>();
			vector<int> res(k,0);
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
		//下面两种方法是利用STL中的partial_sort 实际上也是heap_sort
		vector<int> getLeastNumbers2(vector<int>& arr, int k) {
			if (arr.empty() || k <= 0)return vector<int>();
			partial_sort(arr.begin(), arr.begin() + k, arr.end());
			vector<int> res(arr.begin(), arr.begin() + k);
			return res;
		}

		vector<int> getLeastNumbers3(vector<int>& arr, int k) {
			if (arr.empty() || k <= 0)return vector<int>();
			vector<int> res(k);
			partial_sort_copy(arr.begin(), arr.end(), res.begin(), res.end());
			return res;
		}
	};
}
