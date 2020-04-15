
#include<vector>
using namespace std;
namespace leetcode77 {
	class Solution {
	public:
		//ʹ���˻���ģ��
		vector<vector<int>> res;
		vector<vector<int>> combine(int n, int k) {
			vector<int> track;
			combine_helper(n, k, track, 1);
			return res;
		}
		//�����ͼ����Ӽ��Ĳ�࣬�������ڣ����� res �ĵط������ĵ׶ˡ�
		void combine_helper(int n, int k, vector<int>& track, int start)
		{
			if (track.size() == k) {
				res.push_back(track);
				return;
			}
			for (int i = start; i <= n; ++i)
			{
				track.push_back(i);
				combine_helper(n, k, track, i + 1);
				track.pop_back();
			}
		}
	};
}