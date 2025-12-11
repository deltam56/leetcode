/**
* 1925. Count Square Sum Triples
* A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
* 
* Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
* 
* 
* 
* Example 1:
* 
* Input: n = 5
* Output: 2
* Explanation: The square triples are (3,4,5) and (4,3,5).
* Example 2:
* 
* Input: n = 10
* Output: 4
* Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
* 
* 
* Constraints:
* 
* 1 <= n <= 250
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>

using namespace std;
#if 0
class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for (int c = 1; c <= n; ++c) {
            int c2 = c * c;
            for (int a = 1; a <= n; ++a) {
                for (int b = 1; b <= n; ++b) {
                    if (a*a + b*b == c2)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
#else
class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
		for(int i = 1; i <= n ; ++i){
			for(int j = i+1 ; j <= n ;++j){
				int sq = (i*i)+(j*j);
				int r = sqrt(sq);
				if(r*r == sq && r<= n)
					cnt+=2;
			}
		}
        return cnt;
    }
};
#endif
int main() {
	Solution sol;
	int n;
	int ans,res;

	n = 5;
	ans = 2;
	res = sol.countTriples(n);
	println("ans : {}, res : {}",ans,res);

	n = 10;
	ans = 4;
	res = sol.countTriples(n);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
