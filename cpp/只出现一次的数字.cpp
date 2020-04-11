#include<vector>
#include<unordered_set>
#include <algorithm>
using namespace std;
namespace leetcode136 {

	class Solution {
	public:
		//û�ж���ռ䣬����ʱ��
		//���ⷨ�Ĺؼ�����ʶ����
		//0���κ������������Ǹ���
		//��ͬ�������������0
		int singleNumber(vector<int>& nums) {
			int res = 0;
			for (int i = 0; i < (int)nums.size(); ++i)
			{
				res ^= nums[i];
			}
			return res;
		}
		//�ж���ռ䡢����ʱ��
		//����unordered_set����unordered_map ����ϣ�������ж�
		int singleNumber1(vector<int>& nums) {
			unordered_set<int> hashtable;
			int ans=0;
			for (auto i : nums) {
				if (hashtable.count(i))   hashtable.erase(i);
				else    hashtable.insert(i);
			}
			for (auto j : hashtable)  ans = j;
			return ans;
		}
		//sort֮�󣬸���������ͬ�����ǰ��ŵģ���һ�������ͬ����-1
		//�ڶ����������-1�ľ��ǽ�����������ڶ���ѭ����û�н����˵��
		//����һ�ε���Ϊ-1
		int singleNumber3(vector<int>& nums) {
			int len = (int)nums.size();
			sort(nums.begin(), nums.end());
			for (int i = 0; i < len - 1; i++)
			{
				if (nums[i] != -1 && nums[i] == nums[i + 1])
				{
					nums[i] = -1;
					nums[i + 1] = -1;
				}
			}
			for (int i = 0; i < len; i++)
			{
				if (nums[i] != -1)
					return nums[i];
			}
			return -1;
		}
	};
}