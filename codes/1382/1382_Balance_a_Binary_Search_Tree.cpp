/**
 * 1382. Balance a Binary Search Tree
 *Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
 *
 *A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
 *
 * 
 *
 *Example 1:
 *Input: root = [1,null,2,null,3,null,4,null,null]
 *Output: [2,1,3,null,null,null,4]
 *Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct

 *Input: root = [2,1,3]
 *Output: [2,1,3]
 *
 *Constraints:
 *The number of nodes in the tree is in the range [1, 10^4].
 *1 <= Node.val <= 10^5
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
	vector<int> values;
	void dfs(TreeNode* curr){
		if(curr == nullptr)
			return;
		dfs(curr->left);
		dfs(curr->right);
		values.push_back(curr->val);
		return;
	}
public:
	TreeNode* balanceBST(TreeNode* root) {
		//dfs 탐색하면서 나오는대로 다 새로 구성하면 될듯
		//굳이 기존이 balanced  인지 판단할 필요는 이 문제에서는 필요없을듯
		values = {};
		dfs(root);


		println("val = {}",values);

	}
};
int main() {
	Solution sol;
	TreeNode* root;
	TreeNode* ans = nullptr;
	TreeNode* res = nullptr;

	root = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4))));
	ans = new TreeNode(2, new TreeNode(1, nullptr, nullptr), new TreeNode(3, nullptr, new TreeNode(4)));
	res = sol.balanceBST(root);
	println("ans : {}, res : {}", ans->val, res->val);

	root = new TreeNode(2, new TreeNode(1, nullptr, nullptr), new TreeNode(3));
	ans = new TreeNode(2, new TreeNode(1, nullptr, nullptr), new TreeNode(3));
	res = sol.balanceBST(root);
	println("ans : {}, res : {}", ans->val, res->val);
	return 0;
}
