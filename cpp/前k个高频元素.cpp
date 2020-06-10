#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
namespace leetcode347 { 
	//����mapͳ��ÿ�����ֳ��ֵĴ�����������sort����ʱ�临�Ӷ�O(nlogn)
	vector<int> topKFrequent(vector<int>& nums, int k) {
		if (nums.empty() || k > nums.size() || k <= 0) return vector<int>();
		vector<int> res;
		unordered_map<int, int > hashmap;
		for (int i = 0; i < nums.size(); ++i) {
			hashmap[nums[i]]++;
		}
		vector<pair<int, int>> vec(hashmap.begin(),hashmap.end());
		sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second > b.second;});
		for (int i = 0; i < k; ++i) {
			res.push_back(vec[i].first);
		}
		return res;
	}
	//������ͳ��ÿ�����ֳ��ֵĴ������������ȶ��н���С���ѣ�ʱ�临�Ӷ�O(nlogk)
	struct cmp
	{
		bool operator()(pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; }
	};
	vector<int> topKFrequent1(vector<int>& nums, int k) {
		vector<int> res;
		unordered_map<int, int > hashmap;
		for (int i = 0; i < nums.size(); ++i) {
			hashmap[nums[i]]++;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> freq;
		for (auto a : hashmap) {
			freq.push(a);
			if (freq.size() > k)
				freq.pop();
		}
		while (!freq.empty()) {
			res.push_back(freq.top().first);
			freq.pop();
		}
		return res;
	}
}