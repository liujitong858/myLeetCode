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
		//���ַ������Ը���������ȡ���ȣ����Ը��ڵ�������������ȡ���ȣ���...
		//ʵ�����кܶ��ظ��Ĺ������ٷ��ⷨ�Ǳ�����ʱ��ֱ�ӻ�ȡÿ��������󳤶�
		//һ��·�������Ա�������ĳ���ڵ�Ϊ��㣬��������Ӻ��Ҷ������±�����·��ƴ�ӵõ���
		int diameterOfBinaryTree(TreeNode* root) {
			if (root == nullptr) return 0;
			diameterOfBinaryTree_Helper1(root);
			diameterOfBinaryTree(root->left);
			diameterOfBinaryTree(root->right);
			return MAX_LENGTH;
		}
		//�˽��������
		int diameterOfBinaryTree_Helper(TreeNode* root) {
			if (root == nullptr) return 0;
			return  1 + max(diameterOfBinaryTree_Helper(root->right), diameterOfBinaryTree_Helper(root->left));
		}
		//����һ���������ֱ��
		void diameterOfBinaryTree_Helper1(TreeNode* root) {
			if (root == nullptr) return;
			int leftMaxLength = diameterOfBinaryTree_Helper(root->left);
			int rightMaxLength = diameterOfBinaryTree_Helper(root->right);
			int allLength = leftMaxLength + rightMaxLength;
			MAX_LENGTH = max(MAX_LENGTH, allLength);
		}

		//�������Ż��汾
		int diameterOfBinaryTree_(TreeNode* root) {
			if (root == nullptr) return 0;
			diameterOfBinaryTree_Helper10(root);
			return MAX_LENGTH;
		}
		//�ڵݹ��ʱ��ÿ�ν���������������Ȼ�ȡ֮��ͱȽ�һ��MAX
		//����������˱�����Ҳ��ȡ�˽������
		int diameterOfBinaryTree_Helper10(TreeNode* root) {
			if (root == nullptr) return 0;
			int leftMaxLength = diameterOfBinaryTree_Helper10(root->left);
			int rightMaxLength = diameterOfBinaryTree_Helper10(root->right);
			MAX_LENGTH = max(MAX_LENGTH, leftMaxLength + rightMaxLength);
			return  1 + max(leftMaxLength, rightMaxLength);
		}
	};
}