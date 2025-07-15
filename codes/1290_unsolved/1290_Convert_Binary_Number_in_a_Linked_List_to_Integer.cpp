/**
 * 1290. Convert Binary Number in a Linked List to Integer
 * Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
 * 
 * Return the decimal value of the number in the linked list.
 * 
 * The most significant bit is at the head of the linked list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,0,1]
 * Output: 5
 * Explanation: (101) in base 2 = (5) in base 10
 * Example 2:
 * 
 * Input: head = [0]
 * Output: 0
 * 
 * 
 * Constraints:
 * 
 * The Linked List is not empty.
 * Number of nodes will not exceed 30.
 * Each node's value is either 0 or 1.
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	int getDecimalValue(ListNode* head) {
		vector<bool> bits;
		for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
			bits.push_back(curr->val);
		}

		int value = 0;
		for (bool bit : bits) {
			value = (value << 1) | bit;
		}
		return value;
	}
};
int main() {
	Solution sol;
	int ans ,res;

	//head = [1,0,1];
	ans = 5;
	res = sol.getDecimalValue(new ListNode(1,new ListNode(0,new ListNode(1))));
	println("ans {} res {} ",ans,res);
	//head = [0];
	res = sol.getDecimalValue(new ListNode(0));
	ans = 0;
	println("ans {} res {} ",ans,res);
	return 0;
}
