#include<vector>
using namespace std;
namespace bubblesort {
	void bubblesort(vector<int>& nums) {
		int size = nums.size() - 1;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; i < size - 1; ++j) {
				if (nums[j] > nums[j + 1]) {
					swap(nums[j], nums[j + 1]);
				}
			}
		}
	}
}