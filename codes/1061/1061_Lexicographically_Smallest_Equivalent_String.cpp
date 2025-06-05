/**
 * 1061. Lexicographically Smallest Equivalent String
 * You are given two strings of the same length s1 and s2 and a string baseStr.
 * 
 * We say s1[i] and s2[i] are equivalent characters.
 * 
 * For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
 * Equivalent characters follow the usual rules of any equivalence relation:
 * 
 * Reflexivity: 'a' == 'a'.
 * Symmetry: 'a' == 'b' implies 'b' == 'a'.
 * Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
 * For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.
 * 
 * Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: s1 = "parker", s2 = "morris", baseStr = "parser"
 * Output: "makkek"
 * Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
 * The characters in each group are equivalent and sorted in lexicographical order.
 * So the answer is "makkek".
 * Example 2:
 * 
 * Input: s1 = "hello", s2 = "world", baseStr = "hold"
 * Output: "hdld"
 * Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
 * So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".
 * Example 3:
 * 
 * Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
 * Output: "aauaaaaada"
 * Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".
 *  
 * 
 * Constraints:
 * 
 * 1 <= s1.length, s2.length, baseStr <= 1000
 * s1.length == s2.length
 * s1, s2, and baseStr consist of lowercase English letters.
 **/

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
	string smallestEquivalentString(string s1, string s2, string baseStr) {
		unordered_map<char,char> cmpmap;
		string res = "";
		for(int i = 0 ; i < s1.length() ; ++i){
			cmpmap[s1[i]] = cmpmap[s1[i]] == 0 ? s2[i] :
												min(cmpmap[s1[i]],s2[i]);
			cmpmap[s2[i]] = cmpmap[s2[i]] == 0 ? s1[i] :
												min(cmpmap[s2[i]],s1[i]);
		}

		for (const char c : baseStr){
			res.push_back(cmpmap[c]);
		}

		return res;
	}
};
#else
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for (int i = 0; i < 26; ++i)
            parent[i] = i;
        for (int i = 0; i < s1.length(); ++i) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }
        string res = "";
        for (char c : baseStr) {
            char smallest = find(c - 'a') + 'a';
            res += smallest;
        }
        return res;
    }
};
#endif
int main() {
	Solution sol;
	string s1,s2,baseStr;
	string ans,res;

	s1 = "parker", s2 = "morris", baseStr = "parser";
	ans = "makkek";
	res = sol.smallestEquivalentString(s1,s2,baseStr);
	println("ans : {}, res : {}",ans,res);

	s1 = "hello", s2 = "world", baseStr = "hold";
	ans = "hdld";
	res = sol.smallestEquivalentString(s1,s2,baseStr);
	println("ans : {}, res : {}",ans,res);

	s1 = "leetcode", s2 = "programs", baseStr = "sourcecode";
	ans = "aauaaaaada";
	res = sol.smallestEquivalentString(s1,s2,baseStr);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
