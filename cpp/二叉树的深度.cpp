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
		//�Ƚ����������������ĸ߶�
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return max(left, right) + 1;
	}
	//���汾
	int maxDepth1(TreeNode* root) {
		if (root == nullptr) return 0;
		//�Ƚ����������������ĸ߶�
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};