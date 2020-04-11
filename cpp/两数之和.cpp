#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
namespace leetcode1 {
	//失败案例，不要参考
	vector<int> twoSum(vector<int>& nums, int target) {
		if (nums.empty() || nums.size() < 2)return vector<int>();
		unordered_map<int, int> hash;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (hash.find(nums[i]) == hash.end())hash[nums[i]] = i;
			else hash[-nums[i]] = i;//两个0咋办嘛
		}
		sort(nums.begin(), nums.end());//排序下标就乱了
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
	//暴力解法
	vector<int> twoSum1(vector<int>& nums, int target) {
		if (nums.empty() || nums.size() < 2)return vector<int>();
		int i = 0;
		int j = 0;
		for (int i = 0; i < (int)nums.size() - 1; ++i)
		{
			for (int j = i + 1; j < (int)nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target) return {i,j};//vector的列表初始化
			}
		}
		return {};//vector的列表初始化，可以简化代码
	}
	//遍历二次哈希表
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
	//遍历一次哈希表
	vector<int> twoSum3(vector<int>& nums, int target) {
		if (nums.empty() || nums.size() < 2)return vector<int>();
		unordered_map<int, int> hash;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (hash.find(target - nums[i]) != hash.end())
			{
				return { hash[target - nums[i]] ,i };  //因为i为较大的元素，此时已添加的键值都还小于i，所以i在后面
			}										   //以324 303分别举例
			hash[nums[i]] = i;
		}
		return {};
	}


}