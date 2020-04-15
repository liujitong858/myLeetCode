#include<vector>
using namespace std;
namespace leetcode78 {
	class Solution {
	public:
		vector<vector<int>> res;
		//用一个参数index控制输出范围。
		//回溯模板（简介版本）推荐
		//result = []
		//def backtrack(路径, 选择列表) :
		//	if 满足结束条件 :
		//		result.add(路径)
		//		return
		//		for 选择 in 选择列表 :
		//做选择
		//	backtrack(路径, 选择列表)
		//	撤销选择
		vector<vector<int>> subsets(vector<int>& nums) {
			// 记录走过的路径
			vector<int> track;
			backtrack(nums, 0, track);
			return res;
		}
		void backtrack(vector<int>& nums, int start, vector<int>& track) {
			res.push_back(track);
			// 注意 i 从 start 开始递增
			for (int i = start; i < nums.size(); i++) {
				// 做选择
				track.push_back(nums[i]);
				// 回溯
				backtrack(nums, i + 1, track);//一定记住这里是传播i
				// 撤销选择					   //拿1.3.3做例子
				track.pop_back();
			}
		}

		//位运算
		//集合的每个元素，都有可以选或不选，用二进制和位运算，可以很好的表示。
		vector<vector<int>> subsets1(vector<int>& nums) {
			int S = nums.size();
			int N = 1 << S;//组合个数=位数*2 
			vector<vector<int> > res;
			for (int i = 0; i < N; ++i) {
				vector<int> v;
				for (int j = 0; j < S; ++j)	{
					if (i & (1 << j)) v.push_back(nums[j]);
				}	
				res.push_back(v);
			}
			return res;
		
		}
		//考虑层序遍历求解，每次加入一个元素就扩充res的长度，直到所有元素添加完毕
		//每次复制当前res中所有vector,并对其加入新的元素
		//以此扩充res的长度
		vector<vector<int>> subsets2(vector<int>& nums) {
			vector<vector<int> > res(1);//构造一个空的
			for (int i = 0; i < nums.size(); i++) {
				int cnt = res.size();
				for (int j = 0; j < cnt; j++) {
					vector<int> tmp = res[j];
					tmp.push_back(nums[i]);
					res.push_back(tmp);
				}
			}
			return res;
		}
	};
}