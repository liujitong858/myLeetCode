using namespace std;
#include<string>
#include <unordered_map>
class Solution {
public:
	//��һ�����Ĵ��У�ֻ�����һ���ַ������������Σ�������ַ�������ż���Ρ�
	//ʹ���˹�ϣ��һ����־λ
	int longestPalindrome(string s) {
		if (s.empty()) return 0;
		int maxCount = 0;
		unordered_map<int, int> hashtable;
		for (auto i = 0; i < s.size(); ++i) {
			hashtable[s[i]]++;
		}
		bool first = true;
		for (auto iter = hashtable.begin(); iter != hashtable.end(); ++iter) {
			if (iter->second % 2 == 0) maxCount += iter->second;
			else {
				if (first) {
					maxCount += iter->second;
					first = false;
				}
				else maxCount += iter->second - 1;
			}
		}
		return maxCount;
	}
	//���Ӽ��İ취
	//ʹ����C++11�� ��foreach�ı�������
	//��������������ȡ���İ취��ͬʱֻҪ�жϺ�Ϊ��ż +1
	int longestPalindrome1(string s) {
		unordered_map<char, int> count;
		int ans = 0;
		for (char c : s)
			++count[c];
		for (auto p : count) {
			int v = p.second;
			ans += v / 2 * 2;				//������ȡ����*2
			if (v % 2 == 1 and ans % 2 == 0)//������������Һ�Ϊż��
				++ans;
		}
		return ans;
	}
};