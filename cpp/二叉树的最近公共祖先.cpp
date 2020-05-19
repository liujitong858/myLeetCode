#include<vector>
using namespace std;
namespace leetcode236 {
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		
	};
	class Solution {
	public:

		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			//最低公共祖先也可以是自己
			vector<TreeNode*> pathP;
			vector<TreeNode*> pathQ;
			getPath(root, p, pathP);
			getPath(root, q, pathQ);
			return getlowest(pathP, pathQ);
		}
		bool getPath(TreeNode* root, TreeNode* p, vector<TreeNode*> &path) {
			path.push_back(root);
			if (root == p) {
				return true;
			}
			if (root->left != nullptr&&getPath(root->left, p, path))  return true;
			if (root->right != nullptr&&getPath(root->right, p, path)) return true;
			path.pop_back();
			return false;
		}
		TreeNode* getlowest(vector<TreeNode*> pathp, vector<TreeNode*> pathq) {
			TreeNode* node;
			auto iterp = pathp.begin();
			auto iterq = pathq.begin();
			while (iterp != pathp.end() && iterq != pathq.end()) {
				if (*iterp == *iterq) node = *iterp;
				++iterp;
				++iterq;
			}
			return node;
		}
	};
	//递归思想, 对以root为根的(子)树进行查找p和q, 如果root == null || p || q 直接返回root
	//	表示对于当前树的查找已经完毕, 否则对左右子树进行查找, 根据左右子树的返回值判断:
	//  1. 左右子树的返回值都不为null, 由于值唯一左右子树的返回值就是p和q, 此时root为LCA
	//	2. 如果左右子树返回值只有一个不为null, 说明只有p和q存在与左或右子树中, 最先找到的那个节点为LCA
	//	3. 左右子树返回值均为null, p和q均不在树中, 返回null

	//（1） 如果当前结点 rootroot 等于 NULL，则直接返回 NULL
	//	（2） 如果 rootroot 等于 pp 或者 qq ，那这棵树一定返回 pp 或者 qq
	//	（3） 然后递归左右子树，因为是递归，使用函数后可认为左右子树已经算出结果，用 leftleft 和 rightright 表示
	//	（4） 此时若leftleft为空，那最终结果只要看 rightright；若 rightright 为空，那最终结果只要看 leftleft
	//	（5） 如果 leftleft 和 rightright 都非空，因为只给了 pp 和 qq 两个结点，都非空，说明一边一个，因此 rootroot 是他们的最近公共祖先
	//	（6） 如果 leftleft 和 rightright 都为空，则返回空（其实已经包含在前面的情况中了）


	//最简洁递归代码
	TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q) return root;
		TreeNode *left = lowestCommonAncestor1(root->left, p, q);
		TreeNode *right = lowestCommonAncestor1(root->right, p, q);
		if (left && right) return root;
		return left ? left : right;
	}

 }