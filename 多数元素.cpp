#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
namespace leetcode169 {
	class Solution {
	public:
		//����֮�������λ��
		//ʱ�临�Ӷ�O(nlogn) �ռ临�Ӷ�O(logn)
		int majorityElement(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			return nums[(int)nums.size() / 2];
		}
		//��ϣ��ķ��� �ռ�0��n��ʱ��O��n��
		int maiorityElement1(vector<int>& nums) {
			unordered_map<int, int> hash;
			for (auto elem : nums) {
				++hash[elem];
				if (hash[elem] > (int)nums.size()/2) return elem;
			}
			return -1;
		}
		//Ħ��ͶƱ��
		//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O��1
		//Ħ��ͶƱ����������ͬ��������ͶһƱ��������ͬ�������ͼ�һƱ����󻹴���Ʊ��������������
		int majorityElement2(vector<int>& nums) {
			int candidate = -1;
			int count = 0;
			for (int num : nums) {
				if(count==0)candidate = num;//count=0��ʱ�����»���
			    if (num == candidate) ++count;	
				else --count;
			}
			return candidate;
		}
	};
}
