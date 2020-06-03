#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>
using namespace std;
namespace leetcode3 {
	class Solution {
	public:
		//�Լ��ķ����о���Ժ����һЩ
		//�����ϻ��ǻ�������
		int lengthOfLongestSubstring(string s) {
			if (s.empty()) return 0;
			string res = "";
			int count = 0;
			for (int i = 0; i < s.size(); ++i) {
				int j = res.find(s[i]);
				if (j == -1) {//������s[i]
					res += s[i];
				}
				else {//������ͬ��s[i]
					res.erase(0, j + 1);//��������
					res += s[i];
				}
				count = max(count, (int)res.size());
			}
			return count;
		}
		//ʹ�ù�ϣ����ķ���
		int lengthOfLongestSubstring1(string s) {
			if (s.empty()) return 0;
			vector<int> vec(256, -1); //�ַ���256��
			int left = 0;//���ҵ���߽�
			int maxLength = 0;
			for (int i = 0; i < (int)s.size(); ++i) {
				if (vec[s[i]] != -1 && vec[s[i]] >= left) {
					left = vec[s[i]] + 1;//�����趨��߽�
				}
				else {//����maxLength
					maxLength = max(maxLength, i - left + 1);
				}
				vec[s[i]] = i;//���ַ���λ���趨Ϊ�±�
			}
			return maxLength;
		}
		//Ч�����
		int lengthOfLongestSubstring2(string s) {
			if (s.empty()) return 0;
			unordered_set<char> hashset;
			int left = 0;//���ҵ���߽�
			int maxLength = 0;
			for (int i = 0; i < (int)s.size(); ++i) {
				while (hashset.find(s[i]) != hashset.end()) {
					hashset.erase(s[left]);
					left++;
				}
				hashset.insert(s[i]);
				maxLength = max(maxLength, (int)hashset.size());
			}
			return maxLength;
		}
	};
}