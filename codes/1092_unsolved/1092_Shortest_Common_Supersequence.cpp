/**
*
* 1092. Shortest Common Supersequence
*
*
* Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
* 
* A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
* 
* 
* 
* Example 1:
* 
* Input: str1 = "abac", str2 = "cab"
* Output: "cabac"
* Explanation:
* str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
* str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
* The answer provided is the shortest such string that satisfies these properties.
* Example 2:
* 
* Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
* Output: "aaaaaaaa"
* 
* 
* Constraints:
* 
* 1 <= str1.length, str2.length <= 1000
* str1 and str2 consist of lowercase English letters.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
		int premax = 0;
		int postmax = 0;
		string l_str,s_str;
		string res = "";
		int a = str1.length()-str2.length();

		if (a > 0) {
	        l_str = str1;
	        s_str = str2;
	    } else if (a < 0) {
	        l_str = str2;
	        s_str = str1;
	    } else {
	        l_str = str1;
	        s_str = str2;
	    }
		if(str1 == str2)
			return str1;
		for (int i = 0; i<s_str.length();i++){
			string l_front_substr = l_str.substr(0,i);
			string s_front_substr = s_str.substr(s_str.length()-i);
			if(l_front_substr == s_front_substr)
				premax = i;

			string l_back_substr = l_str.substr(l_str.length()-i);
			string s_back_substr = s_str.substr(0,i);
			if(l_back_substr == s_back_substr)
				postmax = i;
		}

		println("premax : {}  postmax : {} ",premax,postmax);
		res = premax > postmax ? s_str.substr(0,s_str.length()-premax)+l_str :
			l_str + s_str.substr(0,postmax);

		if(premax == 0 and postmax ==0)
			return str1+str2;
		return res;
    }
};

int main() {
	Solution sol;	
	string str1,str2;
	string ans, res;

	aabbccdd
	a bbcc c

	str1 = "abac";
	str2 = "cab";
	ans = "cabac";
	res = sol.shortestCommonSupersequence(str1, str2);
	println("ans : {} \n res : {} ",ans,res);
	assert(ans==res);

	str1 = "aaaaaaaa"; 
	str2 = "aaaaaaaa";
	ans = "aaaaaaaa";
	res = sol.shortestCommonSupersequence(str1, str2);
	println("ans : {} \n res : {} ",ans,res);
	assert(ans==res);

	str1 ="bbbaaaba";
	str2 ="bbababbb";
	ans = "bbbaaababbb";
	res = sol.shortestCommonSupersequence(str1, str2);
	println("ans : {} \n res : {} ",ans,res);
	assert(ans==res);



	cout << "Accepted!" <<endl;
    return 0;
}
