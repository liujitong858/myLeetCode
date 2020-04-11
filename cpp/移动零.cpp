#include<vector>
using namespace std;
namespace leetcode283 {
	class Solution {
	public:
		void moveZeroes(vector<int>& nums) {
			//1、如果可以拷贝其他数组的话，可以把非0放到一个数组，然后遍历原素组,0加到新数组后面
			//2、可以扫描，扫描到0，erase，同时记录次数，最后把0push_back
			if (nums.empty()) return;
			int countOf0 = 0;
			for (auto iter = nums.begin(); iter != nums.end();)	{
				if (*iter == 0)	{	
					iter = nums.erase(iter);
					++countOf0;
				}
				else ++iter;
			}
			for (int i = 0; i < countOf0; ++i){
				nums.push_back(0);
			}
		}
		//扫描到非0的元素直接放到最前面，然后记录一下最后一个非零元素的位置
		//再次遍历，将从非零元素下一位一直到数组容量大小的全部变为0
		//  这是双指针的方法。由变量 “cur” 表示的快速指针负责处理新元素。
		//	如果新找到的元素不是 0，我们就在最后找到的非 0 元素之后记录它。
		//	最后找到的非 0 元素的位置由慢指针 “lastnonzerofoundat” 变量表示
		//	。当我们不断发现新的非 0 元素时，我们只是在 “lastnonzerofoundat + 1” 
		//	第个索引处覆盖它们。此覆盖不会导致任何数据丢失，因为我们已经处理了其中的内容（
		//	如果它是非 0 的，则它现在已经写入了相应的索引，或者如果它是 0，则稍后将进行处理）。
		//	在 “cur” 索引到达数组的末尾之后，我们现在知道所有非 0 元素都已按原始顺序移动到数组的开头。
		//	现在是时候满足其他要求了，“将所有 0 移动到末尾”。
		//	我们现在只需要在 “lastnonzerofoundat” 索引之后用 0 填充所有索引。
		void moveZeroes1(vector<int>& nums) {
			int lastNonZeroFoundAt = 0;
			for (int cur = 0; cur < nums.size(); cur++) {
				if (nums[cur] != 0) {
					nums[lastNonZeroFoundAt++] = nums[cur];
				}
			}
			for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
				nums[i] = 0;
			}
		}	
		//真正意义上面的双指针，只需要遍历一遍
		//因此，当我们遇到一个非零元素时，
     	//我们需要交换当前指针和慢速指针指向的元素，
     	//然后前进两个指针。如果它是零元素，我们只前进当前指针。
		 void moveZeroes2(vector<int>& nums) {
			for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
				if (nums[cur] != 0) {
					swap(nums[lastNonZeroFoundAt++], nums[cur]);
				}
			}
		}
	};
}





