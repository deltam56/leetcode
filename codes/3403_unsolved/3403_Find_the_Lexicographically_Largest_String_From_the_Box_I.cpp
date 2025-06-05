/**
* 3403. Find the Lexicographically Largest String From the Box I
* You are given a string word, and an integer numFriends.
* 
* Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:
* 
* word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
* All the split words are put into a box.
* Find the lexicographically largest string from the box after all the rounds are finished.
* 
* 
* 
* Example 1:
* 
* Input: word = "dbca", numFriends = 2
* 
* Output: "dbc"
* 
* Explanation:
* 
* All possible splits are:
* 
* "d" and "bca".
* "db" and "ca".
* "dbc" and "a".
* Example 2:
* 
* Input: word = "gggg", numFriends = 4
* 
* Output: "g"
* 
* Explanation:
* 
* The only possible split is: "g", "g", "g", and "g".
* 
* 
* 
* Constraints:
* 
* 1 <= word.length <= 5 * 10^3
* word consists only of lowercase English letters.
* 1 <= numFriends <= word.length
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
class Solution {
// 커팅 포인트 조합을 저장할 리스트
vector<vector<int>> allCuts;

void generateCuts(int n, int k, int start, vector<int>& path, int wordLength) {
    if (path.size() == k) {
        // 유효한 커팅인지 확인: 각 조각 길이 >= 1
        bool valid = true;
        int prev = 0;
        for (int cut : path) {
            if (cut - prev <= 0) {
                valid = false;
                break;
            }
            prev = cut;
        }
        if (wordLength - prev <= 0) valid = false;

        if (valid) allCuts.push_back(path);
        return;
    }
    for (int i = start; i < wordLength; ++i) {
        path.push_back(i);
        generateCuts(n, k, i + 1, path, wordLength);
        path.pop_back();
    }
}

// 커팅 포인트로 word를 나누는 함수
vector<string> splitWord(const string& word, const vector<int>& cuts) {
    vector<string> parts;
    int prev = 0;
    for (int cut : cuts) {
        parts.push_back(word.substr(prev, cut - prev));
        prev = cut;
    }
    parts.push_back(word.substr(prev)); // 마지막 조각
    return parts;
}

public:
    string answerString(string word, int numFriends) {
            int n = word.size();
    int cutsNeeded = numFriends - 1;

    allCuts.clear();
    vector<int> path;

    // 자를 수 있는 위치는 1부터 n-1까지
generateCuts(n - 1, cutsNeeded, 1, path, n);

    string answer = "";
    for (const auto& cuts : allCuts) {
        vector<string> parts = splitWord(word, cuts);
        for (const string& part : parts) {
            answer = max(answer, part); // 사전순 최대 문자열 갱신
        }
    }

    return answer;
    }
};
int main() {
	Solution sol;
	string word;
	int numFriends;
	string ans, res;

	word = "dbca", numFriends = 2;
	ans = "dbc";
	res = sol.answerString(word,numFriends);
	println("ans : {} , res : {}",ans ,res);


	word = "gggg", numFriends = 4;
	ans = "g";
	res = sol.answerString(word,numFriends);
	println("ans : {} , res : {}",ans ,res);

    return 0;
}
