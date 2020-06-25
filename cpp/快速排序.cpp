#include<vector>
using namespace std;
namespace sort {
	int Partition(vector<int>& nums, int low, int high) {
		int base = nums[low];//保存最左侧的值
		int left = low;
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

	void Quick_sort(vector<int>& nums,int start,int end) {
		if (start < end) {
			int base= Partition(nums, start, end);
			Quick_sort(nums, start, base - 1);
			Quick_sort(nums, base + 1, end);
		}
	}
}