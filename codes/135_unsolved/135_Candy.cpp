/**
* 135. Candy
* There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
* 
* You are giving candies to these children subjected to the following requirements:
* 
* Each child must have at least one candy.
* Children with a higher rating get more candies than their neighbors.
* Return the minimum number of candies you need to have to distribute the candies to the children.
* 
*  
* 
* Example 1:
* 
* Input: ratings = [1,0,2}
* Output: 5
* Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
* Example 2:
* 
* Input: ratings = [1,2,2}
* Output: 4
* Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
* The third child gets 1 candy because it satisfies the above two conditions.
*  
* 
* Constraints:
* 
* n == ratings.length
* 1 <= n <= 2 * 10^4
* 0 <= ratings[i} <= 2 * 10^4
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <numeric>
using namespace std; //편의성위해..

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        int total = accumulate(candies.begin(), candies.end(), 0);
        return total;
    }
};

int main() {
	Solution sol;
	vector<int> ratings;
	int ans, res;

	ratings = {1,0,2};
	ans = 5;
	res = sol.candy(ratings);
	println("ans : {} , res : {}",ans,res);

	ratings = {1,2,2};
	ans = 4;
	res = sol.candy(ratings);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
