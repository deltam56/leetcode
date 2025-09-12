/**
* 3227. Vowels Game in a String
* Alice and Bob are playing a game on a string.
* 
* You are given a string s, Alice and Bob will take turns playing the following game where Alice starts first:
* 
* On Alice's turn, she has to remove any non-empty substring from s that contains an odd number of vowels.
* On Bob's turn, he has to remove any non-empty substring from s that contains an even number of vowels.
* The first player who cannot make a move on their turn loses the game. We assume that both Alice and Bob play optimally.
* 
* Return true if Alice wins the game, and false otherwise.
* 
* The English vowels are: a, e, i, o, and u.
* 
* 
* 
* Example 1:
* 
* Input: s = "leetcoder"
* 
* Output: true
* 
* Explanation:
* Alice can win the game as follows:
* 
* Alice plays first, she can delete the underlined substring in s = "leetcoder" which contains 3 vowels. The resulting string is s = "der".
* Bob plays second, he can delete the underlined substring in s = "der" which contains 0 vowels. The resulting string is s = "er".
* Alice plays third, she can delete the whole string s = "er" which contains 1 vowel.
* Bob plays fourth, since the string is empty, there is no valid play for Bob. So Alice wins the game.
* Example 2:
* 
* Input: s = "bbcd"
* 
* Output: false
* 
* Explanation:
* There is no valid play for Alice in her first turn, so Alice loses the game.
* 
* 
* 
* Constraints:
* 
* 1 <= s.length <= 10^5
* s consists only of lowercase English letters.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
		string vow = "aeiou"; //alice 가 최대한의 홀수개를 가져가야함 vow 있으면 무조건 이기는거아녀..?
		for(char c : s)
			if(vow.find(c) != string::npos)
				return true;
		return false;
    }
};

int main() {
	Solution sol;
	string s;
	bool ans,res;

	s = "leetcoder";
	ans = true;
	res = sol.doesAliceWin(s);
	println("ans : {}, res : {}",ans,res);

	s = "bbcd";
	ans = false;
	res = sol.doesAliceWin(s);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
