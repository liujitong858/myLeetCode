#include<vector>
using namespace std;
namespace leetcode912 {
	class Solution {
	public:
		//��������
		// ��ã�O(n)��ԭ�����Ѿ��������  
		// ���O(n2)�� ԭ�����Ѿ��ǽ����
		// ƽ����O(n2)
		//�ռ临�Ӷ� : O(1)
		//�ȶ�
		vector<int> sortArray(vector<int>& nums) {
			for (int i = 1; i < (int)nums.size(); ++i)
			{
				for (int j = i; j > 0; --j)
				{
					if (nums[j] < nums[j - 1])
					{
						swap(nums[j], nums[j - 1]);
					}
				}
			}
			return nums;
		}
	    
		//ð������,ÿһ����ѭ���ҵ����ķŵ��Ҳ�
		// ��ã�O(n)��ԭ�����Ѿ��������  
		// ���O(n2)�� ԭ�����Ѿ��ǽ����
		// ƽ����O(n2)
		//�ռ临�Ӷ� : O(1)
		//�ȶ�
		vector<int> sortArray1(vector<int>& nums) {
			for (int i = (int)nums.size() - 1; i > 0; --i)
			{
				for (int j = 1; j <=i ; ++j)
				{
					if (nums[j] < nums[j - 1])
					{
						swap(nums[j], nums[j - 1]);
					}
				}
			}
			return nums;
		}

		// ��������
		// ʱ�临�Ӷ� O(nlogn)
		// �ռ临�Ӷ� ջ�ռ� O(h) hΪ�ݹ���ò���
		// ��ã�O(n * logn)�������������ȷֲ��ڻ��������ߣ���ʱ�ĵݹ���ǲ��ϵض����������С�
		// ���O(n2) �� �����������ֲ��ڻ�����һ�ߣ���ʱ�����������о��൱�ڳ��˲�������
		// ƽ����O(n * logn)
		// ���ȶ�
		vector<int> sortArray2(vector<int>& nums) {
			QuickSort(nums, 0, (int)nums.size() - 1);
			return nums;
		}
		void QuickSort(vector<int>& nums, int start, int end)
		{
			if (start < end)
			{
				int base = quicksort(nums, start, end);
				QuickSort(nums, start, base - 1);
				QuickSort(nums, base + 1, end);
			}
		}
		int quicksort(vector<int>& nums, int low, int high)
		{
			int base = nums[low];
			int left = low;
			while (low < high)
			{
				while (low < high&&nums[high]>=base)
				{
					--high;
				}
				while (low < high&&nums[low]<=base)
				{
					++low;
				}
				if (low < high)
				{
					swap(nums[low], nums[high]);
				}
			}
			nums[left] = nums[low];
			nums[low] = base;
			return low;
		}

		
		//�鲢����
		// �ݹ齫�����Ϊ�������У�����ϲ�����������
		// ��ã�O(n * logn)
		// ���O(n * logn)
		// ƽ����O(n * logn)
		// �ռ临�Ӷ� : O(n)
	    // �ȶ�
		vector<int> sortArray3(vector<int>& nums) {
			merge(nums, 0, (int)nums.size()-1);
			return nums;
		}
		void merge(vector<int>& nums, int low, int high)
		{
			vector<int> temp(high-low+1);
			if (low >= high) return;
			int mid = (low + high) / 2;
			merge(nums, low, mid);
			merge(nums, mid +1 , high);
			int i = low, j = mid + 1,index=0;
			while (i<=mid&&j<=high)
			{
				if (nums[i] < nums[j]) {
					temp[index++] = nums[i++];
				}
				else	{
					temp[index++] = nums[j++];
				}
			}
			//�������ʣ���Ԫ��
			while (i <= mid) temp[index++] = nums[i++];
			while (j <= high) temp[index++] = nums[j++];
			for (int i = 0; i < (int)temp.size(); ++i)
			{
				nums[i + low] = temp[i];
			}
		}

	    // ѡ������
		// ��ð���������ƣ���������ѡ�������ǽ�ÿһ��Ԫ�غ��������ÿһ��Ԫ�ؽ��бȽϺͽ������Ӷ��ҵ���Сֵ
		// ��ã�O(n2)
		// ���O(n2)
		// ƽ����O(n2)
		// ���ȶ�
		vector<int> sortArray4(vector<int>& nums) {
			for (int i = 0; i < (int)nums.size(); ++i)
			{
				int min = i;
				for (int j = i; j < (int)nums.size(); ++j)
				{
					if (nums[j] < nums[min])
					{
						min =j;
					}
				}
				swap(nums[i], nums[min]);
			}
			return nums;
		}
		// ������
		// �������齨��һ���ѣ�������ȫ����������ÿ������ֵ���������ҽ�㣨���ѣ�ͨ���������򣩣���С�����ҽ�㣨��С�ѣ�ͨ�����ڽ��򣩡�
        // �������������ȹ������Ѻ󣬽����Ѷ�Ԫ�أ����ֵ���Ͷѵ�Ԫ�أ�ÿһ�ν������ܵõ�һ��δ�������е����ֵ��
        // ���µ������ѣ��ٽ����Ѷ�Ԫ�غͶѵ�Ԫ�ء��ظ�n-1�κ���ܵõ�һ�����������
        // ��ã�O(n * logn)��logn�ǵ�������������ʱ��
        // ���O(n * logn)
        // ƽ����O(n * logn)
		// ���ȶ�
		// �ռ临�Ӷ� : O(1)
		vector<int> sortArray5(vector<int>& nums) {
			heapSort(nums);
			return nums;
		}
		void maxHeapify(vector<int>& nums, int i, int len) {
			while (i * 2+1 <= len){//��i���ں���
				int lson = i * 2 + 1;//���ӽ�������
				int rson = i * 2 + 2;//���ӽ�������
				int large=0;
				//*******************���������������
				if (lson <= len && nums[lson] > nums[i]) {
					large = lson;
				}
				else {
					large = i;
				}
				if (rson <= len && nums[rson] > nums[large]) {
					large = rson;
				}//********************���������������
				if (large != i) {//�������ֵ
					swap(nums[i], nums[large]);
					i = large;
					//����ѭ��һ���жϽ���������ҽ��λ���Ƿ��ƻ��˶ѽṹ
				    //����ʱ�ڵ㲻�����ֵ, ���п���ҲС��
					//<�Ըýڵ�Ϊ������һ���Ӷ�>�ĺ��ӽڵ�
					//������Ҫ���ýڵ�Ҳ����һ���³�����
				}
				else break;	//������ֵ�����Լ�˵���Ѿ������ѣ�����
			}
		}
		//��������
		void buildMaxHeap(vector<int>& nums, int len) {
			for (int i = len / 2; i >= 0; --i) {
				maxHeapify(nums, i, len);// ֻ��Ҫ�� i = (len - 1) / 2 ���λ�ÿ�ʼ�������
			}
		}
		//�ع���
		void heapSort(vector<int>& nums) {
			int len = (int)nums.size() - 1;
			buildMaxHeap(nums, len);
			for (int i = len; i > 0; --i) {//ֻ��Ҫ����n-1��
				swap(nums[i], nums[0]);  // ����(�����ֵ��������β,��size - 1)
				len-=1;				     // ����Ҫ�����������ֵ��
				maxHeapify(nums, 0, len);// ����ִ���³�����/���¹���
			}
		}
	};
}
