#include<vector>
#include<algorithm>
using namespace std;
namespace BucketSort {
	void BucketSort_1(vector<int>& nums){
		int length = nums.size();
		int min = nums[0];
		int max = nums[0];
		for (int i = 0; i < length; ++i) {
			if (min > nums[i]) min=nums[i];
			if (max < nums[i])max = nums[i];
		}
		int k = 10;//kΪ����֮��ļ��
		int bucketsNum = (max - min) / k + 1;
		vector<vector<int>> vec(bucketsNum, vector<int>());
		for (int i = 0; i < length; ++i) {//Ԫ��װͰ
			vec[(nums[i] - min) / bucketsNum].push_back(nums[i]);
		}
		nums.clear();
		for (int i = 0; i < bucketsNum; ++i) {
			sort(vec[i].begin(), vec[i].end());//����������㷨���ؼ�
			for (auto num : vec[i]) {//���·���ԭ���鼴��
				nums.push_back(num);
			}
		}
	}
}