/*
1790. Check if One String Swap Can Make Strings Equal


You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
 

Constraints:

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.

*/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        char size = s1.size();
        if(s1 == s2)
        {
            return true;
        }
        char count=0;
        vector<array<char, 2>> mis;
        for(char i=0;i < size && count<2;i++){
            if(s1[i]!=s2[i]){
                switch (count){
                    case 0:
                        mis.push_back({s1[i],s2[i]});
                        count ++;
                        break;
                    case 1:
                        mis.push_back({s2[i],s1[i]});
                        break;
                    default:
                        return false;
                }
            }
        }
        if (mis.size() == 2 && mis[0] == mis[1]) {
            return true;
        }
        return false;
    }
};

void print(bool ans,bool ret){
	cout << "ans : " << ans;
	cout << " ret : " << ret << endl;
	assert(ans==ret);

}

int main(){
	string s1;
	string s2;
	bool ans;
	bool ret;

	Solution sol;

	s1 = "bank", s2 = "kanb";
	ans = true;
	ret = sol.areAlmostEqual(s1,s2);
	print(ans,ret);

	s1 = "attack", s2 = "defend";
	ans= false;
	ret = sol.areAlmostEqual(s1,s2);
	print(ans,ret);

	s1 = "kelb", s2 = "kelb";
	ans = true;
	ret = sol.areAlmostEqual(s1,s2);
	print(ans,ret);

	return 0;
}
