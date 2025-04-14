/**
 * 1534. Count Good Triplets
 * Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.
 * 
 * A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:
 * 
 * - 0 <= i < j < k < arr.length
 * - |arr[i] - arr[j]| <= a
 * - |arr[j] - arr[k]| <= b
 * - |arr[i] - arr[k]| <= c
 * Where |x| denotes the absolute value of x.
 * 
 * Return the number of good triplets.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
 * Output: 4
 * Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
 * Example 2:
 * 
 * Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
 * Output: 0
 * Explanation: No triplet satisfies all conditions.
 *  
 * 
 * Constraints:
 * 
 * 3 <= arr.length <= 100
 * 0 <= arr[i] <= 1000
 * 0 <= a, b, c <= 1000
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <cmath>

using namespace std; //편의성위해..
class Solution {
public:
	int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
		int count = 0;
		for(int i = 0; i < arr.size()-2; ++i){
			for(int k = i+2; k < arr.size() ; ++k){
				if(abs(arr[i] - arr[k]) <= c){
					for(int j = i+1 ; j < k ; ++j){
						if(abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[j])<=a)
							count ++;
					}
				}
			}
		}
		return count;
	}
};
int main() {
	Solution sol;
	vector<int> arr;
	int a = 0, b = 0 , c = 0;
	int ans, res;

	arr = {3,0,1,1,9,7};
	a = 7;
	b = 2;
	c = 3;
	ans = 4;
	res = sol.countGoodTriplets(arr,a,b,c);
	println("ans : {} , res : {}", ans,res);

	arr = {1,1,2,2,3};
	a = 0;
	b = 0;
	c = 1;
	ans = 0;
	res = sol.countGoodTriplets(arr,a,b,c);
	println("ans : {} , res : {}", ans,res);

	return 0;
}
