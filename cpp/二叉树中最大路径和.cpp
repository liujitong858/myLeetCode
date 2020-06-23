#include<algorithm>
using namespace std;
namespace leetcode124 {

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

	class Solution {
	public:
		int maxPathSum(TreeNode* root) {
			if (root == nullptr) return 0;
			int val = INT_MIN;
			maxPathSum_helper(root, val);
			return val;
		}
		int maxPathSum_helper(TreeNode* root, int& val) {
			if (root == nullptr) return 0;
			int left = max(0, maxPathSum_helper(root->left, val));
			int right = max(0, maxPathSum_helper(root->right, val));
			int connect_value = root->val + left + right;//左边链接右边
			val = max(val, connect_value);
			// 返回经过root的单边最大分支给上游
			return (root->val + max(left, right));
		}
	};
}