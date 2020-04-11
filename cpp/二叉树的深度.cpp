using namespace std;
#include <algorithm>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		//比较左子树和右子树的高度
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return max(left, right) + 1;
	}
	//简介版本
	int maxDepth1(TreeNode* root) {
		if (root == nullptr) return 0;
		//比较左子树和右子树的高度
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};