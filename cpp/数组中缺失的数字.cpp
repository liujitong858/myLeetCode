#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
namespace leetcode268 {
	class Solution {
	public:
		//��ѧ����
		int missingNumber(vector<int>& nums) {
			if (nums.empty()) return 0;
			int sum = 0;
			for (int i = 1; i <= nums.size(); ++i) {
				sum += i;
				sum -= nums[i - 1];
			}
			return sum;
		}
		//����
		int missingNumber1(vector<int>& nums) {
			if (nums.empty()) return 0;
			sort(nums.begin(), nums.end());
			for (int i = 0; i < nums.size(); ++i) {
				if (i != nums[i]) return i;
			}
			return 0;
		}
		//��ϣ��
		int missingNumber2(vector<int>& nums) {
			if (nums.empty()) return 0;
			unordered_set<int> hashset;
			for (auto num : nums) hashset.insert(num);
			for (int i = 0; i <= nums.size(); ++i) {
				if (hashset.count(i)==0) return i;
			}
			return 0;
		}

		//һ���������飬��С�����ҵ���һ��ȱ����������[8 2 4 3 6 9 7 11 12],��һ��ȱ�ľ���5 ��2��
		//1.����ʱ�临�Ӷ�O(NlogN)
		//2.��������Ϊ��ϣ��������i���������е�i��������Ȼ�����м�û�д������ֵ�λ�á�ʱ��Ϳռ临�Ӷȶ���O(N)
		//����������Сֵ��ȷ���������巶Χ
		//Ȼ���ʼ��Ϊ����
		//����ԭ���� ��丨������ nums[i]=i;
		//ɨ�踨�����飬��һ�� num[i]!=i ����� i
	};
}