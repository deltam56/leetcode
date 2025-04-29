/**
* 1399. Count Largest Group
* You are given an integer n.
* 
* We need to group the numbers from 1 to n according to the sum of its digits. For example, the numbers 14 and 5 belong to the same group, whereas 13 and 3 belong to different groups.
* 
* Return the number of groups that have the largest size, i.e. the maximum number of elements.
* 
*  
* 
* Example 1:
* 
* Input: n = 13
* Output: 4
* Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
* [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
* There are 4 groups with largest size.
* Example 2:
* 
* Input: n = 2
* Output: 2
* Explanation: There are 2 groups [1], [2] of size 1.
*  
* 
* Constraints:
* 
* 1 <= n <= 10^4
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
using namespace std; //편의성위해..

class Solution {
public:
    int countLargestGroup(int n) {
		unordered_map<int,int> group_hash;
		for(int i = 1; i<= n;i++){
			div_t dv(i,0);
			int divnum = 0;
			while(dv.quot > 9){
				dv = div(dv.quot, 10);
				divnum = divnum + dv.rem;
			}
			divnum = divnum+dv.quot;
			group_hash[divnum] ++;
		}
		int max_val = 0;
		int count = 0;
		for (auto& [key, val] : group_hash) {
		    if (val > max_val) {
		        max_val = val;
		        count = 1;
		    } else if (val == max_val) {
		        count++;
		    }
		}
		return count;
    }
};

int main() {
	Solution sol;
	int n;
	int ans, res;

	n = 13;
	ans = 4;
	res = sol.countLargestGroup(n);
	println("ans : {}, res :{}", ans,res);

	n = 2;
	ans = 2;
	res = sol.countLargestGroup(n);
	println("ans : {}, res :{}", ans,res);


	cout << "Accepted!" <<endl;
    return 0;
}
