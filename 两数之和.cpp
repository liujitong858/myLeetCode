#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
namespace leetcode1 {
	//ʧ�ܰ�������Ҫ�ο�
	vector<int> twoSum(vector<int>& nums, int target) {
		if (nums.empty() || nums.size() < 2)return vector<int>();
		unordered_map<int, int> hash;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (hash.find(nums[i]) == hash.end())hash[nums[i]] = i;
			else hash[-nums[i]] = i;//����0զ����
		}
		sort(nums.begin(), nums.end());//�����±������
		int start = 0;
		int end = (int)nums.size() - 1;
		while (nums[start] + nums[end] != target && start < end)
		{
			if (nums[start] + nums[end] > target) --end;
			else ++start;
		}
		vector<int> res;
		if (nums[start] == nums[end]) {
			res.push_back(hash[nums[start]]);
			res.push_back(hash[-nums[start]]);
		}
		else {
			res.push_back(hash[nums[start]]);
			res.push_back(hash[nums[end]]);
		}
		return res;
	}
	//�����ⷨ
	vector<int> twoSum1(vector<int>& nums, int target) {
		if (nums.empty() || nums.size() < 2)return vector<int>();
		int i = 0;
		int j = 0;
		for (int i = 0; i < (int)nums.size() - 1; ++i)
		{
			for (int j = i + 1; j < (int)nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target) return {i,j};//vector���б��ʼ��
			}
		}
		return {};//vector���б��ʼ�������Լ򻯴���
	}
	//�������ι�ϣ��
	vector<int> twoSum2(vector<int>& nums, int target) {
		if (nums.empty() || nums.size() < 2)return vector<int>();
		unordered_map<int, int> hash;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			hash[nums[i]]=i;
		}
		for (int j = 0; j < (int)nums.size(); ++j)
		{
			if (hash.find(target - nums[j]) != hash.end() && hash[target - nums[j]] != j)
			{
				return { j , hash[target - nums[j]] };
			}
		}
		return {};
	}
	//����һ�ι�ϣ��
	vector<int> twoSum3(vector<int>& nums, int target) {
		if (nums.empty() || nums.size() < 2)return vector<int>();
		unordered_map<int, int> hash;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (hash.find(target - nums[i]) != hash.end())
			{
				return { hash[target - nums[i]] ,i };  //��ΪiΪ�ϴ��Ԫ�أ���ʱ����ӵļ�ֵ����С��i������i�ں���
			}										   //��324 303�ֱ����
			hash[nums[i]] = i;
		}
		return {};
	}


}