/**
* 1200. Minimum Absolute Difference
* Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
* 
* Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
* 
* a, b are from arr
* a < b
* b - a equals to the minimum absolute difference of any two elements in arr
*  
* 
* Example 1:
* 
* Input: arr = [4,2,1,3]
* Output: [[1,2],[2,3],[3,4]]
* Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
* Example 2:
* 
* Input: arr = [1,3,6,10,15]
* Output: [[1,3]]
* Example 3:
* 
* Input: arr = [3,8,-10,23,19,-4,-14,27]
* Output: [[-14,-10],[19,23],[23,27]]
*  
* 
* Constraints:
* 
* 2 <= arr.length <= 10^5
* -10^6 <= arr[i] <= 10^6
*
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		int mingap = INT_MAX;
		vector<vector<int>> ret;

		sort(arr.begin(),arr.end());

		for(int i = 0 ; i < arr.size()-1; ++i){
			int gap = abs(arr[i+1]-arr[i]);
			if(gap < mingap){
				mingap = gap;
				ret = {{arr[i],arr[i+1]}};
			}else if(gap == mingap){
				ret.push_back({arr[i],arr[i+1]});
			}
		}
		return ret;
    }
};

int main() {
	Solution sol;
	vector<int> arr;
	vector<vector<int>> ans,res;

	arr = {4,2,1,3};
	ans = {{1,2},{2,3},{3,4}};
	res = sol.minimumAbsDifference(arr);
	println("ans : {}, res : {}",ans,res);

	arr = {1,3,6,10,15};
	ans = {{1,3}};
	res = sol.minimumAbsDifference(arr);
	println("ans : {}, res : {}",ans,res);

	arr = {3,8,-10,23,19,-4,-14,27};
	ans = {{-14,-10},{19,23},{23,27}};
	res = sol.minimumAbsDifference(arr);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
