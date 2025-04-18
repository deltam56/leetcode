/**
*
* 1261. Find Elements in a Contaminated Binary Tree
*   - Google, Amazon
*
* Given a binary tree with the following rules:
*  - root.val == 0
*  - For any treeNode:
*  - If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
*  - If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
*
* Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
* 
* Implement the FindElements class:
*  - FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
*  - bool find(int target) Returns true if the target value exists in the recovered binary tree.
* 
* Example 1:
* 
* 
* Input
* ["FindElements","find","find"]
* [[[-1,null,-1]],[1],[2]]
* Output
* [null,false,true]
* Explanation
* FindElements findElements = new FindElements([-1,null,-1]);
* findElements.find(1); // return False
* findElements.find(2); // return True
*
* Example 2:
* 
* 
* Input
* ["FindElements","find","find","find"]
* [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
* Output
* [null,true,true,false]
* Explanation
* FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
* findElements.find(1); // return True
* findElements.find(3); // return True
* findElements.find(5); // return False
*
* Example 3:
* 
* 
* Input
* ["FindElements","find","find","find","find"]
* [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
* Output
* [null,true,false,false,true]
* Explanation
* FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
* findElements.find(2); // return True
* findElements.find(3); // return False
* findElements.find(4); // return False
* findElements.find(5); // return True
* 
* Constraints:
*  - TreeNode.val == -1
*  - The height of the binary tree is less than or equal to 20
*  - The total number of nodes is between [1, 10^4]
*  - Total calls of find() is between [1, 10^4]
*  - 0 <= target <= 10^6
**/

#include <iostream>
#include <cassert>
#include <unordered_set>
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
	TreeNode(int x, TreeNode *left, TreeNode *right) :
		val(x), left(left), right(right) {}
};

class FindElements {
private:
	unordered_set<int> values;  // 벡터 대신 해시셋 사용

	void recover(TreeNode* root, int val) {
		if (!root) return;

		root->val = val;
		values.insert(val);

		recover(root->left, 2 * val + 1);
		recover(root->right, 2 * val + 2);
	}

public:
	FindElements(TreeNode* root) {
		recover(root, 0);
	}

	bool find(int target) {
		return values.count(target) > 0;
	}
};

void delete_tree(TreeNode* root);
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
int main() {
	TreeNode* root;
	bool res;

	root = new TreeNode(-1, nullptr, new TreeNode(-1));
	FindElements* findElements = new FindElements(root);

	res = findElements->find(1);
	assert(res==false);
	cout << boolalpha << res << endl;

	res = findElements->find(2);
	assert(res==true);
	cout << boolalpha << res << endl;

	delete_tree(root);
	delete findElements;

	root = new TreeNode(-1, new TreeNode(-1, new TreeNode(-1),
			new TreeNode(-1)), new TreeNode(-1));
	findElements = new FindElements(root);
	res = findElements->find(1);
	assert(res==true);
	cout << boolalpha << res << endl;

	res = findElements->find(3);
	assert(res==true);
	cout << boolalpha << res << endl;

	res = findElements->find(5);
	assert(res==false);
	cout << boolalpha << res << endl;

	delete_tree(root);
	delete findElements;

	root = new TreeNode(-1, nullptr, new TreeNode(-1,
			new TreeNode(-1, new TreeNode(-1), nullptr), nullptr));
	findElements = new FindElements(root);
	res = findElements->find(2);
	assert(res==true);
	cout << boolalpha << res << endl;

	res = findElements->find(3);
	assert(res==false);
	cout << boolalpha << res << endl;

	res = findElements->find(4);
	assert(res==false);
	cout << boolalpha << res << endl;

	res = findElements->find(5);
	assert(res==true);
	cout << boolalpha << res << endl;

	delete_tree(root);
	delete findElements;

	cout << "Accepted!" <<endl;
    return 0;
}

void delete_tree(TreeNode* root)
{
	if (!root)
		return;

	delete_tree(root->left);
	delete_tree(root->right);
	delete root;
}
