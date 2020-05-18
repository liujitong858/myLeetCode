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
		//自己的方法
		//比较暴力
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

		//采用后序遍历递归
		//非常巧妙，建议画图理解，也可以看题解
		void flatten(TreeNode* root) {
			if (root == nullptr) return;
			//将左子树变成链表
			flatten(root->left);
			//将右子树变成链表
			flatten(root->right);
			//首先将右子树保存下来
			TreeNode* temp = root->right;
			//将左子树挂到右子树上面
			root->right = root->left;
			//左子树置为空
			root->left = nullptr;
			//找到原左子树的最右结点
			while (root->right != nullptr) root = root->right;
			//将保存的临时右子树挂到上面
			root->right = temp;
		}
	};
}