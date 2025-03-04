/**
* 72. Edit Distance
*
* Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

* You have the following three operations permitted on a word:
* 
* Insert a character
* Delete a character
* Replace a character
* 
* 
* Example 1:
* 
* Input: word1 = "horse", word2 = "ros"
* Output: 3
* Explanation:
* horse -> rorse (replace 'h' with 'r')
* rorse -> rose (remove 'r')
* rose -> ros (remove 'e')
* Example 2:
* 
* Input: word1 = "intention", word2 = "execution"
* Output: 5
* Explanation:
* intention -> inention (remove 't')
* inention -> enention (replace 'i' with 'e')
* enention -> exention (replace 'n' with 'x')
* exention -> exection (replace 'n' with 'c')
* exection -> execution (insert 'u')
* 
* 
* Constraints:
* 
* 0 <= word1.length, word2.length <= 500
* word1 and word2 consist of lowercase English letters.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

class Solution {
public:
    int minDistance(string word1, string word2) {
        int size_word1 = word1.length();
        int size_word2 = word2.length();
        int res = 0;
        vector<vector<int>> dp(size_word1+1, vector<int>(size_word2+1,0));

        for(int i = 0; i<size_word1+1 ; i++)
            dp[i][0] = i;
        for(int i = 0; i<size_word2+1 ; i++)
            dp[0][i] = i;


        for(int i = 1; i<size_word2+1;i++){
            for(int j = 1;j<size_word1+1;j++){
                if(word2[i-1] == word1[j-1])
                    dp[j][i] = dp[j-1][i-1];
                else{
                    dp[j][i] = min({dp[j - 1][i], dp[j][i - 1], dp[j - 1][i - 1]}) + 1;
                }
            }
        }

        res = dp[size_word2][size_word1];
        return res;
    }
};
int main() {
	Solution sol;
	string word1,word2;
	int ans,res;

	word1 = "horse";
	word2 = "ros";
	ans = 3;
	res = sol.minDistance(word1,word2);
	println("ans : {} , res : {} ",ans,res);
	assert(ans==res);

	word1 = "intention";
	word2 = "execution";
	ans = 5;
	res = sol.minDistance(word1,word2);
	println("ans : {} , res : {} ",ans,res);
	assert(ans==res);

	cout << "Accepted!" <<endl;
    return 0;
}
