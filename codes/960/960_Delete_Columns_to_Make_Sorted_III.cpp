/**
* 960. Delete Columns to Make Sorted III
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <numeric>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int> idxs(strs[0].size());
        iota(idxs.begin(), idxs.end(), 0);

        int cnt = 0;

        for (int i = 0; i < (int)strs.size(); ++i) {
            if (idxs.size() <= 1) break;

            auto it = idxs.begin();
            int prevCol = *it;
            ++it;

            while (it != idxs.end()) {
                int curCol = *it;

                if (strs[i][curCol] < strs[i][prevCol]) {
                    it = idxs.erase(it);
                    ++cnt;
                } else {
                    prevCol = curCol;
                    ++it;
                }
            }
        }

        return cnt;
    }
};

int main() {
	Solution sol;
	vector<string> strs;
	int ans,res;

	strs = {"babca","bbazb"};
	ans = 3;
	res = sol.minDeletionSize(strs);
	println("ans : {}, res : {}",ans,res);

	strs = {"edcba"};
	ans = 4;
	res = sol.minDeletionSize(strs);
	println("ans : {}, res : {}",ans,res);

	strs = {"ghi","def","abc"};
	ans = 0;
	res = sol.minDeletionSize(strs);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
