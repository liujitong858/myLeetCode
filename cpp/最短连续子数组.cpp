#include<vector>
#include <algorithm>
using namespace std;
namespace leetcode581{
	class Solution {
	public:
		//307个测试样例可以通过，但是超时
		int findUnsortedSubarray(vector<int>& nums) {
			if (nums.empty() || nums.size() == 1)return 0;
			//排序不是关键
			//关键是找到连续子数组
			int start = 0;
			int end = nums.size() - 1;
			vector<int>::iterator _begin = nums.begin();
			vector<int>::iterator _end = nums.end();
			while (end > 0 && nums[end] == *max_element(_begin, _end))
			{
				--end;
				--_end;
			}
			if (end == 0) return 0;//说明原来就是排序的
			while (start < nums.size() - 1 && nums[start] == *min_element(_begin, _end))
			{
				++start;
				++_begin;
			}
			return end - start + 1;
		}
		//从左到右循环，记录最大值为 max，若 nums[i] < max, 
		//则表明位置 i 需要调整, 循环结束，记录需要调整的最大位置 i 为 high;
		//同理，从右到左循环，记录最小值为 min, 若 nums[i] > min, 
		//则表明位置 i 需要调整，循环结束，记录需要调整的最小位置 i 为 low.
		int findUnsortedSubarray1(vector<int>& nums) {
			if (nums.empty() || nums.size() == 1)return 0;
			int _Max = nums[0];
			int _Min = nums[nums.size() - 1];
			int high = -2;//结束值赋为-2是考虑在数组本身就是有序时,return也可以给出正确值
			int low = -1;
			int pos = 0;//与i对应的索引
			for (int i = 0; i < (int)nums.size(); ++i)
			{
				pos = (int)nums.size() - i - 1;
				if (nums[i] < _Max) high = i;
				else  _Max = nums[i];
	
				if (nums[pos] > _Min) low = pos;
				else _Min = nums[pos];
			}
			//返回开始和结束的索引差
			return high - low + 1;
		}
		//拷贝数组然后对比
		int findUnsortedSubarray2(vector<int>& nums) {
			if (nums.empty() || nums.size() == 1)return 0;
			vector<int >copynums(nums);
			sort(copynums.begin(), copynums.end());
			int start = -1;
			int end = -2;//保证，如果没有区别的情况下也能正常输出
			int pos = 0;
			int size = (int)nums.size();
			for (int i = 0; i < size; ++i)
			{
				pos = size - 1 - i;
				if (start == -1 && nums[i] != copynums[i])
				{
					start = i;
				}
				if (end == -2 && nums[pos] != copynums[pos])
				{
					end = pos;
				}
				if (start != -1 && end != -2)break;
			}
			return end - start + 1;
		}
	};
}