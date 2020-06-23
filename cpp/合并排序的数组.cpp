#include<vector>
#include<algorithm>
using namespace std;
namespace Mianshi {
	class Solution {
	public:
		//���ƹ鲢����
		void merge(vector<int>& A, int m, vector<int>& B, int n) {
			int newMaxIndex = A.size() - 1;
			int curA = m - 1;
			int curB = n - 1;
			while (curA >= 0 && curB >= 0) {
				if (A[curA] >= B[curB]) {
					A[newMaxIndex--] = A[curA--];
				}
				else {
					A[newMaxIndex--] = B[curB--];
				}
			}
			while (curB >= 0) {
				A[newMaxIndex--] = B[curB--];
			}
		}
		//ֱ�Ӱ�����B��������A��Ȼ������
		void merge1(vector<int>& A, int m, vector<int>& B, int n) {
			for (int i = 0; i != n; ++i)
				A[m + i] = B[i];
			sort(A.begin(), A.end());
		}

	};
}