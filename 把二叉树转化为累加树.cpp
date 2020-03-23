namespace leetcode538 {

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
	class Solution {
	public:
		TreeNode* node;
		TreeNode* convertBST(TreeNode* root) {
			//一个树的右子树都比它大
			//一个结点的根节点，以及根节点的右子树也比它大       
			//如果是根节点的左子结点，那么sum=自己+根节点+右子树的val合
			//如果是根节点的右子结点，那么sum=自己+右子树的val合
			//如何递归可以避免重复添加
			//遍历顺序的确定，前序遍历
			if (root == nullptr) return nullptr;
			node = root;
			int sum = TreeNodeValSum(node);
			convertBST_Helper(node, sum, 0);
			return node;
		}
		//root
		//sumRoot 根节点的合
		//LastRootval，root父节点的val
		void convertBST_Helper(TreeNode* root, int sumRoot, int LastRootval) {
			if (root == nullptr) return;
			if (node == root || LastRootval <= root->val) { //针对根节点左子树的右子结点以及根结点的右子树
				int rightTreeSumVal = sumRoot - TreeNodeValSum(root) - LastRootval;//根节点以及根节点右子树所有val集合
				LastRootval = root->val;
				root->val = root->val + TreeNodeValSum(root->right) + rightTreeSumVal;
			}
			else {
				LastRootval = root->val;
				root->val = root->val + sumRoot + TreeNodeValSum(root->right);
			}
			convertBST_Helper(root->left, root->val, LastRootval);
			convertBST_Helper(root->right, root->val, LastRootval);
		}
		//求根节点以及所有子树的SumVal
		//比根节点大的才加上
		int TreeNodeValSum(TreeNode* root) {
			if (root == nullptr) return 0;
			int sum = root->val + TreeNodeValSum(root->left) + TreeNodeValSum(root->right);
			return sum;
		}

		//直接回溯，按照右中左的顺序进行便遍历
		//同时累加val
		TreeNode* convertBST1(TreeNode* root) {
			if (root == nullptr) return nullptr;
			int val = 0;
			convertBST(root,val);
		}
		void convertBST(TreeNode* root, int & val) {
			if (!root) return;
			convertBST(root->right, val);
			root->val += val;//第一次到这里的时候Root就是val最多的结点
			val = root->val;//第一次到这里的时候赋值
			convertBST(root->left, val);
		}
	};
}