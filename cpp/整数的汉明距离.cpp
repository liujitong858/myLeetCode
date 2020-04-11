
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
	//����ⷨ
	//ʵ���Ͻ���˽�ָoffer P102 �е�˼��
	//����һ��������ȥ1���ٺ�ԭ�����������㣬��Ѹ��������ұߵ�1���0
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