#include<vector>
#include<queue>
using namespace std;
namespace leetcode40 {
	class Solution {
	public:
		//���ÿ��������˼�룬�޸�ԭ��������   ƽ��ʱ�临�Ӷ�O(n)
		vector<int> getLeastNumbers(vector<int>& arr, int k) {
			if (arr.empty() || k <= 0)return vector<int>();
			int start = 0;
			int end = (int)arr.size() - 1;
			int index = Partition(arr, start, end);
			vector<int> res;
			while (index != k - 1) {
				if (index > k - 1) {
					end = index - 1;
					index = Partition(arr, start, end);
				}
				else if (index < k - 1) {
					start = index + 1;
					index = Partition(arr, start, end);
				}
			}
			for (int i = 0; i < k; ++i) {
				res.push_back(arr[i]);
			}
			return res;
		}
		int Partition(vector<int>& arr, int low, int high) {
			int base = arr[low];
			int left = low;
			while (low < high)
			{
				while (low < high&&arr[high] >=base) {
					--high;
				}
				while (low < high&&arr[low] <=base) {
					++low;
				}
				if (low < high) {
					int temp = arr[high];
					arr[high] = arr[low];
					arr[low] = temp;
				}
			}
			arr[left] = arr[low];
			arr[low] = base;
			return low;
		}

		//ʱ�� O(nlogk) �����Ҫ����n�Σ�ÿ�β���Ҫ��k��������ά��
		//�ռ� O(k) �������k��
		//�������ѵ�˼�룬û���޸�ԭ�������飬�Ƚ��ʺϴ���������
		//������
		vector<int> getLeastNumbers1(vector<int>& arr, int k) {
			if (arr.empty() || k <= 0)return vector<int>();
			vector<int> res(k,0);
			priority_queue<int> bigHeap;//Ĭ�Ͻ�������
			//priority_queue <int, vector<int>, less<int> ��������
			for (int i = 0; i < k; ++i) {
				bigHeap.push(arr[i]);
			}
			for (int i = k; i < (int)arr.size(); ++i) {
				if (bigHeap.top() > arr[i]) {
					bigHeap.pop();
					bigHeap.push(arr[i]);
				}
			}
			for (int i = 0; i < k; ++i) {
				res[i] = bigHeap.top();
				bigHeap.pop();
			}
			return res;
		}
		//�������ַ���������STL�е�partial_sort ʵ����Ҳ��heap_sort
		vector<int> getLeastNumbers2(vector<int>& arr, int k) {
			if (arr.empty() || k <= 0)return vector<int>();
			partial_sort(arr.begin(), arr.begin() + k, arr.end());
			vector<int> res(arr.begin(), arr.begin() + k);
			return res;
		}

		vector<int> getLeastNumbers3(vector<int>& arr, int k) {
			if (arr.empty() || k <= 0)return vector<int>();
			vector<int> res(k);
			partial_sort_copy(arr.begin(), arr.end(), res.begin(), res.end());
			return res;
		}
	};
}
