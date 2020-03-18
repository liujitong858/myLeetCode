using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	
};
class Solution {
public:
	//�ҵĽⷨ
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr && t2 == nullptr) return nullptr;
		TreeNode* node = new TreeNode(0);//ע��������Ҫʹ�����Ա��һ��Ҫ��ʼ��
		if (t1 != nullptr && t2 != nullptr) {
			node->val = t1->val + t2->val;
			node->left = mergeTrees(t1->left, t2->left);
			node->right = mergeTrees(t1->right, t2->right);
		}
		else if (t2 == nullptr && t1 != nullptr) {
			node->val = t1->val;
			node->left = mergeTrees(t1->left, nullptr);
			node->right = mergeTrees(t1->right, nullptr);
		}
		else if (t2 != nullptr && t1 == nullptr) {
			node->val = t2->val;
			node->left = mergeTrees(nullptr, t2->left);
			node->right = mergeTrees(nullptr, t2->right);
		}
		return node;
	}
	//�ٷ��ⷨ
	TreeNode* mergeTrees1(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr && t2 == nullptr) {
			return nullptr;
		}
		TreeNode* ret = new TreeNode((t1 == nullptr ? 0 : t1->val) + (t2 == nullptr ? 0 : t2->val));
		ret->left = mergeTrees(t1 == nullptr ? nullptr : t1->left, t2 == nullptr ? nullptr : t2->left);
		ret->right = mergeTrees(t1 == nullptr ? nullptr : t1->right, t2 == nullptr ? nullptr : t2->right);
		return ret;
	}
	//�ٷ��ⷨ2.���Ըı�ԭ��������һ����
	TreeNode* mergeTrees2(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr)
			return t2;
		else if (t2 == nullptr)
			return t1;
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
};
