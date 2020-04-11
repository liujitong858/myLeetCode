
class Solution {
public:
	int hammingDistance(int x, int y) {
		int Hamdis = 0;
		while (x != 0 || y != 0) {
			if (((x & 1) && !(y & 1)) || !(x & 1) && (y & 1)) {
				++Hamdis;
			}
			x = x >> 1;
			y = y >> 1;
		}
		return Hamdis;
	}
	//优秀解法
	//实际上借鉴了剑指offer P102 中的思想
	//即把一个整数减去1，再和原整数做与运算，会把该整数最右边的1变成0
	int hammingDistance1(int x, int y) {
		int a = x ^ y;
		int ans = 0;
		while (a != 0) {
			ans++;
			a &= a - 1;
		}
		return ans;
	}
};