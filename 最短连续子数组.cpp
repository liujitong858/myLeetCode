#include<vector>
#include <algorithm>
using namespace std;
namespace leetcode581{
	class Solution {
	public:
		//307��������������ͨ�������ǳ�ʱ
		int findUnsortedSubarray(vector<int>& nums) {
			if (nums.empty() || nums.size() == 1)return 0;
			//�����ǹؼ�
			//�ؼ����ҵ�����������
			int start = 0;
			int end = nums.size() - 1;
			vector<int>::iterator _begin = nums.begin();
			vector<int>::iterator _end = nums.end();
			while (end > 0 && nums[end] == *max_element(_begin, _end))
			{
				--end;
				--_end;
			}
			if (end == 0) return 0;//˵��ԭ�����������
			while (start < nums.size() - 1 && nums[start] == *min_element(_begin, _end))
			{
				++start;
				++_begin;
			}
			return end - start + 1;
		}
		//������ѭ������¼���ֵΪ max���� nums[i] < max, 
		//�����λ�� i ��Ҫ����, ѭ����������¼��Ҫ���������λ�� i Ϊ high;
		//ͬ�����ҵ���ѭ������¼��СֵΪ min, �� nums[i] > min, 
		//�����λ�� i ��Ҫ������ѭ����������¼��Ҫ��������Сλ�� i Ϊ low.
		int findUnsortedSubarray1(vector<int>& nums) {
			if (nums.empty() || nums.size() == 1)return 0;
			int _Max = nums[0];
			int _Min = nums[nums.size() - 1];
			int high = -2;//����ֵ��Ϊ-2�ǿ��������鱾���������ʱ,returnҲ���Ը�����ȷֵ
			int low = -1;
			int pos = 0;//��i��Ӧ������
			for (int i = 0; i < (int)nums.size(); ++i)
			{
				pos = (int)nums.size() - i - 1;
				if (nums[i] < _Max) high = i;
				else  _Max = nums[i];
	
				if (nums[pos] > _Min) low = pos;
				else _Min = nums[pos];
			}
			//���ؿ�ʼ�ͽ�����������
			return high - low + 1;
		}
		//��������Ȼ��Ա�
		int findUnsortedSubarray2(vector<int>& nums) {
			if (nums.empty() || nums.size() == 1)return 0;
			vector<int >copynums(nums);
			sort(copynums.begin(), copynums.end());
			int start = -1;
			int end = -2;//��֤�����û������������Ҳ���������
			int pos = 0;
			int size = (int)nums.size();
			for (int i = 0; i < size; ++i)
			{
				pos = size - 1 - i;
				if (start == -1 && nums[i] != copynums[i])
				{
					start = i;
				}
				if (end == -2 && nums[pos] != copynums[pos])
				{
					end = pos;
				}
				if (start != -1 && end != -2)break;
			}
			return end - start + 1;
		}
	};
}