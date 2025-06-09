/**
* 440. K-th Smallest in Lexicographical Order
* Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
* 
*  
* 
* Example 1:
* 
* Input: n = 13, k = 2
* Output: 10
* Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
* Example 2:
* 
* Input: n = 1, k = 1
* Output: 1
*  
* 
* Constraints:
* 
* 1 <= k <= n <= 10^9
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <queue>

using namespace std; //편의성위해..
#if 0
class Solution {
public:
    int findKthNumber(int n, int k) {
        priority_queue<string,vector<string>,greater<string>> pq;
		for(int i = 1; i <= n ; ++i){
			pq.push(to_string(i));
		}

		int i = 1;
		while(!pq.empty()){
			if(i == k)
				return atoi(pq.top().c_str());
			else
				pq.pop();
			++i;
		}
		return 0;
    }
};
#else
class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        --k;

        while (k > 0) {
            long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr += 1;
                k -= steps;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }

    long countSteps(long n, long curr, long next) {
        long steps = 0;
        while (curr <= n) {
            steps += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};
#endif
int main() {
	Solution sol;
	int n, k;
	int ans,res;

	n = 13, k = 2;
	ans = 10;
	res = sol.findKthNumber(n,k);
	println("ans: {} , res : {}", ans,res);

	n = 1, k = 1;
	ans = 1;
	res = sol.findKthNumber(n,k);
	println("ans: {} , res : {}", ans,res);

    return 0;
}
