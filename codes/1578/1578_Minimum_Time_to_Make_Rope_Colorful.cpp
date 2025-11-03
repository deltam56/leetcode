/**
* 1578. Minimum Time to Make Rope Colorful
* Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
* 
* Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.
* 
* Return the minimum time Bob needs to make the rope colorful.
* 
* 
* 
* Example 1:
* 
* 
* Input: colors = "abaac", neededTime = [1,2,3,4,5]
* Output: 3
* Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
* Bob can remove the blue balloon at index 2. This takes 3 seconds.
* There are no longer two consecutive balloons of the same color. Total time = 3.
* Example 2:
* 
* 
* Input: colors = "abc", neededTime = [1,2,3]
* Output: 0
* Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
* Example 3:
* 
* 
* Input: colors = "aabaa", neededTime = [1,2,3,4,1]
* Output: 2
* Explanation: Bob will remove the balloons at indices 0 and 4. Each balloons takes 1 second to remove.
* There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
* 
* 
* Constraints:
* 
* n == colors.length == neededTime.length
* 1 <= n <= 105
* 1 <= neededTime[i] <= 104
* colors contains only lowercase English letters.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <queue>

using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
		//쭉 돌면서 같은거 만나면, index, count 저장, count==1 까지
		//priority queue 에 넣어둔 time 더하면서 pop
		// time : priority_queue (increase order)
		int ret = 0;
		colors.push_back('\0');
		neededTime.push_back(INT_MAX);
		priority_queue<int,vector<int>,greater<int>> times;
		for(int i = 0; i < colors.size()-1; i++){
			if(colors[i+1] == colors[i]){
				times.push(neededTime[i]);
			}else{
				if(i>0 && colors[i] == colors[i-1]){
					times.push(neededTime[i]);
				}
				while(!times.empty()){
					if(times.size()>1)
						ret += times.top();
					times.pop();
				}
			}
		}
		return ret;
    }
};

int main() {
	Solution sol;
	string colors;
	vector<int> neededTime;
	int ans,res;

	colors = "abaac", neededTime = {1,2,3,4,5};
	ans = 3;
	res = sol.minCost(colors, neededTime);
	println("ans : {}, res : {}",ans,res);

	colors = "abc", neededTime = {1,2,3};
	ans = 0;
	res = sol.minCost(colors, neededTime);
	println("ans : {}, res : {}",ans,res);

	colors = "aabaa", neededTime = {1,2,3,4,1};
	ans = 2;
	res = sol.minCost(colors, neededTime);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
