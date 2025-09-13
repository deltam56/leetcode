/**
* 3541. Find Most Frequent Vowel and Consonant
* You are given a string s consisting of lowercase English letters ('a' to 'z').
* 
* Your task is to:
* 
* Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
* Find the consonant (all other letters excluding vowels) with the maximum frequency.
* Return the sum of the two frequencies.
* 
* Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.
* 
* The frequency of a letter x is the number of times it occurs in the string.
* 
* 
* Example 1:
* 
* Input: s = "successes"
* 
* Output: 6
* 
* Explanation:
* 
* The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
* The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
* The output is 2 + 4 = 6.
* Example 2:
* 
* Input: s = "aeiaeia"
* 
* Output: 3
* 
* Explanation:
* 
* The vowels are: 'a' (frequency 3), 'e' ( frequency 2), 'i' (frequency 2). The maximum frequency is 3.
* There are no consonants in s. Hence, maximum consonant frequency = 0.
* The output is 3 + 0 = 3.
* 
* Constraints:
* 
* 1 <= s.length <= 100
* s consists of lowercase English letters only.
* 
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        string vows = "aeiou";
        unordered_map<char,int> freq;
        int max_vow = 0;
        int max_con = 0;

        for(char c : s)
            freq[c]++;

        // 문제 부분
        for(auto iter = freq.begin(); iter != freq.end(); iter++){
            if(vows.find(iter->first) != string::npos){
                max_vow = max(max_vow, iter->second);
            } else {
                max_con = max(max_con, iter->second);
            }
        }
        return max_con + max_vow;
    }
};

int main() {
	Solution sol;
	string s;
	int ans,res;

	s = "successes";
	ans = 6;
	res = sol.maxFreqSum(s);
	println("ans : {}, res : {}",ans,res);

	s = "aeiaeia";
	ans = 3;
	res = sol.maxFreqSum(s);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
