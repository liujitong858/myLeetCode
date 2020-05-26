#include<vector>
using namespace std;
namespace leetcode287 {
	class Solution {
	public:
		//1、不能更改原数组（假设数组是只读的）；
		//2、只能使用额外的 O(1) 的空间。
		//容易想到的方法有：

		//使用哈希表判重，这违反了限制 2；
		//将原始数组排序，排序以后，重复的数相邻，即找到了重复数，这违反了限制 1；
		//使用类似「力扣」第 41 题：缺失的第一个正数 （原地哈希）的思路，当两个数发现要放在同一个地方的时候，就发现了这个重复的元素，这违反了限制 1；
		//既然要定位数，这个数恰好是一个整数，可以在「整数的有效范围内」做二分查找，但是比较烦的一点是得反复看整个数组好几次，本题解就介绍通过二分法定位一个有范围的整数；
		
		//offer上面的解法
		int findDuplicate(vector<int>& nums) {
			//不可以更改原数组
			//只能使用额外O(1)的空间
			//不可以使用暴力法
			//时间复杂度：O(N \log N)O(NlogN)，二分法的时间复杂度为 O(\log N)O(logN)，
			//在二分法的内部，执行了一次 for 循环，时间复杂度为 O(N)O(N)，故时间复杂度为 O(N \log N)O(NlogN)。

			if (nums.empty()) return -1;
			int start = 1;
			int end = nums.size() - 1;
			while (start <= end) {
				int middle = (end - start) / 2 + start;
				int count = count_helper(nums, start, middle);
				if (start == end) {
					if (count > 1) return start;
					else return -1;
				}
				if (count > middle - start + 1) {//严格大于
					end = middle;
				}
				else start = middle + 1;
			}
			return -1;
		}
		int count_helper(vector<int>& nums, int start, int end) {
			int count = 0;
			for (int i = 0; i < (int)nums.size(); ++i) {
				if (nums[i] >= start && nums[i] <= end) {
					++count;
				}
			}
			return count;
		}

		//还可以使用「快慢指针」来完成
		//1.数组中有一个重复的整数 <= = > 链表中存在环
		//2.找到数组中的重复整数 <= = > 找到链表的环入口
		//142题中慢指针走一步slow = slow.next == > 本题 slow = nums[slow]
		//142题中快指针走两步fast = fast.next.next == > 本题 fast = nums[nums[fast]]

		int findDuplicate1(vector<int>& nums) {
			int slow = 0;
			int fast = 0;
			slow = nums[slow];
			fast = nums[nums[fast]];
			while (slow!=fast){
				slow = nums[slow];
				fast = nums[nums[fast]];
			}
			//此时已经进入环内，但是在环的入口才是重复的数字
			//所以此时应该找环的入口
			//设环的周长是c，起点距离环入口是m
			//设fast和slow相遇的时候，fast走了2n,slow走了n
			//fast,而这n步全用在了在环里循环（n%c==0）。
			//fast和slow相遇时，slow在环中行进的距离是n-m，其中n%c==0。
			//这时我们再让slow前进m步——也就是在环中走了n步了。
			//而n%c==0即slow在环里面走的距离是环的周长的整数倍，就回到了环的入口了，而入口就是重复的数字。
			//我们不知道起点到入口的长度m，所以弄个finder和slow一起走，他们必定会在入口处相遇。
			int slow1 = 0;
			int fast1 = slow;
			while (slow1 != fast1) {
				slow1 = nums[slow1];
				fast1 = nums[nums[fast1]];
			}
			return slow1;
		}
		//原地哈希
		int findDuplicate2(vector<int>& nums) {
			//不可以更改原数组
			//只能使用额外O(1)的空间
			//不可以使用暴力法
			if (nums.empty()) return -1;
			for (int i = 0; i < (int)nums.size(); ++i) {
				while (nums[i] != i) {
					if (nums[i] == nums[nums[i]]) {
						return nums[i];
					}
					int temp = nums[nums[i]];
					nums[nums[i]] = nums[i];
					nums[i] = temp;
				}
			}
			return -1;
		}

	};
}