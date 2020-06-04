#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode406 {
	class Solution {
	public:
		//50% 100%
		//先排序
		//先对输入数组排序，h升序，k降序 从头循环遍历
		//当前这个人就是剩下未安排的人中最矮的人，
		//他的k值就代表他在剩余空位的索引值 
		//如果有多个人高度相同，要按照k值从大到小领取索引值 示例：
		//  [0, 1, 2, 3, 4, 5] [4, 4] 4
		//	[0, 1, 2, 3, 5]    [5, 2] 2
		//	[0, 1, 3, 5]       [5, 0] 0
		//	[1, 3, 5]          [6, 1] 3
		//	[1, 5]             [7, 1] 5
		//	[1]                [7, 0] 1
		//	[[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
		vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
			if (people.empty() || people.size() == 1) return people;
			int length = (int)people.size();
			vector<vector<int>> res(length, { -1,-1 });
			for (int i = 0; i < length - 1; ++i) {
				for (int j = length - 2; j >= i; j--) {
					if (people[j][0] > people[j + 1][0]) {
						swap(people[j], people[j + 1]);
					}
					else if (people[j][0] == people[j + 1][0]) {
						if (people[j][1] < people[j + 1][1]) {
							swap(people[j], people[j + 1]);
						}
					}
				}
			}
			for (int i = 0; i < length; ++i) {
				int count = people[i][1] + 1;//索引;
				for (int j = 0; j < length; ++j) {
					if (res[j][0] == -1) {
						if (--count <= 0) {
							res[j] = people[i];
							break;
						}
					}
				}
			}
			return res;
		}
		vector<vector<int>> reconstructQueue1(vector<vector<int>>& people) {
			// 先排序
		   // [7,0], [7,1], [6,1], [5,0], [5,2], [4,4]

		   // 再一个一个插入。
		   // [7,0]
		   // [7,0], [7,1]
		   // [7,0], [6,1], [7,1]
		   // [5,0], [7,0], [6,1], [7,1]
		   // [5,0], [7,0], [5,2], [6,1], [7,1]
		   // [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]
			/*auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
				return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] > v2[0];
			};
			sort(people.begin(), people.end(), cmp);*/

			vector<vector<int>> res;
			sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
				if (a[0] > b[0])return true;
				if (a[0] == b[0] && a[1] < b[1]) return true;
				return false;
			});
			
			for (auto e : people) {
				res.insert(res.begin() + e[1], e);
			}
			return res;
		}
	};
}