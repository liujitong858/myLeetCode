namespace leetcodeMianshi64 {
	class Solution {
	public:
		//Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A ? B : C��
		//���淽ʽʵ����ʹ���������ж����
		int sumNums(int n) {
			int res = 0;
			return sumNums_helper(n, res);
		}
		int sumNums_helper(int n, int res) {
			res += n;
			n--;
			return n == 0 ? res : sumNums_helper(n, res);
		}

		//����
		//ʹ�� && �Ķ�·����
		//A && B
		//A Ϊ true������㲢���ر��ʽ B �� bool ֵ
		//A Ϊ false����ֱ�ӷ��� false
		int sumNums1(int n) {
			n && (n += sumNums(n - 1));
			return n;
		}
	};
}