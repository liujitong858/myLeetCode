#include<algorithm>
using namespace std;
namespace leetcode543 {

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

	class Solution {
	public:
		int MAX_LENGTH = INT_MIN;
		//这种方法是以根结点遍历获取长度，再以根节点的左结点遍历，获取长度，再...
		//实际上有很多重复的工作，官方解法是遍历的时候直接获取每个结点的最大长度
		//一条路径均可以被看作由某个节点为起点，从其左儿子和右儿子向下遍历的路径拼接得到。
		int diameterOfBinaryTree(TreeNode* root) {
			if (root == nullptr) return 0;
			diameterOfBinaryTree_Helper1(root);
			diameterOfBinaryTree(root->left);
			diameterOfBinaryTree(root->right);
			return MAX_LENGTH;
		}
		//此结点最大深度
		int diameterOfBinaryTree_Helper(TreeNode* root) {
			if (root == nullptr) return 0;
			return  1 + max(diameterOfBinaryTree_Helper(root->right), diameterOfBinaryTree_Helper(root->left));
		}
		//计算一个结点的最大直径
		void diameterOfBinaryTree_Helper1(TreeNode* root) {
			if (root == nullptr) return;
			int leftMaxLength = diameterOfBinaryTree_Helper(root->left);
			int rightMaxLength = diameterOfBinaryTree_Helper(root->right);
			int allLength = leftMaxLength + rightMaxLength;
			MAX_LENGTH = max(MAX_LENGTH, allLength);
		}

		//方案二优化版本
		int diameterOfBinaryTree_(TreeNode* root) {
			if (root == nullptr) return 0;
			diameterOfBinaryTree_Helper10(root);
			return MAX_LENGTH;
		}
		//在递归的时候每次结点左右子树结点深度获取之后就比较一次MAX
		//这样既完成了遍历，也获取了结点的深度
		int diameterOfBinaryTree_Helper10(TreeNode* root) {
			if (root == nullptr) return 0;
			int leftMaxLength = diameterOfBinaryTree_Helper10(root->left);
			int rightMaxLength = diameterOfBinaryTree_Helper10(root->right);
			MAX_LENGTH = max(MAX_LENGTH, leftMaxLength + rightMaxLength);
			return  1 + max(leftMaxLength, rightMaxLength);
		}
	};
}