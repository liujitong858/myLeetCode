#include<string>
using namespace std;
namespace leetcode5 {
	class Solution {
	public:
		bool isMatch(string s, string p) {
			if (s.empty() && p.empty()) return true;
			if (!s.empty() && p.empty()) return false;
			int size_s = s.size();
			int size_p = p.size();
			return isMatch_helper(s, p, 0, 0, size_s, size_p);
		}
		bool isMatch_helper(string& s, string& p, int index_s, int index_p, int size_s, int size_p) {
			if (index_s != size_s && index_p >= size_p) return false;
			if (index_s == size_s && index_p == size_p) return true;

			if (p[index_p + 1] != '*') {
				if (p[index_p] == s[index_s] || (p[index_p] == '.'&& index_s != size_s)) {
					return isMatch_helper(s, p, index_s + 1, index_p + 1, size_s, size_p);
				}
				else return false;
			}
			else {
				if (p[index_p] == s[index_s] || (p[index_p] == '.'&& index_s != size_s)) {
					return isMatch_helper(s, p, index_s + 1, index_p, size_s, size_p)//���ܳ���ƥ��0���Ͷ�������/��ab��a*ab��ֻ��Ҫƥ�����
						|| isMatch_helper(s, p, index_s, index_p + 2, size_s, size_p);
				}
				else {//����ȵĻ���ֱ��ƥ�����
					return isMatch_helper(s, p, index_s, index_p + 2, size_s, size_p);
				}
			}
		}
	};
}