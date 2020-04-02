#include<vector>
using namespace std;
namespace leetcode912 {
	class Solution {
	public:
		//插入排序
		// 最好：O(n)，原数组已经是升序的  
		// 最坏：O(n2)， 原数组已经是降序的
		// 平均：O(n2)
		//空间复杂度 : O(1)
		//稳定
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
	    
		//冒泡排序,每一次外循环找到最大的放到右侧
		// 最好：O(n)，原数组已经是升序的  
		// 最坏：O(n2)， 原数组已经是降序的
		// 平均：O(n2)
		//空间复杂度 : O(1)
		//稳定
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

		// 快速排序
		// 时间复杂度 O(nlogn)
		// 空间复杂度 栈空间 O(h) h为递归调用层数
		// 最好：O(n * logn)，其他的数均匀分布在基数的两边，此时的递归就是不断地二分左右序列。
		// 最坏：O(n2) ， 其他的数都分布在基数的一边，此时划分左右序列就相当于成了插入排序。
		// 平均：O(n * logn)
		// 不稳定
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

		
		//归并排序
		// 递归将数组分为两个序列，有序合并这两个序列
		// 最好：O(n * logn)
		// 最坏：O(n * logn)
		// 平均：O(n * logn)
		// 空间复杂度 : O(n)
	    // 稳定
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
			//如果还有剩余的元素
			while (i <= mid) temp[index++] = nums[i++];
			while (j <= high) temp[index++] = nums[j++];
			for (int i = 0; i < (int)temp.size(); ++i)
			{
				nums[i + low] = temp[i];
			}
		}

	    // 选择排序
		// 和冒泡排序相似，区别在于选择排序是将每一个元素和它后面的每一个元素进行比较和交换，从而找到最小值
		// 最好：O(n2)
		// 最坏：O(n2)
		// 平均：O(n2)
		// 不稳定
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
		// 堆排序
		// 根据数组建立一个堆（类似完全二叉树），每个结点的值都大于左右结点（最大堆，通常用于升序），或小于左右结点（最小堆，通常用于降序）。
        // 对于升序排序，先构建最大堆后，交换堆顶元素（最大值）和堆底元素，每一次交换都能得到一个未有序序列的最大值。
        // 重新调整最大堆，再交换堆顶元素和堆底元素。重复n-1次后就能得到一个升序的数组
        // 最好：O(n * logn)，logn是调整最大堆所花的时间
        // 最坏：O(n * logn)
        // 平均：O(n * logn)
		// 不稳定
		// 空间复杂度 : O(1)
		vector<int> sortArray5(vector<int>& nums) {
			heapSort(nums);
			return nums;
		}
		void maxHeapify(vector<int>& nums, int i, int len) {
			while (i * 2+1 <= len){//当i存在孩子
				int lson = i * 2 + 1;//左子结点的索引
				int rson = i * 2 + 2;//右子结点的索引
				int large=0;
				//*******************找三个结点中最大的
				if (lson <= len && nums[lson] > nums[i]) {
					large = lson;
				}
				else {
					large = i;
				}
				if (rson <= len && nums[rson] > nums[large]) {
					large = rson;
				}//********************找三个结点中最大的
				if (large != i) {//更新最大值
					swap(nums[i], nums[large]);
					i = large;
					//并再循环一遍判断交换后的左右结点位置是否破坏了堆结构
				    //若此时节点不是最大值, 则有可能也小于
					//<以该节点为根的下一个子堆>的孩子节点
					//所以需要将该节点也进行一次下沉操作
				}
				else break;	//如果最大值就是自己说明已经是最大堆，返回
			}
		}
		//建立最大堆
		void buildMaxHeap(vector<int>& nums, int len) {
			for (int i = len / 2; i >= 0; --i) {
				maxHeapify(nums, i, len);// 只需要从 i = (len - 1) / 2 这个位置开始逐层下移
			}
		}
		//重构堆
		void heapSort(vector<int>& nums) {
			int len = (int)nums.size() - 1;
			buildMaxHeap(nums, len);
			for (int i = len; i > 0; --i) {//只需要再排n-1次
				swap(nums[i], nums[0]);  // 出堆(将最大值放置数组尾,堆size - 1)
				len-=1;				     // 不需要考虑最后的最大值了
				maxHeapify(nums, 0, len);// 将根执行下沉操作/重新构建
			}
		}
	};
}
