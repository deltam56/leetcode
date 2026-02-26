/**
* 1356. Sort Integers by The Number of 1 Bits
* You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
* 
* Return the array after sorting it.
* 
* 
* 
* Example 1:
* 
* Input: arr = [0,1,2,3,4,5,6,7,8]
* Output: [0,1,2,4,8,3,5,6,7]
* Explantion: [0] is the only integer with 0 bits.
* [1,2,4,8] all have 1 bit.
* [3,5,6] have 2 bits.
* [7] has 3 bits.
* The sorted array by bits is [0,1,2,4,8,3,5,6,7]
* Example 2:
* 
* Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
* Output: [1,2,4,8,16,32,64,128,256,512,1024]
* Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
* 
* 
* Constraints:
* 
* 1 <= arr.length <= 500
* 0 <= arr[i] <= 104
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
    vector<int> sortByBits(vector<int>& arr) {
		// count of 1 : num
		vector<pair<int,int>> cnts;
		vector<int> ret;
		for(int n: arr){
			cnts.push_back({__builtin_popcount(n),n});
		}

		sort(cnts.begin(),cnts.end());

		for(auto p:cnts){
			ret.push_back(p.second);
		}
		return ret;
    }
};

int main() {
	Solution sol;
	vector<int> arr;
	vector<int> ans,res;

	arr = {0,1,2,3,4,5,6,7,8};
	ans = {0,1,2,4,8,3,5,6,7};
	res = sol.sortByBits(arr);
	println("ans : {}, res : {}",ans,res);

	arr = {1024,512,256,128,64,32,16,8,4,2,1};
	ans = {1,2,4,8,16,32,64,128,256,512,1024};
	res = sol.sortByBits(arr);
	println("ans : {}, res : {}",ans,res);


    return 0;
}
