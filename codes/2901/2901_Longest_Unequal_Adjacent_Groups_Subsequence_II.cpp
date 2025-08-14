/**
 * 2901. Longest Unequal Adjacent Groups Subsequence II
 * You are given a string array words, and an array groups, both arrays having length n.
 * 
 * The hamming distance between two strings of equal length is the number of positions at which the corresponding characters are different.
 * 
 * You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds:
 * 
 * For adjacent indices in the subsequence, their corresponding groups are unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k.
 * words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, where 0 < j + 1 < k, for all indices in the subsequence.
 * Return a string array containing the words corresponding to the indices (in order) in the selected subsequence. If there are multiple answers, return any of them.
 * 
 * Note: strings in words may be unequal in length.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: words = ["bab","dab","cab"], groups = [1,2,2]
 * 
 * Output: ["bab","cab"]
 * 
 * Explanation: A subsequence that can be selected is [0,2].
 * 
 * - groups[0] != groups[2]
 * - words[0].length == words[2].length, and the hamming distance between them is 1.
 * So, a valid answer is [words[0],words[2]] = ["bab","cab"].
 * 
 * Another subsequence that can be selected is [0,1].
 * 
 * - groups[0] != groups[1]
 * - words[0].length == words[1].length, and the hamming distance between them is 1.
 * So, another valid answer is [words[0],words[1]] = ["bab","dab"].
 * 
 * It can be shown that the length of the longest subsequence of indices that satisfies the conditions is 2.
 * 
 * Example 2:
 * 
 * Input: words = ["a","b","c","d"], groups = [1,2,3,4]
 * 
 * Output: ["a","b","c","d"]
 * 
 * Explanation: We can select the subsequence [0,1,2,3].
 * 
 * It satisfies both conditions.
 * 
 * Hence, the answer is [words[0],words[1],words[2],words[3]] = ["a","b","c","d"].
 * 
 * It has the longest length among all subsequences of indices that satisfy the conditions.
 * 
 * Hence, it is the only answer.
 * 
 * 
 * 
 * Constraints:
 * 
 * 1 <= n == words.length == groups.length <= 1000
 * 1 <= words[i].length <= 10
 * 1 <= groups[i] <= n
 * words consists of distinct strings.
 * words[i] consists of lowercase English letters.
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
	vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
		vector<string> ret;
		//ret.push_back(words[0]);
		for(int i = 1; i< groups.size() ; ++i){
			if(groups[i] != groups[i-1] &&
			   words[i].length() == words[i-1].length()){
				int ham_distance = 0;
				for(int j = 0 ; j < words[i].length(); ++j){
					if(words[i][j] != words[i-1][j])
						++ham_distance;
				}
				if(ham_distance ==1){
					ret.push_back(words[i]);
				}
			}
		}
		return ret;
	}
};
#else
class Solution {
public:
    int hamming(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i)
            if (a[i] != b[i]) ++diff;
        return diff;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);       // dp[i] = i에서 끝나는 최장 경로 길이
        vector<int> prev(n, -1);    // prev[i] = 이전 노드

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] &&
                    words[i].size() == words[j].size() &&
                    hamming(words[i], words[j]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }

        // 가장 긴 경로의 끝을 찾음
        int max_len = 0, end_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > max_len) {
                max_len = dp[i];
                end_idx = i;
            }
        }

        // 경로 복원
        vector<string> result;
        for (int i = end_idx; i != -1; i = prev[i]) {
            result.push_back(words[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
#endif
void ans_print(vector<string> ans, vector<string> res){
	println("ans : {}",ans);
	for(const string& s: ans)
		println("{}",s);
	println("res : {}",res);
	for(const string& s: res)
		println("{}",s);


}
int main() {
	Solution sol;
	vector<string> words;
	vector<int> groups;
	vector<string> ans,res;

	words = {"bab","dab","cab"}, groups = {1,2,2};
	ans = {"bab","cab"};
	res = sol.getWordsInLongestSubsequence(words, groups);
	ans_print(ans,res);
	words = {"a","b","c","d"}, groups = {1,2,3,4};
	ans = {"a","b","c","d"};
	res = sol.getWordsInLongestSubsequence(words, groups);
	ans_print(ans,res);

	return 0;
}
