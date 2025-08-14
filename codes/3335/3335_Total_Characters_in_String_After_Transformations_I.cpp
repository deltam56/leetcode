/**
 * 3335. Total Characters in String After Transformations I
 * You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:
 * 
 * If the character is 'z', replace it with the string "ab".
 * Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
 * Return the length of the resulting string after exactly t transformations.
 * 
 * Since the answer may be very large, return it modulo 109 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: s = "abcyy", t = 2
 * 
 * Output: 7
 * 
 * Explanation:
 * 
 * First Transformation (t = 1):
 * 'a' becomes 'b'
 * 'b' becomes 'c'
 * 'c' becomes 'd'
 * 'y' becomes 'z'
 * 'y' becomes 'z'
 * String after the first transformation: "bcdzz"
 * Second Transformation (t = 2):
 * 'b' becomes 'c'
 * 'c' becomes 'd'
 * 'd' becomes 'e'
 * 'z' becomes "ab"
 * 'z' becomes "ab"
 * String after the second transformation: "cdeabab"
 * Final Length of the string: The string is "cdeabab", which has 7 characters.
 * Example 2:
 * 
 * Input: s = "azbk", t = 1
 * 
 * Output: 5
 * 
 * Explanation:
 * 
 * First Transformation (t = 1):
 * 'a' becomes 'b'
 * 'z' becomes "ab"
 * 'b' becomes 'c'
 * 'k' becomes 'l'
 * String after the first transformation: "babcl"
 * Final Length of the string: The string is "babcl", which has 5 characters.
 * 
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 10^5
 * s consists only of lowercase English letters.
 * 1 <= t <= 10^5
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
					 //
#define MODMAX 1000000007
#if 0
class Solution {
public:
	int lengthAfterTransformations(string s, int t) {
		int count = 0;
		int iternum = 0;
		string tmp_str = s;
		while(iternum != t){
			for(int i = 0 ; i < tmp_str.length() ; ++i){
				if(tmp_str[i] != 'z'){
					tmp_str += tmp_str[i]+1;
				}else{
					tmp_str += "ab";
				}
				tmp_str = tmp_str.substr(1);
			}
			++iternum;
		}
		count = tmp_str.length();
		return count % MODMAX;
	}
};
#else
class Solution {
public:
	int lengthAfterTransformations(string s, int t) {
		// dp[ch - 'a'][i]: 문자 ch가 i회 변환 후 생성하는 문자 개수
		vector<vector<long long>> dp(26, vector<long long>(t + 1, 0));

		// 초기 상태: 변환 0회 -> 길이 1
		for (int ch = 0; ch < 26; ++ch)
			dp[ch][0] = 1;

		// DP 계산
		for (int i = 1; i <= t; ++i) {
			for (int ch = 0; ch < 26; ++ch) {
				if (ch == 25) // 'z'
					dp[ch][i] = (dp[0][i-1] + dp[1][i-1]) % MOD; // 'a' + 'b'
				else
					dp[ch][i] = dp[ch+1][i-1]; // 다음 문자로 변환됨
			}
		}

		// 최종 문자열 길이 계산
		long long total = 0;
		for (char c : s) {
			total = (total + dp[c - 'a'][t]) % MOD;
		}

		return total;
	}
};
#endif
int main() {
	Solution sol;
	string s;
	int t;
	int ans, res;

	s = "abcyy", t = 2;
	ans = 7;
	res = sol.lengthAfterTransformations(s,t);
	println("ans : {} res : {}",ans,res);

	s = "azbk", t = 1;
	ans = 5;
	res = sol.lengthAfterTransformations(s,t);
	println("ans : {} res : {}",ans,res);

	return 0;
}
