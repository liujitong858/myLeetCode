#include<vector>
#include<stack>
using namespace std;
namespace leetcode94 {

  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
	class Solution {
	public:
		//µÝ¹é
		vector<int> res;
		vector<int> inorderTraversal(TreeNode* root) {
			if (root != nullptr) inorderTraversal_helper(root);
			return res;
		}
		void inorderTraversal_helper(TreeNode* root) {
			if (root->left != nullptr) inorderTraversal(root->left);
			res.push_back(root->val);
			if (root->right != nullptr)inorderTraversal(root->right);
		}


		//·ÇµÝ¹é
		vector<int> inorderTraversal1(TreeNode* root) {
			if (root == nullptr) return vector<int>();
			stack<TreeNode*> sta;
			vector<int> res;
			TreeNode* node = root;
			while (!sta.empty() || node != nullptr)
			{
				while (node != nullptr) {
					sta.push(node);
					node = node->left;
				}
				node = sta.top();
				sta.pop();
				res.push_back(node->val);
				node = node->right;
			}
			return res;
		}
	};
}