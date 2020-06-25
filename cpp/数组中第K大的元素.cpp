#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
namespace leetcode215 {
	class Solution {
	public:
		//����֮�����ҵķ���
		int findKthLargest(vector<int>& nums, int k) {
			if (nums.empty() || nums.size() < k) return -1;
			sort(nums.begin(), nums.end());
			for (int i = nums.size() - 1; i >= 0; --i) {
				if (i + k == nums.size()) return nums[i];
				else continue;
			}
			return -1;
		}

		//ʹ���Զ���Ŀ�������
		//�������������һ������
		////��Ϊ��������������������ǽ�������������
        //�ݹ������˻�������ʱ�临�Ӷȴ�O(NlogN)���O(N^2)
		int findKthLargest1(vector<int>& nums, int k) {
			if (nums.empty() || nums.size() < k) return -1;
			int start = 0;
			int end = nums.size()-1;
			int index = partition(nums, start, end);
			int maxkIndex = nums.size() - k-1;//����󣬵�K��Ԫ�ص�����
			while (index != maxkIndex) {
				if (index < maxkIndex) start = index + 1;
				else end = index - 1;
				partition(nums, start, end);
			}
			return nums[index];
		}
		int partition(vector<int>& nums, int low, int high) {
			//swap(nums[low], nums[low + rand() % (high - low + 1)]);
			//������һ����Ϊ�˷�ֹ�ݹ����˻�������
			int left = low;
			int base = nums[low];
			while (low < high) {
				while (low < high&&nums[high] >= base) {
					--high;
				}
				while (low < high&&nums[low] <= base) {
					++low;
				}
				if (low < high) {
					swap(nums[low], nums[high]);
				}
			}
			nums[left] = nums[low];
			nums[low] = base;
			return low;
		}

		int findKthLargest2(vector<int>& nums, int k) {
			if (nums.empty() || nums.size() < k) return -1;
			priority_queue<int, vector<int>, greater<int>> heap;
			for (int i = 0; i < k; ++i) {
				heap.push(nums[i]);
			}
			for (int i = k; i < nums.size() - 1; ++i) {
				if (nums[i] > heap.top()) {
					heap.pop();
					heap.push(nums[i]);
				}
			}
			return heap.top();
		}
		//�Ż���һ��ѭ��Ҳ����
		//for(int i=0;i<nums.size();++i){
		//smallHeap.push(nums[i]);
		//if (smallHeap.size() > k) {
		//	smallHeap.pop();//һ������С�ģ���Ϊ���ȶ����Զ�����
		//}
	};
}