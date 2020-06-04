#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
namespace leetcode84 {
	class Solution {
	public:
		//�����ⷨ����ʱ������
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
		//����ջ
		//ʱ�临�Ӷ�O(n)
		//�ռ临�Ӷ�O(n)
		
		int largestRectangleArea1(vector<int>& heights) {
			if (heights.empty()) return 0;
			int length = (int)heights.size();
			int maxArea = 0;
			stack<int> sta;
			for (int i = 0; i < length; ++i) {
				while (!sta.empty() && heights[sta.top()] > heights[i]) {
					int curHeight = heights[sta.top()];
					sta.pop();
					int width = i;//���ջΪ�յĻ���˵����߽����һֱ������ࡣ
					if (!sta.empty()) {
						width = i - sta.top() - 1;//sta.top()����߽�
					}
					maxArea = max(maxArea, curHeight*width);
				}
				sta.push(i);
			}
			while (!sta.empty()) {
				int curHeight = heights[sta.top()];
				sta.pop();
				int width = length;//���ֻ��һ��Ԫ����
				if (!sta.empty()) {
					width = length - sta.top() - 1;
				}
				maxArea = max(maxArea, curHeight*width);
			}
			return maxArea;
		}
		//���´��� ��Ҫ������������������
		//��ջ��ʱ��ջΪ�գ�
		//��������Ժ�ջ�л���Ԫ�أ�
		//Ϊ�˿������ǿ�����������������˼��������߶�Ϊ 0 �����Σ����Իر����������ַ������ۡ�
		//������վ�����ߵ�������һ������������ʣ������ڱ���Sentinel����
		//�������������Σ�
		//��ߵ����Σ��� 1 �����Σ�������һ���������������κ�һ��Ԫ��С�����϶������ջ�����ջһ������Ϊ�գ�
		//�ұߵ����Σ��� 2 �����Σ�Ҳ������Ϊ��һ���������������κ�һ��Ԫ��С�����������������������Ԫ�س�ջ���� 1 ���ڱ�Ԫ�س��⣩��
		//����ջ��Ӧ���߶ȣ��ʵ������Ӳ�������̬����˳�Ϊ����ջ��Monotone Stack����
		//���Ǳ����ⷨ���Ż�������ÿ�����εĸ߶ȶ�Ӧ�������ε�˳���ɳ�ջ˳�������
	};
}