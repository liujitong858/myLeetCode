#include<algorithm>
#include<unordered_map>
using namespace std;
namespace leetcode337 {
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
	class Solution {
	public:
		int rob(TreeNode* root) {
			return robHelper(root);
		}
		//��Ϊ�����ظ����㣬����ʱ�临�ӶȺܸߣ�leetcode����ʱ������
		int robHelper(TreeNode* root) {
			if (root == nullptr) return 0;
			int money = 0;
			if (root->left) {//��������
				money += robHelper(root->left->left) + robHelper(root->left->right);
			}
			if (root->right) {//��������
				money += robHelper(root->right->left) + robHelper(root->right->right);
			}
			return max(money + root->val, robHelper(root->left) + robHelper(root->right));
		}
		//�����˽����ظ�����
		unordered_map<TreeNode*, int> hashtable;
		int robHelper1(TreeNode* root) {
			if (root == nullptr) return 0;
			if (hashtable.count(root) != 0) return hashtable[root];
			int money = 0;
			if (root->left) {//��������
				money += robHelper(root->left->left) + robHelper(root->left->right);
			}
			if (root->right) {//��������
				money += robHelper(root->right->left) + robHelper(root->right->right);
			}
			int maxValue = max(money + root->val, robHelper(root->left) + robHelper(root->right));
			hashtable[root] = maxValue;
			return maxValue;
		}

		//ÿһ������״̬�����֣�ѡ���߲�ѡ
		int rob1(TreeNode* root) {
			vector<int> vec(2, 0);
			//���������һλΪ�������ڵ����ֵ���ڶ�λΪ���������ڵ����ֵ
			vec = robHelper3(root);
			return max(vec[0], vec[1]);
		}
		 vector<int> robHelper3(TreeNode* root) {
			if (root == nullptr) return { 0,0 };
			//���������������Ҷ�ӽ�㿪ʼ���������ڵ�
			vector<int >left = robHelper3(root->left);
			vector<int >right = robHelper3(root->right);

			vector<int> vec(2, 0);
			vec[0] = root->val + left[1] + right[1];
			vec[1] = +max(left[0], left[1]) + max(right[0], right[1]);
			return vec;
		}
	};
}