/**
 * 1022. Sum of Root To Leaf Binary Numbers


 * You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

 * For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
 * For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

 * The test cases are generated so that the answer fits in a 32-bits integer.

 * Example 1:
 * Input: root = [1,0,1,0,1,0,1]
 * Output: 22
 * Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

 * Example 2:
 * Input: root = [0]
 * Output: 0

 * Constraints:

 * The number of nodes in the tree is in the range [1, 1000].
 * Node.val is 0 or 1.
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
private:
	int sum = 0;
	void dfs(int nodeval, TreeNode* curr) {
		nodeval = (nodeval << 1) + curr->val;
		if(curr->left == nullptr && curr->right == nullptr) {
			sum += nodeval;
			return;
		}
		if(curr->left)  dfs(nodeval, curr->left);
		if(curr->right) dfs(nodeval, curr->right);
	}
public:
	int sumRootToLeaf(TreeNode* root) {
		sum = 0;
		dfs(0, root);
		return sum;
	}
};

int main() {
	Solution sol;
	TreeNode* root;
	int ans,res;

	//* Input: root = [1,0,1,0,1,0,1]
	root = new TreeNode(1, new TreeNode(0, new TreeNode(0), new TreeNode(1)), new TreeNode(1, new TreeNode(0), new TreeNode(1)));
	ans = 22;
	res = sol.sumRootToLeaf(root);
	println("ans: {},res : {}",ans,res);

	root = new TreeNode(0);
	ans = 0;
	res = sol.sumRootToLeaf(root);
	println("ans: {},res : {}",ans,res);

	return 0;
}
