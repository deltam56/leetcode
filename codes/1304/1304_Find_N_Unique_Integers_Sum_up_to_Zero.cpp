/**
* 1304. Find N Unique Integers Sum up to Zero
* Given an integer n, return any array containing n unique integers such that they add up to 0.



Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0]


Constraints:

1 <= n <= 1000
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
		vector<int> ret;
		if( (n%2)!=0)
			ret.push_back(0);
		for(int i = 1; i <= (n/2) ; ++i){
			ret.push_back(i);
			ret.push_back(-1*i);
		}

		return ret;
    }
};

int main() {
	Solution sol;
	int n;
	vector<int> ans,res;

	n = 5;
	ans = {-7,-1,1,3,4};
	res = sol.sumZero(n);
	println("ans : {}, res :{}",ans,res);

	n = 3;
	ans = {-1,0,1};
	res = sol.sumZero(n);
	println("ans : {}, res :{}",ans,res);

	n = 1;
	ans = {0};
	res = sol.sumZero(n);
	println("ans : {}, res :{}",ans,res);

    return 0;
}
