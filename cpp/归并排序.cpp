#include<vector>
using namespace std;
namespace mergesort {
	void mergeSort_helper(vector<int>& nums, int low, int high) {
		vector<int> temp(high - low + 1);
		if (low >= high) return;
		int mid = (low + high) / 2;
		mergeSort_helper(nums, low, mid);
		mergeSort_helper(nums, mid + 1, high);
		int i = low;
		int j = mid + 1;
		int index = 0;
		while (i <= mid && j <= high) {
			if (nums[i] < nums[j]) {
				temp[index++] = nums[i++];
			}
			else temp[index++] = nums[j++];
		}
		while (i <= mid) {
			temp[index++] = nums[i++];
		}
		while (j <= high) {
			temp[index++] = nums[j++];
		}
		for (int i = 0; i < high - low + 1; ++i) {
			nums[i + low] = temp[i];
		}
	}
	void mergeSort(vector<int>& nums) {
		mergeSort_helper(nums, 0, nums.size() - 1);
	}
	
}