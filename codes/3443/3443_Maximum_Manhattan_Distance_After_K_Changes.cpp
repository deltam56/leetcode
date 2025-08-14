/**
* 3443. Maximum Manhattan Distance After K Changes
* You are given a string s consisting of the characters 'N', 'S', 'E', and 'W', where s[i] indicates movements in an infinite grid:
* 
* 'N' : Move north by 1 unit.
* 'S' : Move south by 1 unit.
* 'E' : Move east by 1 unit.
* 'W' : Move west by 1 unit.
* Initially, you are at the origin (0, 0). You can change at most k characters to any of the four directions.
* 
* Find the maximum Manhattan distance from the origin that can be achieved at any time while performing the movements in order.
* 
* The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
* 
* 
* Example 1:
* 
* Input: s = "NWSE", k = 1
* 
* Output: 3
* 
* Explanation:
* 
* Change s[2] from 'S' to 'N'. The string s becomes "NWNE".
* 
* Movement	Position (x, y)	Manhattan Distance	Maximum
* s[0] == 'N'	(0, 1)	0 + 1 = 1	1
* s[1] == 'W'	(-1, 1)	1 + 1 = 2	2
* s[2] == 'N'	(-1, 2)	1 + 2 = 3	3
* s[3] == 'E'	(0, 2)	0 + 2 = 2	3
* The maximum Manhattan distance from the origin that can be achieved is 3. Hence, 3 is the output.
* 
* Example 2:
* 
* Input: s = "NSWWEW", k = 3
* 
* Output: 6
* 
* Explanation:
* 
* Change s[1] from 'S' to 'N', and s[4] from 'E' to 'W'. The string s becomes "NNWWWW".
* 
* The maximum Manhattan distance from the origin that can be achieved is 6. Hence, 6 is the output.
* 
* 
* 
* Constraints:
* 
* 1 <= s.length <= 10^5
* 0 <= k <= s.length
* s consists of only 'N', 'S', 'E', and 'W'.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std; //편의성위해..
#if 0
class Solution {
	char invert(char c){
		switch (c){
		case 'N':
			return 'S';
		case 'W':
			return 'E';
		case 'E':
			return 'W';
		case 'S':
			return 'N';
		}
		return 'X';
	}
	int computepos(string s){
		pair<int,int> pos = {0,0};
		int max_distance = INT_MIN;
		for(const char c : s){
			switch (c){
			case 'N':
				pos.first ++;
				break;
			case 'W':
				pos.second --;
				break;
			case 'E':
				pos.second ++;
				break;
			case 'S':
				pos.first --;
				break;
			}
			max_distance = max(max_distance, abs(pos.first) + abs(pos.second));
		}
		return max_distance;
	}
public:
    int maxDistance(string s, int k) {
		unordered_map<char,int> pos_freq;
		char min_h,min_v;
		int conv_count = 0;
		// freq count
		for(char c : s){
			pos_freq[c] ++;
		}

		// MINVALUE of N vs S / E vs W
		min_v = pos_freq['N'] >= pos_freq['S'] ? 'S' : 'N';
		min_h = pos_freq['W'] >= pos_freq['E'] ? 'E' : 'W';

		for(int i = 0; i < s.length() ; ++i){
			if((s[i] == min_v || s[i] == min_h )&& conv_count < k){
				conv_count++;
				s[i] = invert(s[i]);
			}
		}
		println("{}",s);
		return computepos(s);
    }
};
#else
class Solution {
    const char dirs[4] = {'N', 'S', 'E', 'W'};

    pair<int, int> move(pair<int,int> pos, char c) {
        switch(c) {
            case 'N': return {pos.first, pos.second + 1};
            case 'S': return {pos.first, pos.second - 1};
            case 'E': return {pos.first + 1, pos.second};
            case 'W': return {pos.first - 1, pos.second};
        }
        return pos;
    }

    int simulate(const string& s) {
        int x = 0, y = 0;
        int max_dist = 0;
        for (char c : s) {
            tie(x, y) = move({x, y}, c);
            max_dist = max(max_dist, abs(x) + abs(y));
        }
        return max_dist;
    }

public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int base = simulate(s);
        int best = base;

        // Step 1: 후보 인덱스 뽑기
        vector<tuple<int, char, int>> candidates;  // {index, new_char, gain}

        for (int i = 0; i < n; ++i) {
            char original = s[i];
            for (char d : dirs) {
                if (d == original) continue;
                s[i] = d;
                int new_dist = simulate(s);
                int gain = new_dist - base;
                if (gain > 0) {
                    candidates.emplace_back(i, d, gain);
                }
            }
            s[i] = original; // 원복
        }

        // Step 2: gain 높은 순으로 정렬
        sort(candidates.begin(), candidates.end(), [](auto& a, auto& b) {
            return get<2>(a) > get<2>(b);
        });

        // Step 3: 상위 maxCandidates 개만 골라서 조합 완전탐색
        const int maxCandidates = 12; // 12C2 x 3^2 = 1980
        vector<tuple<int, char>> selected;
        vector<int> used(n, 0);

        function<void(int, int)> dfs = [&](int depth, int start) {
            if (depth == k) {
                string temp = s;
                for (auto &[i, c] : selected) temp[i] = c;
                best = max(best, simulate(temp));
                return;
            }

            for (int j = start; j < min((int)candidates.size(), maxCandidates); ++j) {
                auto [i, c, _] = candidates[j];
                if (used[i]) continue; // 하나의 인덱스는 1번만 변경
                used[i] = 1;
                selected.emplace_back(i, c);
                dfs(depth + 1, j + 1);
                selected.pop_back();
                used[i] = 0;
            }
        };

        dfs(0, 0);
        return best;
    }
};
#endif
int main() {
	Solution sol;
	string s;
	int k;
	int ans,res;

	s = "WENSS";
	k = 2;
	ans = 5;
	res = sol.maxDistance(s,k);
	println("ans : {} , res : {} ",ans,res);

	s = "ENNSW";
	k = 1;
	ans = 4;
	res = sol.maxDistance(s,k);
	println("ans : {} , res : {} ",ans,res);

	s = "NWSE";
	k = 1;
	ans = 3;
	res = sol.maxDistance(s,k);
	println("ans : {} , res : {} ",ans,res);

	s = "NSWWEW";
	k = 3;
	ans = 6;
	res = sol.maxDistance(s,k);
	println("ans : {} , res : {} ",ans,res);

    return 0;
}
