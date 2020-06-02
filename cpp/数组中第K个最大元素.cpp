#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
namespace leetcode215 {
	class Solution {
	public:
		//ʱ�临�Ӷ�O(NlogN)������ N ������ĳ��ȣ�
		//�㷨������������Ҫ������JDK Ĭ��ʹ�ÿ����������ʱ�临�Ӷ�ΪO(NlogN)��
		//�ռ临�Ӷȣ�O(1)��������ԭ������û�н�������ĸ����ռ䡣
		//���ÿ⺯���ı�����
		int findKthLargest(vector<int>& nums, int k) {
			if (nums.empty() || nums.size() < k) return -1;
			int size = nums.size();
			sort(nums.begin(), nums.end());
			return nums[size - k];
		}
		//ʱ�临�Ӷ�: ƽ�����O(N)������ O(N^2)
		//�ռ临�Ӷ� : O(1)��
		//����������Ȼ�죬�������ʵ�ֵò��ã��������������������ʱ��
		//ʱ�临�ӶȻ��úܸߡ������ʹ�� partition �ķ����������⣬ʱ��������̫���룬���Կ���һ����ʲô���⣬�������ܳ�����
		int findKthLargest1(vector<int>& nums, int k) {
			if (nums.empty()) return -1;
			int low = 0;
			int high = nums.size() - 1;
			int Kmax = nums.size() - k;//��k�������
			int index = _partition1(nums, low, high);
			while (index != Kmax) {
				if (index > Kmax) high = index - 1;
				else low = index + 1;
				index = _partition1(nums, low, high);
			}
			return nums[index];
		}

		int _partition1(vector<int>& vec, int low, int high) {
			//��Ϊ��������������������ǽ�������������
			//�ݹ������˻�������ʱ�临�Ӷȴ�O(NlogN)���O(N^2)
			swap(vec[low], vec[low + rand() % (high - low + 1)]);
			int base = vec[low];
			int left = low;
			while (low < high) {
				while (low < high&&vec[high] >= base) {
					--high;
				}
				while (low < high&&vec[low] <= base) {
					++low;
				}
				if (low < high) {
					swap(vec[high], vec[low]);
				}
			}
			swap(vec[left], vec[low]);
			return low;
		}
	    //ʱ�临�Ӷ�: O(Nlogk)��
		//�ռ临�Ӷ� :O(k)�����ڴ洢��Ԫ�ء�
		int findKthLargest2(vector<int>& nums, int k) {
			if (nums.empty()) return -1;
			priority_queue<int, vector<int>, greater<int>> smallHeap;//Ĭ�Ͻ���С����
			for (int i = 0; i < k; ++i) {
				smallHeap.push(nums[i]);
			}
			for (int i = k; i < nums.size(); ++i) {
				if (smallHeap.top() < nums[i]) {
					smallHeap.pop();
					smallHeap.push(nums[i]);
				}
			}
			return smallHeap.top();
		}
	};
}
