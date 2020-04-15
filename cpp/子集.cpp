#include<vector>
using namespace std;
namespace leetcode78 {
	class Solution {
	public:
		vector<vector<int>> res;
		//��һ������index���������Χ��
		//����ģ�壨���汾���Ƽ�
		//result = []
		//def backtrack(·��, ѡ���б�) :
		//	if ����������� :
		//		result.add(·��)
		//		return
		//		for ѡ�� in ѡ���б� :
		//��ѡ��
		//	backtrack(·��, ѡ���б�)
		//	����ѡ��
		vector<vector<int>> subsets(vector<int>& nums) {
			// ��¼�߹���·��
			vector<int> track;
			backtrack(nums, 0, track);
			return res;
		}
		void backtrack(vector<int>& nums, int start, vector<int>& track) {
			res.push_back(track);
			// ע�� i �� start ��ʼ����
			for (int i = start; i < nums.size(); i++) {
				// ��ѡ��
				track.push_back(nums[i]);
				// ����
				backtrack(nums, i + 1, track);//һ����ס�����Ǵ���i
				// ����ѡ��					   //��1.3.3������
				track.pop_back();
			}
		}

		//λ����
		//���ϵ�ÿ��Ԫ�أ����п���ѡ��ѡ���ö����ƺ�λ���㣬���Ժܺõı�ʾ��
		vector<vector<int>> subsets1(vector<int>& nums) {
			int S = nums.size();
			int N = 1 << S;//��ϸ���=λ��*2 
			vector<vector<int> > res;
			for (int i = 0; i < N; ++i) {
				vector<int> v;
				for (int j = 0; j < S; ++j)	{
					if (i & (1 << j)) v.push_back(nums[j]);
				}	
				res.push_back(v);
			}
			return res;
		
		}
		//���ǲ��������⣬ÿ�μ���һ��Ԫ�ؾ�����res�ĳ��ȣ�ֱ������Ԫ��������
		//ÿ�θ��Ƶ�ǰres������vector,����������µ�Ԫ��
		//�Դ�����res�ĳ���
		vector<vector<int>> subsets2(vector<int>& nums) {
			vector<vector<int> > res(1);//����һ���յ�
			for (int i = 0; i < nums.size(); i++) {
				int cnt = res.size();
				for (int j = 0; j < cnt; j++) {
					vector<int> tmp = res[j];
					tmp.push_back(nums[i]);
					res.push_back(tmp);
				}
			}
			return res;
		}
	};
}