/**
* 1358. Number of Substrings Containing All Three Characters
* Given a string s consisting only of characters a, b and c.
* 
* Return the number of substrings containing at least one occurrence of all these characters a, b and c.
* 
* 
* 
* Example 1:
* 
* Input: s = "abcabc"
* Output: 10
* Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).
* Example 2:
* 
* Input: s = "aaacb"
* Output: 3
* Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".
* Example 3:
* 
* Input: s = "abc"
* Output: 1
* 
* 
* Constraints:
* 
* 3 <= s.length <= 5 x 10^4
* s only consists of a, b or c characters.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int counts[3] = {0, 0, 0};
        int left = 0;
        int answer = 0;

        for (int right = 0; right < static_cast<int>(s.length()); ++right) {
            counts[s[right] - 'a']++;

            while (counts[0] > 0 &&
                   counts[1] > 0 &&
                   counts[2] > 0) {
                counts[s[left] - 'a']--;
                left++;
            }

            answer += left;
        }

        return answer;
    }
};

int main() {
	Solution sol;
	string s;
	int ans,res;

	s = "abcabc";
	ans = 10;
	res = sol.numberOfSubstrings(s);
	println("ans : {}, res : {}",ans,res);

	s = "aaacb";
	ans = 3;
	res = sol.numberOfSubstrings(s);
	println("ans : {}, res : {}",ans,res);

	s = "abc";
	ans = 1;
	res = sol.numberOfSubstrings(s);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
