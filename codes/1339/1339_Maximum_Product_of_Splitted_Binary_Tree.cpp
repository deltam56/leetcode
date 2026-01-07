/**
 * 1339. Maximum Product of Splitted Binary Tree
 * Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

 Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

 Note that you need to maximize the answer before taking the mod and not after taking it.



 Example 1:


 Input: root = [1,2,3,4,5,6]
 Output: 110
 Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
 Example 2:


 Input: root = [1,null,2,3,4,null,null,5,6]
 Output: 90
 Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)


 Constraints:

 The number of nodes in the tree is in the range [2, 5 * 104].
 1 <= Node.val <= 104
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>


using namespace std;

//Definition for a binary tree node.
//
const int MOD = 1e9+7;
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
	int sum = 0;
	long long ret = INT_MIN;
	void sum_dfs(TreeNode* curr){
		if(curr == nullptr)
			return;
		sum += curr->val;
		sum_dfs(curr->left);
		sum_dfs(curr->right);
	}
	long long find_max(TreeNode* curr){
		if(curr == nullptr)
			return 0;
		long long subtree_sum = curr->val;
		subtree_sum += find_max(curr->left);
		subtree_sum += find_max(curr->right);

		ret = max(ret, (subtree_sum * (sum - subtree_sum)));
		return subtree_sum;
	}
public:
	int maxProduct(TreeNode* root) {
		sum = 0;
		ret = INT_MIN;
		sum_dfs(root);

		find_max(root);
		return ret%MOD;
	}
};
int main() {
	Solution sol;
	TreeNode* root;
	int ans,res;

	root = new TreeNode(1,new TreeNode(2,new TreeNode(4),new TreeNode(5)), new TreeNode(3,new TreeNode(6),nullptr));
	ans = 110;
	res = sol.maxProduct(root);
	println("ans : {}, res : {}",ans,res);

	root = new TreeNode(1,nullptr,new TreeNode(2,new TreeNode(3),new TreeNode(4,new TreeNode(5),new TreeNode(6))));
	ans = 90;
	res = sol.maxProduct(root);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
