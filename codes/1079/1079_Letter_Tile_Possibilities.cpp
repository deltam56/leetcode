/*
1079. Letter Tile Possibilities

You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.



Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: tiles = "AAABBC"
Output: 188
Example 3:

Input: tiles = "V"
Output: 1


Constraints:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.

*/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>

using namespace std; //편의성위해..
#if 0
class Solution {
public:
    int numTilePossibilities(string tiles) {
		int res=0;
		string dtiles = tiles+tiles;
		unordered_map<string,int> tmpres;
		
		for(int j = 1; j<=tiles.length(); j++){
			for(int i = 0 ;(i+j)<dtiles.length();i++){
				string ss = dtiles.substr(i,j);
				if(tmpres.find(ss) == tmpres.end()){
				   res ++;
				}
				tmpres[ss]= 1;
			}
		}

		return res;
    }
};
#else
class Solution {
public:
    int backtrack(vector<int>& freq) {
        int cnt = 0;

        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0)
                continue;

            cnt++;
            freq[i]--;
            cnt += backtrack(freq);
            // Backtracking
            freq[i]++;
        }
        return cnt;
    }

public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);

        for (char c : tiles)
            freq[c - 'A']++;

        return backtrack(freq);
    }
};

#endif

int main() {
	Solution sol;	
	string tiles;
	int ans, res;

	tiles = "AAB";
	ans = 8;
	res = sol.numTilePossibilities(tiles);
	println("ans : {}  res : {}",ans,res);
	assert(ans==res);

	tiles = "AAABBC";
	ans = 188;
	res = sol.numTilePossibilities(tiles);
	println("ans : {}  res : {}",ans,res);
	assert(ans==res);

	tiles = "V";
	ans = 1;
	res = sol.numTilePossibilities(tiles);
	println("ans : {}  res : {}",ans,res);
	assert(ans==res);

	cout << "Accepted!" <<endl;
    return 0;
}
