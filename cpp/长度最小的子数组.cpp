#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode209 {
	class Solution {
	public:
		//ʱ�临�Ӷȣ�O(n)
		//��������
		//��˫ָ��
		int minSubArrayLen(int s, vector<int>& nums) {
			if (nums.empty()) return 0;
			int cur = 0;
			int minLength = INT_MAX;
			int left = 0;
			for (int i = 0; i < (int)nums.size(); ++i) {
				cur += nums[i];
				while (cur >= s) {
					minLength = min(minLength, i - left + 1);//����
					cur -= nums[left];
					++left;
				}
			}
			return minLength == INT_MAX ? 0 : minLength;
		}
	};
}