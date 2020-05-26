#include<vector>
#include<queue>
using namespace std;
namespace leetcode102 {
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

	class Solution {
	public:
		//BFS
		//广度优先需要用队列作为辅助结构，我们先将根节点放到队列中，然后不断遍历队列
		vector<vector<int>> levelOrder(TreeNode* root) {
			if (root == nullptr) return vector<vector<int>>();
			vector<vector<int>> res;
			queue<TreeNode*> que1;
			queue<TreeNode*> que2;
			que1.push(root);
			while (!que1.empty() || !que2.empty()) {
				vector<int> vec1;
				vector<int> vec2;
				while (!que1.empty()) {
					TreeNode* node = que1.front();
					que1.pop();
					if (node->left != nullptr) que2.push(node->left);
					if (node->right != nullptr) que2.push(node->right);
					vec2.push_back(node->val);
				}
				if (!vec2.empty()) res.push_back(vec2);
				while (!que2.empty()) {
					TreeNode* node = que2.front();
					que2.pop();
					if (node->left != nullptr) que1.push(node->left);
					if (node->right != nullptr) que1.push(node->right);
					vec1.push_back(node->val);
				}
				if (!vec1.empty()) res.push_back(vec1);
			}
			return res;
		}
		//简化版本
		//但是运行时间还是慢一些
		vector<vector<int>> levelOrder1(TreeNode* root) {
			if (root == nullptr) return vector<vector<int>>();
			vector<vector<int>> res;
			queue<TreeNode*> que;
			que.push(root);
			//如果不是分行打印的话，那么不需要内层while，直接打印即可
			while (!que.empty()) {
				vector<int> vec;
				int count = (int)que.size();
				while (count--) {
					TreeNode* node = que.front();
					que.pop();
					if (node->left != nullptr) que.push(node->left);
					if (node->right != nullptr) que.push(node->right);
					vec.push_back(node->val);
				}
				if (!vec.empty()) res.push_back(vec);
			}
			return res;
		}
		//DFS版本，关键是加入一个Level 所在层变量
		vector<vector<int>> levelOrder2(TreeNode* root) {
			if (root == nullptr) return vector<vector<int>>();
			vector<vector<int>> res;
			levelOrder_DFS(0, root, res);
			return res;
		}
		void levelOrder_DFS(int level, TreeNode* root, vector<vector<int>>& res) {
			if (root == nullptr) return;
			if (level >= res.size()) res.push_back(vector<int>());
			res[level].push_back(root->val);
			levelOrder_DFS(level + 1, root->left, res);
			levelOrder_DFS(level + 1, root->right, res);
		}
	};
}