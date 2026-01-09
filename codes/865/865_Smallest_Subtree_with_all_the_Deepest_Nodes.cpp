/**
* 865. Smallest Subtree with all the Deepest Nodes
* Given the root of a binary tree, the depth of each node is the shortest distance to the root.
* 
* Return the smallest subtree such that it contains all the deepest nodes in the original tree.
* 
* A node is called the deepest if it has the largest depth possible among any node in the entire tree.
* 
* The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.
* 
* 
* 
* Example 1:
* 
* 
* Input: root = [3,5,1,6,2,0,8,null,null,7,4]
* Output: [2,7,4]
* Explanation: We return the node with value 2, colored in yellow in the diagram.
* The nodes coloured in blue are the deepest nodes of the tree.
* Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
* Example 2:
* 
* Input: root = [1]
* Output: [1]
* Explanation: The root is the deepest node in the tree.
* Example 3:
* 
* Input: root = [0,1,3,null,2]
* Output: [2]
* Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

//Definition for a binary tree node.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

class Solution {
private:
	pair<int, TreeNode*> dfs(TreeNode* node){
		if(node == nullptr) return {0,nullptr};

		auto [lD, lL] = dfs(node->left);
		auto [rD, rL] = dfs(node->right);
		if(lD > rD) return {lD +1 , lL};
		else if (rD > lD) return {rD+1, rL};
		else return {lD+1, node};
	}
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};

int main() {
	Solution sol;
	TreeNode* root;
	TreeNode* ans;
	TreeNode* res;

    root = new TreeNode(3,
        new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))),
		new TreeNode(1, new TreeNode(0), new TreeNode(8)));

    ans = new TreeNode(2, new TreeNode(7), new TreeNode(4));
    res = sol.subtreeWithAllDeepest(root);
    printTree(ans);
	cout << endl;
    printTree(res);
	cout << endl;

    root = new TreeNode(1);
    ans = new TreeNode(1);
    res = sol.subtreeWithAllDeepest(root);
    printTree(ans);
	cout << endl;
    printTree(res);
	cout << endl;

    root = new TreeNode(0, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(3));
    ans = new TreeNode(2);
    res = sol.subtreeWithAllDeepest(root);
    printTree(ans);
	cout << endl;
    printTree(res);
	cout << endl;
    return 0;
}
