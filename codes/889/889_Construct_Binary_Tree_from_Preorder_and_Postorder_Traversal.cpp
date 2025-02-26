/**
* 
* 889. Construct Binary Tree from Preorder and Postorder Traversal
* Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
* 
* If there exist multiple answers, you can return any of them.:w
*
* 
*  
* 
* Example 1:
* 
* 
* Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
* Output: [1,2,3,4,5,6,7]
* Example 2:
* 
* Input: preorder = [1], postorder = [1]
* Output: [1]
*  
* 
* Constraints:
* 
* 1 <= preorder.length <= 30
* 1 <= preorder[i] <= preorder.length
* All the values of preorder are unique.
* postorder.length == preorder.length
* 1 <= postorder[i] <= postorder.length
* All the values of postorder are unique.
* It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
*
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..


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
	void MakeTree(){

	}
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
		TreeNode* root = nullptr;


        return root;
    }
};
void print(TreeNode* ans, TreeNode* res){
	if (!res) return;
	
	println("ans : {} res : {}",ans->val,res->val);
	assert(res->val == ans->val);

	print(ans->left,res->left);
	print(ans->right,res->right);
}
void deleteTree(TreeNode* root)
{
	if (!root)
		return;

	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

int main() {
	Solution sol;	
	vector<int> preorder,postorder;
	TreeNode* ans = nullptr;
	TreeNode* res = nullptr;



	preorder = {1,2,4,5,3,6,7};
	postorder = {4,5,2,6,7,3,1};
	
	ans = new TreeNode(1,
					   new TreeNode(2,new TreeNode(4),new TreeNode(5))
					   new TreeNode(3,new TreeNode(6),new TreeNode(7)));
	res = sol.constructFromPrePost(preorder,postorder);
	print(ans,res);
	deleteTree(res);
	deleteTree(ans);
	
	
	preorder = {1};
	postorder = {1};
	ans = new TreeNode(1);
	res = sol.contructFromPrePost(preorder,postorder);
	print(ans,res);
	deleteTree(res);
	deleteTree(ans);	


	cout << "Accepted!" <<endl;
    return 0;
}
