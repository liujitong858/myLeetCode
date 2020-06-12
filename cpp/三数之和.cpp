#include<vector>
#include<algorithm>
using namespace std;
namespace leetcodee15 {
	class Solution {
	public:
		//双指针解法
		//O（n)
		vector<vector<int>> threeSum(vector<int>& nums) {
			if (nums.size() < 3) return vector<vector<int>>();
			vector<vector<int>> res;
			sort(nums.begin(), nums.end());
			int length = nums.size();
			int i = 0;
			int j = 0;
			int k = length - 1;
			for (int i = 0; i < length - 2; ++i) {//注意是length-2
				//if (i > 0 && nums[i] == nums[i - 1]) continue;//去重放在这里也是可以的
				if (nums[i] > 0) break;//这一步很关键
				j = i + 1;
				k = length - 1;
				while (j < k) {
					int sum = nums[j] + nums[k];
					if (sum < -nums[i]) ++j;
					else if (sum > -nums[i])--k;
					else {
						vector<int> vec{ nums[i],nums[j],nums[k] };
						res.push_back(vec);
						int _curJ = nums[j];
						int _curK = nums[k];
						while (j < k&&nums[j] == _curJ) ++j;//去重   
						while (j < k&&nums[k] == _curK)--k;//去重   
					}
					while (i + 1 < length - 2 && nums[i] == nums[i + 1]) ++i;//去重   
				}
			}
			return res;
		}
	};
}