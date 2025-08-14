/**
* 118. Pascal's Triangle
* Given an integer numRows, return the first numRows of Pascal's triangle.
* 
* In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
* 
* Example 1:
* 
* Input: numRows = 5
* Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
* Example 2:
* 
* Input: numRows = 1
* Output: [[1]]
* 
* 
* Constraints:
* 
* 1 <= numRows <= 30
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		int rowcount = 1;
		vector<vector<int>> ret;
		ret.push_back({1});
		if(numRows == 1)
			return ret;

		while(rowcount < numRows){
			vector<int> tmp_vec;
			tmp_vec.push_back(1);
			for(int i = 1; i < ret[rowcount-1].size(); ++i){
				tmp_vec.push_back(ret[rowcount-1][i-1]+ret[rowcount-1][i]);
			}
			tmp_vec.push_back(1);
			ret.push_back(tmp_vec);
			rowcount++;
		}
		return ret;
    }
};
int main() {
	Solution sol;
	int numRows;
	vector<vector<int>> ans,res;

	numRows = 5;
	ans = {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
	res = sol.generate(numRows);
	println("ans : {} , res : {}",ans,res);

	numRows = 1;
	ans = {{1}};
	res = sol.generate(numRows);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
