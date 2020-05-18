#include<vector>
using namespace std;
namespace leetcode114 {

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
	class Solution {
	public:
		//�Լ��ķ���
		//�Ƚϱ���
		void flatten(TreeNode* root) {
			if (root == nullptr) return;
			vector<TreeNode*> vec;
			flatten_helper(vec, root);
			TreeNode* node = root;
			for (int i = 1; i < (int)vec.size(); ++i)
			{
				node->right = vec[i];
				node = node->right;
			}
		}
		void flatten_helper(vector<TreeNode*> &vec, TreeNode* root) {
			vec.push_back(root);
			if (root->left != nullptr)flatten_helper(vec, root->left);
			if (root->right != nullptr)flatten_helper(vec, root->right);
			root->left = nullptr;
			root->right = nullptr;
		}

		//���ú�������ݹ�
		//�ǳ�������黭ͼ��⣬Ҳ���Կ����
		void flatten(TreeNode* root) {
			if (root == nullptr) return;
			//���������������
			flatten(root->left);
			//���������������
			flatten(root->right);
			//���Ƚ���������������
			TreeNode* temp = root->right;
			//���������ҵ�����������
			root->right = root->left;
			//��������Ϊ��
			root->left = nullptr;
			//�ҵ�ԭ�����������ҽ��
			while (root->right != nullptr) root = root->right;
			//���������ʱ�������ҵ�����
			root->right = temp;
		}
	};
}