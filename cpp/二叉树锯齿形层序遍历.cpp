#include<vector>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
namespace leetcode103 {
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
	class Solution {
	public:
		//使用双端队列
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
			if (root == nullptr) return vector<vector<int>>();
			if (root == nullptr) return vector<vector<int>>();
			vector<vector<int>> res;
			deque<TreeNode*> deq;
			deq.push_front(root);
			int level = 1;
			while (!deq.empty()) {
				vector<int> vec;
				int count = (int)deq.size();
				while (count--) {
					TreeNode* node = nullptr;
					if (level % 2) {//奇数行从前往后取节点 孩子自左向右压入双端队列尾
						node = deq.front();
						deq.pop_front();
						if (node->left != nullptr) deq.push_back(node->left);
						if (node->right != nullptr) deq.push_back(node->right);
					}
					else {//偶数行 从后往前取节点 孩子自右向左压入双端队列头
						node = deq.back();
						deq.pop_back();
						if (node->right != nullptr) deq.push_front(node->right);
						if (node->left != nullptr) deq.push_front(node->left);
					}
					vec.push_back(node->val);
				}
				if (!vec.empty()) {
					res.push_back(vec);
					level++;
				}
			}
			return res;
		}

		//使用两个栈
		vector<vector<int>> zigzagLevelOrder1(TreeNode* root) {
			if (root == nullptr) return vector<vector<int>>();
			if (root == nullptr) return vector<vector<int>>();
			vector<vector<int>> res;
			stack<TreeNode*> sta1;
			stack<TreeNode*> sta2;
			sta1.push(root);
			while (!sta1.empty() || !sta2.empty()) {
				vector<int>vec1;
				while (!sta1.empty()) {//奇数行的左子结点先进栈
					TreeNode* node = sta1.top();
					sta1.pop();
					if (node->left != nullptr)sta2.push(node->left);
					if (node->right != nullptr)sta2.push(node->right);
					vec1.push_back(node->val);
				}
				if (!vec1.empty()) {
					res.push_back(vec1);
					vec1.clear();
				}
				while (!sta2.empty()) {//偶数行的右子结点先进栈
					TreeNode* node = sta2.top();
					sta2.pop();
					if (node->right != nullptr)sta1.push(node->right);
					if (node->left != nullptr)sta1.push(node->left);
					vec1.push_back(node->val);
				}
				if (!vec1.empty()) {
					res.push_back(vec1);
					vec1.clear();
				}
			}
			return res;
		}
	};
}