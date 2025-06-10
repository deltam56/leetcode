/**
* 3442. Maximum Difference Between Even and Odd Frequency I
* You are given a string s consisting of lowercase English letters.
* 
* Your task is to find the maximum difference diff = a1 - a2 between the frequency of characters a1 and a2 in the string such that:
* 
* a1 has an odd frequency in the string.
* a2 has an even frequency in the string.
* Return this maximum difference.
* 
* 
* 
* Example 1:
* 
* Input: s = "aaaaabbc"
* 
* Output: 3
* 
* Explanation:
* 
* The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
* The maximum difference is 5 - 2 = 3.
* Example 2:
* 
* Input: s = "abcabcab"
* 
* Output: 1
* 
* Explanation:
* 
* The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
* The maximum difference is 3 - 2 = 1.
* 
* 
* Constraints:
* 
* 3 <= s.length <= 100
* s consists only of lowercase English letters.
* s contains at least one character with an odd frequency and one with an even
* frequency.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std; //편의성위해..
class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> c_freq;
		int max_odd=0,max_even=0;
		int min_odd=INT_MAX,min_even=INT_MAX;
		for(const char c: s){
			c_freq[c]++;
		}

		for(auto& i: c_freq){
			if(i.second % 2 == 0){
				max_even = max(max_even,i.second);
				min_even = min(min_even,i.second);
			}
			else
				max_odd = max(max_odd,i.second);
				min_odd = min(min_odd,i.second);
		}
		return max({max_odd-max_even,
					min_odd-min_even,
					max_odd-min_even,});

    }
};
int main() {
	Solution sol;
	string s;
	int ans,res;

	s = "mmsmsym";
	ans = -1;
	res = sol.maxDifference(s);
	println("ans : {} , res : {}",ans,res);

	s = "aaaaabbc";
	ans = 3;
	res = sol.maxDifference(s);
	println("ans : {} , res : {}",ans,res);

	s = "abcabcab";
	ans = 1;
	res = sol.maxDifference(s);
	println("ans : {} , res : {}",ans,res);


    return 0;
}
