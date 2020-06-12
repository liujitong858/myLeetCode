#include<vector>
#include<algorithm>
using namespace std;
namespace leetcodee15 {
	class Solution {
	public:
		//˫ָ��ⷨ
		//O��n)
		vector<vector<int>> threeSum(vector<int>& nums) {
			if (nums.size() < 3) return vector<vector<int>>();
			vector<vector<int>> res;
			sort(nums.begin(), nums.end());
			int length = nums.size();
			int i = 0;
			int j = 0;
			int k = length - 1;
			for (int i = 0; i < length - 2; ++i) {//ע����length-2
				//if (i > 0 && nums[i] == nums[i - 1]) continue;//ȥ�ط�������Ҳ�ǿ��Ե�
				if (nums[i] > 0) break;//��һ���ܹؼ�
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
						while (j < k&&nums[j] == _curJ) ++j;//ȥ��   
						while (j < k&&nums[k] == _curK)--k;//ȥ��   
					}
					while (i + 1 < length - 2 && nums[i] == nums[i + 1]) ++i;//ȥ��   
				}
			}
			return res;
		}
	};
}