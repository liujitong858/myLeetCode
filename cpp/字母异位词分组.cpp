#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
namespace leetcode49 {
	class Solution {
	public:
		//1、准备一个临时vector<string>，里面的元素都是sort之后的string
		//2、准备一个哈希表，key是sort之后的元素，content是vector
		//3、因为临时vector和原来strs的元素索引一一对应，所以遍历一遍vector，就可以填充好哈希表
		//4、最后遍历哈希表即可，有几个数组就有几个键值对；
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			if (strs.empty()) return vector<vector<string>>();
			vector<vector<string>> res;
			unordered_map<string, vector<string>> hash;
			vector<string> copy_strs(strs);
			for (int i = 0; i < strs.size(); ++i) {
				sort(copy_strs[i].begin(), copy_strs[i].end());
			}
			for (int i = 0; i < strs.size(); ++i) {
				hash[copy_strs[i]].push_back(strs[i]);
			}
			for (auto a : hash) {
				res.push_back(a.second);
			}
			return res;
		}
	};
}