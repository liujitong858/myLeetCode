#include<stack>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//反转后变为一颗新树，不动原来的树
TreeNode* invertTree(TreeNode* root) {
	if (root == nullptr) return nullptr;
	TreeNode* node = new TreeNode(root->val);
	node->left = invertTree(root->right);
	node->right = invertTree(root->left);
	return node;
}
//在原来树的基础上进行反转,这个问题的关键是tempNod，交换
TreeNode* invertTree1(TreeNode* root) {
	if (root == nullptr) return nullptr;
	//交换左右子树
	TreeNode* tempNode = root->right;
	root->right = root->left;
	root->left = tempNode;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

//使用栈或者队列做
TreeNode* invertTree2(TreeNode* root) {
	if (root == nullptr) return nullptr;
	stack<TreeNode*> nodeStack;
	nodeStack.push(root);
	while (!nodeStack.empty()) {
		TreeNode* cur = nodeStack.top();
		TreeNode* tempNode = cur->right;
		cur->right = cur->left;
		cur->left = tempNode;
		nodeStack.pop();
		if (cur->left != nullptr) nodeStack.push(cur->left);
		if (cur->right != nullptr) nodeStack.push(cur->right);
	}
	return  root;
}

TreeNode* invertTree3(TreeNode* root) {
	if (root == nullptr) return nullptr;
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);
	while (!nodeQueue.empty()) {
		TreeNode* cur = nodeQueue.front();
		TreeNode* tempNode = cur->right;
		cur->right = cur->left;
		cur->left = tempNode;
		nodeQueue.pop();
		if (cur->left != nullptr) nodeQueue.push(cur->left);
		if (cur->right != nullptr) nodeQueue.push(cur->right);
	}
	return  root;
}