#include<vector>
#include<string>
#include<algorithm>
using namespace std;
namespace leetcode9 {
	class Solution {
	public:
		//���ڻ�����
		//1������
		//2���ȿ���ʹ���ַ��������
		bool isPalindrome(int x) {
			string x_string = to_string(x);
			if (x_string.size() == 0 || x_string.size() == 1) return true;
			return isPalindrome_helper(x_string, 0, x_string.size() - 1);
		}
		bool isPalindrome_helper(string& x_string, int left, int right) {
			while (left < right) {
				if (x_string[left] == x_string[right]) {
					++left;
					--right;
				}
				else return false;
			}
			return true;
		}

		//�ַ�����ת��ֱ�ӱȽ�
		bool isPalindrome1(int x) {
			string x_string = to_string(x);
			string ori_string = x_string;
			if (x_string.size() == 0 || x_string.size() == 1) return true;
			reverse(x_string.begin(), x_string.end());//��ת
			return ori_string == x_string ? true : false;
		}

		bool isPalindrome2(int x) {
			if (x < 0) return false;
			int div = 1;
			while (x / div >= 10) div *= 10;//��ȡǧλ������Ҫ�ĳ���
			while (x > 0) {
				int left = x / div;//���������
				int right = x % 10;//���Ҳ�����
				if (left != right) return false;
				x = (x % div) / 10;//�����м��λ��ʮλ��������
				div /= 100;//����100��������һ��ѭ����ȡ��ʮλ������
			}
			return true;
		}
		//ʹ��vector
		bool isPalindrome3(int x) {
			if (x < 0) return false;
			if (x / 10 == 0) return true;//0-9
			vector<int> tmp;
			while (x > 0) {
				tmp.emplace_back(x % 10);
				x /= 10;
			}
			for (int i = tmp.size() - 1, j = 0; i > 0, j < i; i--, j++)
				if (tmp[i] != tmp[j]) return false;
			return true;
		}
	};
}