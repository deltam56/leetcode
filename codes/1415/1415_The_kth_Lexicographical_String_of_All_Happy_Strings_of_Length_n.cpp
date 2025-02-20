/**
 * 1415. The k-th Lexicographical String of All Happy Strings of Length n
 * 
 * A happy string is a string that:
 *  - consists only of letters of the set ['a', 'b', 'c'].
 *  - s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
 *  - For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
 *
 * Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
 * 
 * Return the kth string of this list or return an empty string if there are less than k happy strings of length n.
 * 
 * Example 1:
 * Input: n = 1, k = 3
 * Output: "c"
 * Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
 *
 * Example 2:
 * Input: n = 1, k = 4
 * Output: ""
 * Explanation: There are only 3 happy strings of length 1.
 *
 * Example 3:
 * Input: n = 3, k = 9
 * Output: "cab"
 * Explanation: There are 12 different happy string of length 3 ["aba", "abc",
 * "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You
 * will find the 9th string = "cab"
 *
 * Constraints:
 *  - 1 <= n <= 10
 *  - 1 <= k <= 100
 */
#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>


using namespace std; //편의성위해..
#if 1
class Solution {
private:
	void backtracking(vector<string>& res,string& curr, int n,int k, int idx){
		/*base case*/
			if (res.size() == k)
				return;
		/*edge case*/
			if (curr.length() == n){
				res.push_back(curr);
				return;
			}

		/*backtracking*/
			for (char c = 'a' ; c <= 'c'; c++){
				if(curr.back() != c){
					curr += c;
					backtracking(res, curr, n ,k,idx+1);
					curr.pop_back();
				}
			}

	}
public:
	string getHappyString(int n, int k) {

		vector<string> res;
		string curr="";

		backtracking(res,curr,n,k,0);

		return res.size() == k?res.back():"";

	}
};
#else
class Solution {
private:
	void backtrack(vector<string>& res, string& curr, int n, int k,
			int idx) {
		/* Base case */
		if (res.size() == k)
			return;

		/* Edge case */
		if (curr.length() == n) {
			res.push_back(curr);
			return;
		}

		/* Backtracking */
		for (char c = 'a'; c <= 'c' ; ++c) {
			if (curr.back() != c) {
				curr += c;
				backtrack(res, curr, n, k, idx + 1);
				curr.pop_back();
			}
		}
	}

public:
	string getHappyString(int n, int k) {
		vector<string> res;
		string curr("");

		backtrack(res, curr, n, k, 0);

		return res.size() == k ? res.back() : "";
	}
};
#endif
int main() {
	Solution sol;
	string ret;

	ret = sol.getHappyString(1, 3);
	assert(ret == "c");
	cout << ret << endl;

	ret = sol.getHappyString(1, 4);
	assert(ret == "");
	cout << ret << endl;

	ret = sol.getHappyString(3, 9);
	assert(ret == "cab");
	cout << ret << endl;

	cout << "Accepted!" <<endl;

	return 0;
}
