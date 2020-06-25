#include<vector>
#include<queue>
using namespace std;
namespace heapsort {
		//ʱ�� O(nlogk) �����Ҫ����n�Σ�ÿ�β���Ҫ��k��������ά��
		//�ռ� O(k) �������k��
		//�������ѵ�˼�룬û���޸�ԭ�������飬�Ƚ��ʺϴ���������
		//������
		//��k����С�� ����	less<int>
		//��k������� ��С�� greater<int>
	vector<int> getLeastNumbers1(vector<int>& arr, int k) {
		if (arr.empty() || k <= 0)return vector<int>();
		vector<int> res(k, 0);
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
	void adjust(vector<int>& nums, int len, int index)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		int maxIndex = index;
		if (left<len&&nums[left]>nums[maxIndex]) maxIndex = left;
		if (right<len&&nums[right]>nums[maxIndex]) maxIndex = right; // maxIdx��3��������������±�
		if (maxIndex != index)//maxIndex��ֵ�и��µĻ�
			if (maxIndex != index)                 // ���maxIdx��ֵ�и���
			{
				swap(nums[maxIndex], nums[index]);
				adjust(nums, len, maxIndex);       // �ݹ������������������ʵĲ���
			}
	}
	//��д������
	void heapSort(vector<int>& nums, int size)
	{
		for (int i = size / 2 - 1; i >= 0; i--)  // ��ÿһ����Ҷ�����жѵ���(�����һ����Ҷ��㿪ʼ)
		{
			adjust(nums, size, i);
		}
		for (int i = size - 1; i >= 1; i--)
		{
			swap(nums[0], nums[i]);           // ����ǰ���ķ��õ�����ĩβ
			adjust(nums, i, 0);              // ��δ�������Ĳ��ּ������ж�����
		}
	}
	
}