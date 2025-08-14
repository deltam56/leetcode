/**
* 898. Bitwise ORs of Subarrays
* Medium
* Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
* 
* The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
* 
* A subarray is a contiguous non-empty sequence of elements within an array.
* 
*  
* 
* Example 1:
* 
* Input: arr = [0]
* Output: 1
* Explanation: There is only one possible result: 0.
* Example 2:
* 
* Input: arr = [1,1,2]
* Output: 3
* Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
* These yield the results 1, 1, 2, 1, 3, 3.
* There are 3 unique values, so the answer is 3.
* Example 3:
* 
* Input: arr = [1,2,4]
* Output: 6
* Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
*  
* 
* Constraints:
* 
* 1 <= arr.length <= 5 * 104
* 0 <= arr[i] <= 109
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_set>

using namespace std; //편의성위해..
class Solution {
public:
#if 0
    int subarrayBitwiseORs(vector<int>& arr) {
		unordered_set<int>  val_check;
		for(int i = 0; i < arr.size(); ++ i){
			int tmp_or = 0;
			for(int j = i; j<arr.size() ; ++j){
				tmp_or = tmp_or | arr[j];
				val_check.insert(tmp_or);
			}
		}
		return val_check.size();
    }
#else
	int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> result;
    unordered_set<int> cur;
    unordered_set<int> prev;

    for (int num : arr) {
        unordered_set<int> next;
        next.insert(num);
        for (int x : prev) {
            next.insert(x | num);
        }
        prev = std::move(next);
        result.insert(prev.begin(), prev.end());
    }

    return result.size();
}
#endif
};
int main() {
	Solution sol;
	vector<int> arr;
	int ans, res;

	arr = {0};
	ans = 1;
	res = sol.subarrayBitwiseORs(arr);
	println("ans : {} , res : {}",ans, res);

	arr = {1,1,2};
	ans = 3;
	res = sol.subarrayBitwiseORs(arr);
	println("ans : {} , res : {}",ans, res);

	arr = {1,2,4};
	ans = 6;
	res = sol.subarrayBitwiseORs(arr);
	println("ans : {} , res : {}",ans, res);

    return 0;
}
