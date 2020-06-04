#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
namespace leetcode84 {
	class Solution {
	public:
		//暴力解法超出时间限制
		//O(n2)
		int largestRectangleArea(vector<int>& heights) {
			if (heights.empty()) return 0;
			int length = (int)heights.size();
			int maxArea = 0;
			for (int i = 0; i < length; ++i) {
				int left = i;
				int right = i;
				while (left > 0 && heights[left - 1] >= heights[i]) {
					--left;
				}
				while (right < length - 1 && heights[right + 1] >= heights[i]) {
					++right;
				}
				maxArea = max(maxArea, heights[i] * (right - left + 1));
			}
			return maxArea;
		}
		//利用栈
		//时间复杂度O(n)
		//空间复杂度O(n)
		
		int largestRectangleArea1(vector<int>& heights) {
			if (heights.empty()) return 0;
			int length = (int)heights.size();
			int maxArea = 0;
			stack<int> sta;
			for (int i = 0; i < length; ++i) {
				while (!sta.empty() && heights[sta.top()] > heights[i]) {
					int curHeight = heights[sta.top()];
					sta.pop();
					int width = i;//如果栈为空的话，说明左边界就是一直到最左侧。
					if (!sta.empty()) {
						width = i - sta.top() - 1;//sta.top()是左边界
					}
					maxArea = max(maxArea, curHeight*width);
				}
				sta.push(i);
			}
			while (!sta.empty()) {
				int curHeight = heights[sta.top()];
				sta.pop();
				int width = length;//如果只有一个元素了
				if (!sta.empty()) {
					width = length - sta.top() - 1;
				}
				maxArea = max(maxArea, curHeight*width);
			}
			return maxArea;
		}
		//以下代码 需要考虑两种特殊的情况：
		//弹栈的时候，栈为空；
		//遍历完成以后，栈中还有元素；
		//为此可以我们可以在输入数组的两端加上两个高度为 0 的柱形，可以回避上面这两种分类讨论。
		//这两个站在两边的柱形有一个很形象的名词，叫做哨兵（Sentinel）。
		//有了这两个柱形：
		//左边的柱形（第 1 个柱形）由于它一定比输入数组里任何一个元素小，它肯定不会出栈，因此栈一定不会为空；
		//右边的柱形（第 2 个柱形）也正是因为它一定比输入数组里任何一个元素小，它会让所有输入数组里的元素出栈（第 1 个哨兵元素除外）。
		//这里栈对应到高度，呈单调增加不减的形态，因此称为单调栈（Monotone Stack）。
		//它是暴力解法的优化，计算每个柱形的高度对应的最大矩形的顺序由出栈顺序决定。
	};
}