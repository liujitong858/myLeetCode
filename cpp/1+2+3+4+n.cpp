namespace leetcodeMianshi64 {
	class Solution {
	public:
		//要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）
		//下面方式实际上使用了条件判断语句
		int sumNums(int n) {
			int res = 0;
			return sumNums_helper(n, res);
		}
		int sumNums_helper(int n, int res) {
			res += n;
			n--;
			return n == 0 ? res : sumNums_helper(n, res);
		}

		//正解
		//使用 && 的短路特性
		//A && B
		//A 为 true，则计算并返回表达式 B 的 bool 值
		//A 为 false，则直接返回 false
		int sumNums1(int n) {
			n && (n += sumNums(n - 1));
			return n;
		}
	};
}