/**
* 3136. Valid Word
* A word is considered valid if:
* 
* It contains a minimum of 3 characters.
* It contains only digits (0-9), and English letters (uppercase and lowercase).
* It includes at least one vowel.
* It includes at least one consonant.
* You are given a string word.
* 
* Return true if word is valid, otherwise, return false.
* 
* Notes:
* 
* 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
* A consonant is an English letter that is not a vowel.
* 
* 
* Example 1:
* 
* Input: word = "234Adas"
* 
* Output: true
* 
* Explanation:
* 
* This word satisfies the conditions.
* 
* Example 2:
* 
* Input: word = "b3"
* 
* Output: false
* 
* Explanation:
* 
* The length of this word is fewer than 3, and does not have a vowel.
* 
* Example 3:
* 
* Input: word = "a3$e"
* 
* Output: false
* 
* Explanation:
* 
* This word contains a '$' character and does not have a consonant.
* 
* 
* 
* Constraints:
* 
* 1 <= word.length <= 20
* word consists of English uppercase and lowercase letters, digits, '@', '#', and '$'.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <cctype>

using namespace std; //편의성위해..
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word) {
            if (!isalnum(c)) return false;

            if (isalpha(c)) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    hasVowel = true;
                else
                    hasConsonant = true;
            }
        }

        return hasVowel && hasConsonant;
    }
};
int main() {
	Solution sol;
	string word;
	bool ans,res;

	word = "234Adas";
	ans = true;
	res = sol.isValid(word);
	println("ans : {} res : {}", ans,res);

	word = "b3";
	ans = false;
	res = sol.isValid(word);
	println("ans : {} res : {}", ans,res);

	word = "a3$e";
	ans = false;
	res = sol.isValid(word);
	println("ans : {} res : {}", ans,res);

    return 0;
}
