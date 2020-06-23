#include<vector>
using namespace std;
namespace leetcode977 {
	class Solution {
	public:
		//˫ָ��
		vector<int> sortedSquares(vector<int>& A) {
			if (A.empty()) return {};
			int left = 0;
			int right = A.size() - 1;
			int cur = A.size() - 1;
			vector<int> res(A.size());
			while (cur >= 0) {
				int left_ = A[left] * A[left];
				int right_ = A[right] * A[right];
				if (left_ > right_) {
					left++;
					res[cur] = left_;
				}
				else {
					right--;
					res[cur] = right_;
				}
				cur--;
			}
			return res;
		}

		//��������������飬����ʹ��hashset���������ֵ�ƽ�����ظ��ʹ治��ȥ��
		//��ô���Ϳ���ֱ�ӷ���set�Ĵ�Сsize���ɡ�ʱ��ռ临�Ӷȶ���O��n)��
		//˫ָ��������������������飬��Ȼ���ظ����϶����и�����0, 1��Щ���֡�ƽ������ͷ��
		//�м�С����������βָ�빲ͬ���м�ɨ�裬ɨ��ʱȥ���ظ�Ԫ�أ�ͬʱ��һ��sum����¼�ж��ٸ���ͬ���֡�
		//ʱ�临�Ӷ�O(N)���ռ临�Ӷ�O(1)��
		int sortedSquares1(vector<int>& A) {
			if (A.empty()) return 0;
			int length = A.size();
			int left = 0;
			int right = length - 1;
			int sum = 0;
			while (left <= right) {
				if (A[left]+A[right]==0) {
					sum++;
					int temp = A[left];
					while (left <= right&&A[left] == temp) {
						left++;
					}
					while (left <= right&&A[right] == -temp) {
						right--;
					}
				}
				else if (A[left] + A[right] > 0) {
					sum++;
					int temp = A[right];
					while (left <= right && A[right] == temp) {
						right--;
					}
				}
				else {
					sum++;
					int temp = A[left];
					while (left<=right&&A[left]==temp)		{
						left++;
					}
				}
			}
			return sum;
		}

		//һ�������ȵ����ٵݼ����ҳ����鲻�ظ��ĸ��������� [1, 3, 9, 1]�����Ϊ3������ʹ�ö���ռ䣬���Ӷ�o(n)
		//�ⷨ������һ����˫ָ�����м�ƽ�
	};
}