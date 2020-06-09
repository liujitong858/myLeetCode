#include<string>
#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode5 {
	//暴力法
	string longestPalindrome(string s) {
		string res = "";//存放结果
		string temp = "";//存放子串
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = i; j < s.length(); j++)
			{
				temp = temp + s[j];
				string tem = temp;//tem存放子串反转结果
				std::reverse(tem.begin(), tem.end());//反转
				if (temp == tem)
					res = res.length() > temp.length() ? res : temp;
			}
			temp = "";
		}
		return res;
	}
	//动态规划
	string longestPalindrome1(string s) {
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//回文串起始位置
		int max = 1;//回文串最大长度
		vector<vector<int>>  dp(len, vector<int>(len));//定义二维动态数组
		for (int i = 0; i < len; i++)//初始化状态
		{
			dp[i][i] = 1;
			if (i < len - 1 && s[i] == s[i + 1])
			{
				dp[i][i + 1] = 1;
				max = 2;
				start = i;
			}
		}
		for (int l = 3; l <= len; l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
		{
			for (int i = 0; i + l - 1 < len; i++)
			{
				int j = l + i - 1;//终止字符位置
				if (s[i] == s[j] && dp[i + 1][j - 1] == 1)//状态转移
				{
					dp[i][j] = 1;
					start = i;
					max = l;
				}
			}
		}
		return s.substr(start, max);//获取最长回文子串
	}
	int expandAroundCenter(string& s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{// 计算以left和right为中心的回文串长度
			L--;
			R++;
		}
		return R - L - 1;
	}
	//中心扩展法
	string longestPalindrome2(string s) {
		int length = s.size();
		if (length == 0 || length == 1) return s;
		int maxLength = 0;//记录最大回文子串的长度
		int begin = 0;//记录回文子串起始位置
		int end = 0;//记录回文子串终止位置
		for (int i = 0; i < length; ++i) {
			int len1 = expandAroundCenter(s, i, i);//一个元素为中心
			int len2 = expandAroundCenter(s, i, i + 1);
			maxLength = max(max(len1, len2), maxLength);
			if (maxLength > end - begin + 1) {
				begin = i - (maxLength - 1) / 2;
				end = i + maxLength / 2;
			}
		}
		return s.substr(begin, maxLength);
		//该函数的意思是获取从begin开始长度为mlen长度的字符串
	}
	
}