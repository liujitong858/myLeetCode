namespace leetcode101 {

  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
	class Solution {
	public:
		bool isSymmetric(TreeNode* root) {
			if (root == nullptr) return true;
			return isSymmetric_Helper(root->left, root->right);
		}
		bool isSymmetric_Helper(TreeNode* left, TreeNode* right) {
			if (left == nullptr&&right == nullptr) return true;
			else if (left ==nullptr||right == nullptr) return false;
			if (left->val == right->val) {
				return isSymmetric_Helper(left->left, right->right) &&
					isSymmetric_Helper(left->right, right->left);
			}
			else return false;
		}
	};
}