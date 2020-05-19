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
			//��͹�������Ҳ�������Լ�
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
	//�ݹ�˼��, ����rootΪ����(��)�����в���p��q, ���root == null || p || q ֱ�ӷ���root
	//	��ʾ���ڵ�ǰ���Ĳ����Ѿ����, ����������������в���, �������������ķ���ֵ�ж�:
	//  1. ���������ķ���ֵ����Ϊnull, ����ֵΨһ���������ķ���ֵ����p��q, ��ʱrootΪLCA
	//	2. ���������������ֵֻ��һ����Ϊnull, ˵��ֻ��p��q�����������������, �����ҵ����Ǹ��ڵ�ΪLCA
	//	3. ������������ֵ��Ϊnull, p��q����������, ����null

	//��1�� �����ǰ��� rootroot ���� NULL����ֱ�ӷ��� NULL
	//	��2�� ��� rootroot ���� pp ���� qq ���������һ������ pp ���� qq
	//	��3�� Ȼ��ݹ�������������Ϊ�ǵݹ飬ʹ�ú��������Ϊ���������Ѿ����������� leftleft �� rightright ��ʾ
	//	��4�� ��ʱ��leftleftΪ�գ������ս��ֻҪ�� rightright���� rightright Ϊ�գ������ս��ֻҪ�� leftleft
	//	��5�� ��� leftleft �� rightright ���ǿգ���Ϊֻ���� pp �� qq ������㣬���ǿգ�˵��һ��һ������� rootroot �����ǵ������������
	//	��6�� ��� leftleft �� rightright ��Ϊ�գ��򷵻ؿգ���ʵ�Ѿ�������ǰ���������ˣ�


	//����ݹ����
	TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q) return root;
		TreeNode *left = lowestCommonAncestor1(root->left, p, q);
		TreeNode *right = lowestCommonAncestor1(root->right, p, q);
		if (left && right) return root;
		return left ? left : right;
	}

 }