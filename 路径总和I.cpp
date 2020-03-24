#include<vector>
using namespace std;
namespace leetcode113 {
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};
	class Solution {
	public:
		vector<vector<int>> res;
		vector<vector<int>> pathSum(TreeNode* root, int sum) {
			if (root == nullptr) return vector<vector<int>>();
			vector<int> vec;
			pathSum(root, sum, vec);
			return res;
		}
		void pathSum(TreeNode* root, int sum, vector<int> vec) {
			if (root == nullptr) return;
			vec.push_back(root->val);
			if (root->val == sum && root->left == nullptr&&root->right == nullptr) {
				res.push_back(vec);
			}
			pathSum(root->left, sum - root->val, vec);
			pathSum(root->right, sum - root->val, vec);
			vec.pop_back();
		}
	};
}