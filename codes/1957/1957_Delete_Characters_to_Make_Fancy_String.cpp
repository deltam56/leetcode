/**
* 1957. Delete Characters to Make Fancy String
* A fancy string is a string where no three consecutive characters are equal.
* 
* Given a string s, delete the minimum possible number of characters from s to make it fancy.
* 
* Return the final string after the deletion. It can be shown that the answer will always be unique.
* 
*  
* 
* Example 1:
* 
* Input: s = "leeetcode"
* Output: "leetcode"
* Explanation:
* Remove an 'e' from the first group of 'e's to create "leetcode".
* No three consecutive characters are equal, so return "leetcode".
* Example 2:
* 
* Input: s = "aaabaaaa"
* Output: "aabaa"
* Explanation:
* Remove an 'a' from the first group of 'a's to create "aabaaaa".
* Remove two 'a's from the second group of 'a's to create "aabaa".
* No three consecutive characters are equal, so return "aabaa".
* Example 3:
* 
* Input: s = "aab"
* Output: "aab"
* Explanation: No three consecutive characters are equal, so return "aab".
*  
* 
* Constraints:
* 
* 1 <= s.length <= 105
* s consists only of lowercase English letters.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

class Solution {
public:
    string makeFancyString(string s) {
		int charcount = 1;
		string ret = "";
		ret += s[0];
        for(int i = 1; i < s.length(); ++i){
			if(s[i-1] == s[i]){
				charcount ++;
				if(charcount <3){
					ret += s[i];
				}else{
					charcount--;
				}
			}else{
				charcount = 1;
				ret += s[i];
			}
		}
		return ret;
    }
};

int main() {
	Solution sol;
	string s;
	string ans, res;

	s = "leeetcode";
	ans = "leetcode";
	res = sol.makeFancyString(s);
	println("ans : {}, res :{}",ans,res);

	s = "aaabaaaa";
	ans = "aabaa";
	res = sol.makeFancyString(s);
	println("ans : {}, res :{}",ans,res);

	s = "aab";
	ans = "aab";
	res = sol.makeFancyString(s);
	println("ans : {}, res :{}",ans,res);

	cout << "Accepted!" <<endl;
    return 0;
}
