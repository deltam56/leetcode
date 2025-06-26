/**
* 2311. Longest Binary Subsequence Less Than or Equal to K
* You are given a binary string s and a positive integer k.
* 
* Return the length of the longest subsequence of s that makes up a binary
* number less than or equal to k.
* 
* Note:
* 
* The subsequence can contain leading zeroes.
* The empty string is considered to be equal to 0.
* A subsequence is a string that can be derived from another string by deleting
* some or no characters without changing the order of the remaining characters.
* 
* 
* Example 1:
* 
* Input: s = "1001010", k = 5
* Output: 5
* Explanation: The longest subsequence of s that makes up a binary number less
* than or equal to 5 is "00010", as this number is equal to 2 in decimal.
* Note that "00100" and "00101" are also possible, which are equal to 4 and 5
* in decimal, respectively.
* The length of this subsequence is 5, so 5 is returned.
* Example 2:
* 
* Input: s = "00101001", k = 1
* Output: 6
* Explanation: "000001" is the longest subsequence of s that makes up a binary
* number less than or equal to 1, as this number is equal to 1 in decimal.
* The length of this subsequence is 6, so 6 is returned.
* 
* 
* Constraints:
* 
* 1 <= s.length <= 1000
* s[i] is either '0' or '1'.
* 1 <= k <= 10^9
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
#if 0
class Solution {
public:
    int longestSubsequence(string s, int k) {
		//역순 진행 하면서
		//0은 넣기
		//1 은 보고 넣기
		string result="";
		for(int i = s.length()-1 ; i >= 0 ; --i){
			if(s[i]=='0'){
				result = '0'+result;
			}
			else{
				string tmp = '1'+result;
				if(stoll((tmp),nullptr,2) <= k)
					result='1'+result;
			}
		}
		return result.length();
    }
};
#else
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        long long value = 0;
        int bit = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                if (bit < 32) {
                    if ((value + (1LL << bit)) <= k) {
                        value += (1LL << bit);
                        count++;
                        bit++;
                    } else {
                        bit++;
                    }
                }
            } else {
                count++;
                bit++;
            }
        }

        return count;
    }
};
#endif
int main() {
	Solution sol;
	string s;
	int k;
	int ans, res;

	s = "1001010", k = 5;
	ans = 5;
	res = sol.longestSubsequence(s,k);
	println ("ans : {} res : {}",ans,res);

	s = "00101001", k = 1;
	ans = 6;
	res = sol.longestSubsequence(s,k);
	println ("ans : {} res : {}",ans,res);

    return 0;
}
