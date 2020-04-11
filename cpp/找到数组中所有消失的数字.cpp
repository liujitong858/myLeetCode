#include<vector>
using namespace std;
namespace leetcode448 {
	class Solution {
	public:
		//不允许使用额外空间的意思就是不让你使用哈希表
		//尽管有两层循环，但是每个数字最多只要交换两次就能找到属于它的位置
		//注意：将重复出现的位置置-1.的效率比重复位置不操作要快，亲测。
		//如果是不操作的话。 最后一个for循环只需要判断nums[i] ！= i+1 ,push_back(i+1)
		vector<int> findDisappearedNumbers(vector<int>& nums) {
			vector<int> res;
			for (int i = 0; i < (int)nums.size(); ++i) {
				while (nums[i] != i + 1 && nums[i] != -1) {
					if (nums[nums[i] - 1] != nums[i]) {
						swap(nums[i], nums[nums[i] - 1]);
					}
					else {
						nums[i] = -1;
						break;
					}
				}
			}
			for (int i = 0; i < (int)nums.size(); ++i) {
				if (nums[i] == -1)res.push_back(i + 1);
			}
			return res;
		}
		//将所有正数作为数组下标，置对应数组值为负值。那么，仍为正数的位置即为（未出现过）消失的数字
		vector<int> findDisappearedNumbers1(vector<int>& nums) {
			for (int i = 0; i < nums.size(); ++i)
				nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
			vector<int> res;
			for (int i = 0; i < nums.size(); ++i) {
				if (nums[i] > 0)
					res.push_back(i + 1);
			}
			return res;
		}
	};
}