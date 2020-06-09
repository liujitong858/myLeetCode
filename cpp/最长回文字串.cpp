#include<string>
#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode5 {
	//������
	string longestPalindrome(string s) {
		string res = "";//��Ž��
		string temp = "";//����Ӵ�
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = i; j < s.length(); j++)
			{
				temp = temp + s[j];
				string tem = temp;//tem����Ӵ���ת���
				std::reverse(tem.begin(), tem.end());//��ת
				if (temp == tem)
					res = res.length() > temp.length() ? res : temp;
			}
			temp = "";
		}
		return res;
	}
	//��̬�滮
	string longestPalindrome1(string s) {
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//���Ĵ���ʼλ��
		int max = 1;//���Ĵ���󳤶�
		vector<vector<int>>  dp(len, vector<int>(len));//�����ά��̬����
		for (int i = 0; i < len; i++)//��ʼ��״̬
		{
			dp[i][i] = 1;
			if (i < len - 1 && s[i] == s[i + 1])
			{
				dp[i][i + 1] = 1;
				max = 2;
				start = i;
			}
		}
		for (int l = 3; l <= len; l++)//l��ʾ�������Ӵ����ȣ�����3��ʾ�ȼ�������Ϊ3���Ӵ�
		{
			for (int i = 0; i + l - 1 < len; i++)
			{
				int j = l + i - 1;//��ֹ�ַ�λ��
				if (s[i] == s[j] && dp[i + 1][j - 1] == 1)//״̬ת��
				{
					dp[i][j] = 1;
					start = i;
					max = l;
				}
			}
		}
		return s.substr(start, max);//��ȡ������Ӵ�
	}
	int expandAroundCenter(string& s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{// ������left��rightΪ���ĵĻ��Ĵ�����
			L--;
			R++;
		}
		return R - L - 1;
	}
	//������չ��
	string longestPalindrome2(string s) {
		int length = s.size();
		if (length == 0 || length == 1) return s;
		int maxLength = 0;//��¼�������Ӵ��ĳ���
		int begin = 0;//��¼�����Ӵ���ʼλ��
		int end = 0;//��¼�����Ӵ���ֹλ��
		for (int i = 0; i < length; ++i) {
			int len1 = expandAroundCenter(s, i, i);//һ��Ԫ��Ϊ����
			int len2 = expandAroundCenter(s, i, i + 1);
			maxLength = max(max(len1, len2), maxLength);
			if (maxLength > end - begin + 1) {
				begin = i - (maxLength - 1) / 2;
				end = i + maxLength / 2;
			}
		}
		return s.substr(begin, maxLength);
		//�ú�������˼�ǻ�ȡ��begin��ʼ����Ϊmlen���ȵ��ַ���
	}
	
}