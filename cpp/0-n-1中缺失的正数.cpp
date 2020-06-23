#include<vector>
using namespace std;
namespace offer53 {
	class Solution {
		//双100%：只要比较数组下标和该下标对应的值即可，再排除缺失0和缺失最后一项两个特殊情况。
		 int missingNumber(vector<int>& nums) {
			if (nums[0] == 1) return 0;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] != i) return i;
			}
			return nums.size();//这里注意，如果全都没有找到，输出最后n
		}
		 //排序数组中的搜索问题，首先想到二分法解决。”get一项新技能
		 //跳出时，变量 i 和 j 分别指向 “右子数组的首位元素” 。因此返回 i 即可。
		 int missingNumber1(vector<int>& nums) {
			 int left = 0;
			 int right = nums.size();
			 int middle = 0;
			 while (left < right) {
				 middle = left + (right - left) / 2;
				 if (nums[middle] == middle) {//说明缺失的数字在右侧
					 left = middle + 1;
				 }
				 else right = middle ;
			 }
			 return left;
		 }
	};
}

