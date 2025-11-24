/**
 * 1930. Unique Length-3 Palindromic Subsequences
 * Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
 * 
 * Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
 * 
 * A palindrome is a string that reads the same forwards and backwards.
 * 
 * A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
 * 
 * For example, "ace" is a subsequence of "abcde".
 *  
 * 
 * Example 1:
 * 
 * Input: s = "aabca"
 * Output: 3
 * Explanation: The 3 palindromic subsequences of length 3 are:
 * - "aba" (subsequence of "aabca")
 * - "aaa" (subsequence of "aabca")
 * - "aca" (subsequence of "aabca")
 * Example 2:
 * 
 * Input: s = "adc"
 * Output: 0
 * Explanation: There are no palindromic subsequences of length 3 in "adc".
 * Example 3:
 * 
 * Input: s = "bbcbaba"
 * Output: 4
 * Explanation: The 4 palindromic subsequences of length 3 are:
 * - "bbb" (subsequence of "bbcbaba")
 * - "bcb" (subsequence of "bbcbaba")
 * - "bab" (subsequence of "bbcbaba")
 * - "aba" (subsequence of "bbcbaba")
 *  
 * 
 * Constraints:
 * 
 * 3 <= s.length <= 10^5
 * s consists of only lowercase English letters.
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_set>
using namespace std;

#if 1
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<string> strs;

        for (int i = 0; i < n - 1; ++i) {
            int mid = i + 1;

            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    for (int k = mid; k < j; ++k) {
                        string tmp;
                        tmp.push_back(s[i]);
                        tmp.push_back(s[k]);
                        tmp.push_back(s[j]);
                        strs.insert(tmp);
                    }
                    mid = j;
                }
            }
        }

        return strs.size();
    }
};
#else
class Solution {
public:
	int countPalindromicSubsequence(string s) {
		int n = s.size();

		// 각 문자('a' ~ 'z')의 첫 등장, 마지막 등장 위치
		vector<int> first(26, n);
		vector<int> last(26, -1);

		for (int i = 0; i < n; ++i) {
			int c = s[i] - 'a';
			first[c] = min(first[c], i);
			last[c]  = max(last[c], i);
		}

		int ans = 0;

		// 각 문자를 양 끝 문자로 본다.
		for (int c = 0; c < 26; ++c) {
			if (first[c] >= last[c]) continue;  // 두 번 이상 안 나오면 양 끝이 될 수 없음

			// first[c]와 last[c] 사이에 어떤 문자들이 있는지 체크
			bool inside[26] = {false};

			for (int i = first[c] + 1; i < last[c]; ++i) {
				inside[s[i] - 'a'] = true;
			}

			// 이 문자 c를 양 끝으로 했을 때 가능한 서로 다른 중간 문자 개수를 더한다.
			for (int x = 0; x < 26; ++x) {
				if (inside[x]) ans++;
			}
		}

		return ans;
	}
};
#endif
int main() {
	Solution sol;
	string s;
	int ans,res;

	s = "aabca";
	ans = 3;
	res = sol.countPalindromicSubsequence(s);
	println("ans : {}, res : {}",ans,res);

	s = "adc";
	ans = 0;
	res = sol.countPalindromicSubsequence(s);
	println("ans : {}, res : {}",ans,res);

	s = "bbcbaba";
	ans = 4;
	res = sol.countPalindromicSubsequence(s);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
