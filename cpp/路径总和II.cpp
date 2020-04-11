namespace leetcode112 {
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};
	class Solution {
	public:
		bool hasPathSum(TreeNode* root, int sum) {
			return hasPathSumHelper(root, sum);
		}
		bool hasPathSumHelper(TreeNode* root, int sum) {
			if (root == nullptr) return false;
			if (root->val == sum &&
				root->left == nullptr&&
				root->right == nullptr) return true;
			return  hasPathSum(root->left, sum - root->val) ||
				hasPathSum(root->right, sum - root->val);
		}
	};
}
 