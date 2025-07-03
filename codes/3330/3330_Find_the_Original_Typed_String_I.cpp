/**
* 3330. Find the Original Typed String I
* Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
* 
* Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
* 
* You are given a string word, which represents the final output displayed on Alice's screen.
* 
* Return the total number of possible original strings that Alice might have intended to type.
* 
* 
* 
* Example 1:
* 
* Input: word = "abbcccc"
* 
* Output: 5
* 
* Explanation:
* 
* The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".
* 
* Example 2:
* 
* Input: word = "abcd"
* 
* Output: 1
* 
* Explanation:
* 
* The only possible string is "abcd".
* 
* Example 3:
* 
* Input: word = "aaaa"
* 
* Output: 4
* 
* 
* 
* Constraints:
* 
* 1 <= word.length <= 100
* word consists only of lowercase English letters.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>

using namespace std; //편의성위해..
class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> group_lengths;
        int count = 1;
        for (int i = 1; i < word.size(); ++i) {
            if (word[i] == word[i - 1]) {
                count++;
            } else {
                group_lengths.push_back(count);
                count = 1;
            }
        }
        group_lengths.push_back(count);

        int result = 1;
        for (int len : group_lengths) {
            if (len > 1) {
                result += len - 1;
            }
        }
        return result;
    }
};
int main() {
	Solution sol;
	string word;
	int ans,res;

	word = "abbcccc";
	ans = 5;
	res = sol.possibleStringCount(word);
	println("ans : {} , res : {}",ans,res);

	word = "abcd";
	ans = 1;
	res = sol.possibleStringCount(word);
	println("ans : {} , res : {}",ans,res);

	word = "aaaa";
	ans = 4;
	res = sol.possibleStringCount(word);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
