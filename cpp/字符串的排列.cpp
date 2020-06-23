#include<string>
#include<unordered_map>
using namespace std;
namespace leetcode567 {
	class Solution {
	public:
		//����: s1 = "ab" s2 = "eidbaooo"
		//��� : True
		//���� : s2 ���� s1 ������֮һ("ba").

		//����: s1= "ab" s2 = "eidboaoo"
		//���: False
		bool checkInclusion(string s1, string s2) {
			if (s1.size() > s2.size()) return false;
			int length = s1.size();
			//ģʽ�����ֵ䣺���Կ���һ��Ƶ�ʷֲ�
			vector<int> hashmap1(26, 0);
			//��̬���µ�ƥ�䴰���ֵ�
			vector<int> hashmap2(26, 0);

			for (int i = 0; i < length; ++i) {
				hashmap1[s1[i] - 'a']++;
				hashmap2[s2[i] - 'a']++;
			}
			for (int i = length; i < s2.size(); ++i) {
				if (hashmap1 == hashmap2) return true;
				//�������� �����һ��� �������� hash ��Ĳ�����Ϊ��ӦƵ�ʵ�����
				hashmap2[s2[i - length] - 'a']--;
				hashmap2[s2[i] - 'a']++;
			}
			//�����㷨��������ҿ����䣬�������һ������û���ж�
			return hashmap1 == hashmap2;
		}
		bool checkInclusion1(string s1, string s2) {
			if (s1.size() > s2.size()) return false;
			unordered_map<char, int> need, windows;
			for (auto ch : s1) {
				need[ch]++;
			}
			int left = 0;
			int right = 0;
			int vaild = 0;
			while (right < s2.size()) {
				char ch = s2[right];
				right++;
				if (need.count(ch)) {
					windows[ch]++;
					if (need[ch] == windows[ch]) {
						vaild++;
					}
				}
				while (right - left >= s1.size()) {
					if (vaild == need.size()) return true;
					char char_ = s2[left];
					left++;
					if (need.count(char_)) {
						if (need[char_] == windows[char_]) {
							vaild--;
						}
						windows[char_]--;
					}
				}
			}
			return false;
		}
	};
}