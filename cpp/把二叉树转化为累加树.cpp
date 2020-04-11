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
			//һ��������������������
			//һ�����ĸ��ڵ㣬�Լ����ڵ��������Ҳ������       
			//����Ǹ��ڵ�����ӽ�㣬��ôsum=�Լ�+���ڵ�+��������val��
			//����Ǹ��ڵ�����ӽ�㣬��ôsum=�Լ�+��������val��
			//��εݹ���Ա����ظ����
			//����˳���ȷ����ǰ�����
			if (root == nullptr) return nullptr;
			node = root;
			int sum = TreeNodeValSum(node);
			convertBST_Helper(node, sum, 0);
			return node;
		}
		//root
		//sumRoot ���ڵ�ĺ�
		//LastRootval��root���ڵ��val
		void convertBST_Helper(TreeNode* root, int sumRoot, int LastRootval) {
			if (root == nullptr) return;
			if (node == root || LastRootval <= root->val) { //��Ը��ڵ������������ӽ���Լ�������������
				int rightTreeSumVal = sumRoot - TreeNodeValSum(root) - LastRootval;//���ڵ��Լ����ڵ�����������val����
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
		//����ڵ��Լ�����������SumVal
		//�ȸ��ڵ��Ĳż���
		int TreeNodeValSum(TreeNode* root) {
			if (root == nullptr) return 0;
			int sum = root->val + TreeNodeValSum(root->left) + TreeNodeValSum(root->right);
			return sum;
		}

		//ֱ�ӻ��ݣ������������˳����б����
		//ͬʱ�ۼ�val
		TreeNode* convertBST1(TreeNode* root) {
			if (root == nullptr) return nullptr;
			int val = 0;
			convertBST(root,val);
		}
		void convertBST(TreeNode* root, int & val) {
			if (!root) return;
			convertBST(root->right, val);
			root->val += val;//��һ�ε������ʱ��Root����val���Ľ��
			val = root->val;//��һ�ε������ʱ��ֵ
			convertBST(root->left, val);
		}
	};
}