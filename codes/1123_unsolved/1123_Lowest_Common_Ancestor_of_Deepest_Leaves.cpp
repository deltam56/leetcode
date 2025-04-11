/**
* 1123. Lowest Common Ancestor of Deepest Leaves
* Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
* 
* Recall that:
* 
* The node of a binary tree is a leaf if and only if it has no children
* The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
* The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
* 
* 
* Example 1:
* 
* 
* Input: root = [3,5,1,6,2,0,8,null,null,7,4]
* Output: [2,7,4]
* Explanation: We return the node with value 2, colored in yellow in the diagram.
* The nodes coloured in blue are the deepest leaf-nodes of the tree.
* Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
* Example 2:
* 
* Input: root = [1]
* Output: [1]
* Explanation: The root is the deepest node in the tree, and it's the lca of itself.
* Example 3:
* 
* Input: root = [0,1,3,null,2]
* Output: [2]
* Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
*Constraints:
* 
* The number of nodes in the tree will be in the range [1, 1000].
* 0 <= Node.val <= 1000
* The values of the nodes in the tree are unique.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#if 0
class Solution {
private:
	void dfs(TreeNode* &ret_Tree,int curr_d,int& max_d,TreeNode* cur){
		if (cur == nullptr) return;
		max_d = max(max_d, curr_d);
		dfs(ret_Tree,curr_d+1,max_d,cur->left);
		dfs(ret_Tree,curr_d+1,max_d,cur->right);
		if(curr_d == max_d - 1){
			if(cur->left != nullptr && cur->right != nullptr)
				ret_Tree = new TreeNode(cur->val,cur->left,cur->right);
		}
	}
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
		TreeNode* ret_Tree;
		int max_d = 0;
		dfs(ret_Tree, 0, max_d, root);

		return ret_Tree;
    }
};
#else
class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (!node) return {nullptr, 0};

        auto [left_lca, left_depth] = dfs(node->left);
        auto [right_lca, right_depth] = dfs(node->right);

        if (left_depth == right_depth)
            return {node, left_depth + 1};  // 두 쪽 다 가장 깊은 노드 있음 → 현재 노드가 LCA
        else if (left_depth > right_depth)
            return {left_lca, left_depth + 1};
        else
            return {right_lca, right_depth + 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};
#endif
int main() {
	Solution sol;
	TreeNode* root;
	TreeNode* ans;
	TreeNode* res;

	root = new TreeNode(3,
						new TreeNode(5,
									 new TreeNode(6),
									 new TreeNode(2,
												  new TreeNode(7),
												  new TreeNode(4))),
						new TreeNode(1,
									 new TreeNode(0),
									 new TreeNode(8)));

	ans = new TreeNode(2,new TreeNode(7),new TreeNode(4));
	res = sol.lcaDeepestLeaves(root);

	root = new TreeNode(1);
	ans = new TreeNode(1);
	res = sol.lcaDeepestLeaves(root);

	root = new TreeNode(0,new TreeNode(1,nullptr,new TreeNode(2)),new TreeNode(3));
	ans = new TreeNode(2);
	res = sol.lcaDeepestLeaves(root);


    return 0;
}
