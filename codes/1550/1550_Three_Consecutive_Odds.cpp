/**
* 1550. Three Consecutive Odds
* Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
*  
* 
* Example 1:
* 
* Input: arr = [2,6,4,1]
* Output: false
* Explanation: There are no three consecutive odds.
* Example 2:
* 
* Input: arr = [1,2,34,3,4,5,7,23,12]
* Output: true
* Explanation: [5,7,23] are three consecutive odds.
*  
* 
* Constraints:
* 
* 1 <= arr.length <= 1000
* 1 <= arr[i] <= 1000
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int flagcount = 0;
        for(auto& num:arr){
            if(num % 2 == 0)
                flagcount = 0;
			else
				flagcount++;
            if(flagcount>2)
                return true;
        }
        return false;
    }
};
int main() {
	Solution sol;
	vector<int> arr;
	bool ans,res;

	arr ={1,2,1,1};
	ans = false;
	res = sol.threeConsecutiveOdds(arr);
	println("ans : {} res : {}",ans,res);

    return 0;
}
