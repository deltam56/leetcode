/*
3174. Clear Digits
You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.



Example 1:

Input: s = "abc"

Output: "abc"

Explanation:

There is no digit in the string.

Example 2:

Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on s[2], and s becomes "c4".

Then we apply the operation on s[1], and s becomes "".



Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.


*/

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <print>
#include <cctype>
using namespace std;
class Solution {
public:
    string clearDigits(string s) {
		string res;
		for (char c : s){
			if(isdigit(c)){
				res.pop_back();
			}else{
				res += c;
			}
		}
		return res;
    }
};
void print(string ans,string res){
	println("ans : {}",ans);
	println("res : {}",res);
	assert(ans==res);
	
	
}
int main() {
	Solution sol;	
	string s;
	string ans,res;

	s = "abc";
	ans = "abc";
	res = sol.clearDigits(s);
	print(res,ans);


	s = "cb34";
	ans = "";
	res = sol.clearDigits(s);
	print(ans,res);

	cout << "Accepted!" <<endl;
    return 0;
}
