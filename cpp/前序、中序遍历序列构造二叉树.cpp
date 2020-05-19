#include<vector>
#include<algorithm>
using namespace std;
namespace leetcode105 {

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

	class Solution {
	public:
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			if (preorder.empty() || inorder.empty()) return nullptr;
			vector<int> leftTree;
			vector<int> rightTree;
			TreeNode* root = new TreeNode(preorder[0]);
			//根结点的索引
			auto indexOfroot = find(inorder.begin(), inorder.end(), preorder[0]);
			int dis = distance(inorder.begin(), indexOfroot);
			vector<int> preleft;
			vector<int> inorderleft;
			vector<int> preright;
			vector<int> inorderright;
			for (int i = 0; i < (int)inorder.size(); ++i) {
				if (i == dis) continue;
				else if (i < dis) inorderleft.push_back(inorder[i]);
				else  inorderright.push_back(inorder[i]);
			}
			for (int i = 1; i < (int)preorder.size(); ++i) {
				if (dis != 0) {
					dis--;
					preleft.push_back(preorder[i]);
				}
				else  preright.push_back(preorder[i]);
			}
			root->right = buildTree(preright, inorderright);
			root->left = buildTree(preleft, inorderleft);
			return root;
		}

		//采用索引的方式代替vec
		//节约空间和时间
		TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
			if (preorder.empty() || inorder.empty())    return nullptr;
			return buildTree_helper1(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
		}
		TreeNode* buildTree_helper1(vector<int>& preorder, int prebegin, int preend, vector<int>& inorder, int inbegin, int inend) {
			if (prebegin > preend || inbegin > inend)  return nullptr;
			TreeNode* root = new TreeNode(preorder[prebegin]);
			int dis = 0;
			while (inorder[inbegin + dis] != preorder[prebegin])   ++dis;
			root->left = buildTree_helper1(preorder, prebegin + 1, prebegin + dis, inorder, inbegin, inbegin + dis - 1);
			root->right = buildTree_helper1(preorder, prebegin + dis + 1, preend, inorder, inbegin + dis + 1, inend);
			return root;
		}
	};
}