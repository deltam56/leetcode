/**
* 2551. Put Marbles in Bags
* You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.
* 
* Divide the marbles into the k bags according to the following rules:
* 
* - No bag is empty.
* - If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
* - If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
* The score after distributing the marbles is the sum of the costs of all the k bags.
* 
* Example 1:

* Input: weights = [1,3,5,1], k = 2
* Output: 4
* Explanation:
* The distribution [1],[3,5,1] results in the minimal score of (1+1) + (3+1) = 6.
* The distribution [1,3],[5,1], results in the maximal score of (1+3) + (5+1) = 10.
* Thus, we return their difference 10 - 6 = 4.
* Example 2:
* 
* Input: weights = [1, 3], k = 2
* Output: 0
* Explanation: The only distribution possible is [1],[3].
* Since both the maximal and minimal score are the same, we return 0.
* 
* 
* Constraints:
* 
* 1 <= k <= weights.length <= 105
* 1 <= weights[i] <= 109
* Return the difference between the maximum and minimum scores among marble distributions.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <map>

using namespace std; //편의성위해..
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
		//{value: {p1,p2,p3...}}
		map<long long,vector<int>> p_map;
		map<long long,int> index_value;
		long long max = 0, min =0;
		int m = weights.size();



		

		return max-min
    }
};
int main() {
	Solution sol;
	vector<int> weights;
	int k;
	long long ans, res;


	weights = {1,3,5,1};
	k = 2;
	ans = 4;
	res = sol.putMarbles(weights,k);
	println("ans : {} , res : {}",ans,res);

	weights = {1, 3};
	k = 2;
	ans = 0;
	res = sol.putMarbles(weights,k);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
