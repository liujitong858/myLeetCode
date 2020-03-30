#include<algorithm>
#include<unordered_map>
using namespace std;
namespace leetcode337 {
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
	class Solution {
	public:
		int rob(TreeNode* root) {
			return robHelper(root);
		}
		//因为结点会重复计算，所以时间复杂度很高，leetcode超出时间限制
		int robHelper(TreeNode* root) {
			if (root == nullptr) return 0;
			int money = 0;
			if (root->left) {//两个孙子
				money += robHelper(root->left->left) + robHelper(root->left->right);
			}
			if (root->right) {//两个孙子
				money += robHelper(root->right->left) + robHelper(root->right->right);
			}
			return max(money + root->val, robHelper(root->left) + robHelper(root->right));
		}
		//避免了结点的重复计算
		unordered_map<TreeNode*, int> hashtable;
		int robHelper1(TreeNode* root) {
			if (root == nullptr) return 0;
			if (hashtable.count(root) != 0) return hashtable[root];
			int money = 0;
			if (root->left) {//两个孙子
				money += robHelper(root->left->left) + robHelper(root->left->right);
			}
			if (root->right) {//两个孙子
				money += robHelper(root->right->left) + robHelper(root->right->right);
			}
			int maxValue = max(money + root->val, robHelper(root->left) + robHelper(root->right));
			hashtable[root] = maxValue;
			return maxValue;
		}

		//每一个结点的状态有两种，选或者不选
		int rob1(TreeNode* root) {
			vector<int> vec(2, 0);
			//返回数组第一位为包含根节点最大值，第二位为不包含根节点最大值
			vec = robHelper3(root);
			return max(vec[0], vec[1]);
		}
		 vector<int> robHelper3(TreeNode* root) {
			if (root == nullptr) return { 0,0 };
			//深度优先搜索，从叶子结点开始遍历到根节点
			vector<int >left = robHelper3(root->left);
			vector<int >right = robHelper3(root->right);

			vector<int> vec(2, 0);
			vec[0] = root->val + left[1] + right[1];
			vec[1] = +max(left[0], left[1]) + max(right[0], right[1]);
			return vec;
		}
	};
}