#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
namespace leetcode49 {
	class Solution {
	public:
		//1��׼��һ����ʱvector<string>�������Ԫ�ض���sort֮���string
		//2��׼��һ����ϣ��key��sort֮���Ԫ�أ�content��vector
		//3����Ϊ��ʱvector��ԭ��strs��Ԫ������һһ��Ӧ�����Ա���һ��vector���Ϳ������ù�ϣ��
		//4����������ϣ���ɣ��м���������м�����ֵ�ԣ�
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