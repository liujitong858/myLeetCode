#include<unordered_map>
#include<string>
using namespace std;
namespace leetcode76 {
	class Solution {
	public:
		//labuladong �Ļ�������ģ��
		string minWindow(string s, string t) {
			if (s.size() < t.size()) return "";
			unordered_map<char, int> need, window;
			for (auto ch : t) {
				need[ch]++;
			}
			int left = 0;
			int right = 0;
			int vaild = 0;
			// ��¼��С�����Ӵ�����ʼ����������
			int start = 0, len = INT_MAX;
			while (right < s.size()) {
				char ch = s[right];//�������봰�ڵ��ַ�
				++right;
				if (need.count(ch)) {
					window[ch]++;
					if (need[ch] == window[ch]) vaild++;
				}

				while (vaild == need.size()) {
					// �����������С�����Ӵ�
					if (right - left < len) {
						start = left;
						len = right - left;
					}
					char char_ = s[left];//�����Ƴ����ڵ��ַ�
					left++;
					if (need.count(char_)) {
						if (need[char_] == window[char_]) vaild--;
						window[char_]--;
					}
				}
			}
			return len == INT_MAX ? "" : s.substr(start, len);
		}
	};
}