#include<deque>
#include<vector>
using namespace std;
namespace leetcode437 {
struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
        class Solution {
        public:
        	int count = 0;
			//对每一个结点都求pathSum
        	int pathSum(TreeNode* root, int sum) {
        		if (root == nullptr) return 0;
        		pathSum(root->left, sum);
        		pathSumHelper(root, sum);
        		pathSum(root->right, sum);
        		return count;
        	}
			//求以一个根节点为起点 一个路径的合
        	void pathSumHelper(TreeNode* root, int sum) {
        		if (root == nullptr) return;
        		if (root->val == sum) ++count;
        		pathSumHelper(root->left, sum - root->val);
        		pathSumHelper(root->right, sum - root->val);
        	}
        };
}