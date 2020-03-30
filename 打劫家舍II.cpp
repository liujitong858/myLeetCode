#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode213 {
	class Solution {
	public:
		//��ʵ���ǰѻ�����������У�һ���Ǵ�0��n - 1����һ���Ǵ�1��n��Ȼ�󷵻�����������ġ�
		int rob(vector<int>& nums) {
			if (nums.empty()) return 0;
			if ((int)nums.size() == 1) return nums[0];
			if ((int)nums.size() == 2) return max(nums[0], nums[1]);
			if ((int)nums.size() == 3) return max(nums[0], max(nums[1], nums[2]));
			vector<int> dp((int)nums.size());
			//���㲻����βԪ�ص����ֵ
			dp[0] = nums[0];
			dp[1] = max(nums[0], nums[1]);
			for (int i = 2; i < (int)nums.size() - 1; ++i)
			{
				dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
			}
			int maxSum[2] = { 0,0 };
			maxSum[0] = dp[(int)nums.size() - 2];
			//���㲻����ͷԪ�ص����ֵ
			dp[1] = nums[1];
			dp[2] = max(nums[1], nums[2]);
			for (int i = 3; i < (int)nums.size(); ++i)
			{
				dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
			}
			maxSum[1] = dp[(int)nums.size() - 1];
			return max(maxSum[0], maxSum[1]);

		}
	};

}