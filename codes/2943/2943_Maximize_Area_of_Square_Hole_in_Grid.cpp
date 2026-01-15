/**
* 2943. Maximize Area of Square Hole in Grid
* You are given the two integers, n and m and two integer arrays, hBars and vBars. The grid has n + 2 horizontal and m + 2 vertical bars, creating 1 x 1 unit cells. The bars are indexed starting from 1.
* 
* You can remove some of the bars in hBars from horizontal bars and some of the bars in vBars from vertical bars. Note that other bars are fixed and cannot be removed.
* 
* Return an integer denoting the maximum area of a square-shaped hole in the grid, after removing some bars (possibly none).
* 
* Example 1:
* 
* Input: n = 2, m = 1, hBars = [2,3], vBars = [2]
* 
* Output: 4
* 
* Explanation:
* 
* The left image shows the initial grid formed by the bars. The horizontal bars are [1,2,3,4], and the vertical bars are [1,2,3].
* 
* One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2.
* 
* Example 2:
* 
* Input: n = 1, m = 1, hBars = [2], vBars = [2]
* 
* Output: 4
* 
* Explanation:
* 
* To get the maximum square-shaped hole, we remove horizontal bar 2 and vertical bar 2.
* 
* Example 3:
* 
* Input: n = 2, m = 3, hBars = [2,3], vBars = [2,4]
* 
* Output: 4
* 
* Explanation:
* 
* One way to get the maximum square-shaped hole is by removing horizontal bar 3, and vertical bar 4.
* 
* Constraints:
* 
* 1 <= n <= 109
* 1 <= m <= 109
* 1 <= hBars.length <= 100
* 2 <= hBars[i] <= n + 1
* 1 <= vBars.length <= 100
* 2 <= vBars[i] <= m + 1
* All values in hBars are distinct.
* All values in vBars are distinct.
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
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
		int hcnt = 2;
		int vcnt = 2;

		sort(hBars.begin(),hBars.end());
		sort(vBars.begin(),vBars.end());

		int tmp_hcnt = 2;
		int tmp_vcnt = 2;
		if((hBars.size() == 0 )||(vBars.size()==0))
			return 1;
		for(int i = 0; i < hBars.size()-1 ; ++i){
			if(abs(hBars[i+1]-hBars[i]) == 1)
				tmp_hcnt++;
			else tmp_hcnt = 2;
			hcnt = max(hcnt,tmp_hcnt);
		}
		for(int i = 0; i < vBars.size()-1 ; ++i){
			if(abs(vBars[i+1]-vBars[i]) == 1)
				tmp_vcnt++;
			else tmp_vcnt=2;
			vcnt = max(vcnt,tmp_vcnt);
		}

		return pow(min(vcnt, hcnt),2);
    }
};

int main() {
	Solution sol;
	int n, m;
	vector<int> hBars, vBars;
	int ans,res;
						// 2,3,4            2,4,6,7,10,12,13
	n = 3, m =13, hBars ={2,4,3}, vBars = {4,6,7,12,10,13,2};
	ans = 9;
	res = sol.maximizeSquareHoleArea(n,m,hBars,vBars);
	println("ans : {}, res : {}",ans,res);

	n = 2, m = 1, hBars = {2,3}, vBars = {2};
	ans = 4;
	res = sol.maximizeSquareHoleArea(n,m,hBars,vBars);
	println("ans : {}, res : {}",ans,res);

	n = 1, m = 1, hBars = {2}, vBars = {2};
	ans = 4;
	res = sol.maximizeSquareHoleArea(n,m,hBars,vBars);
	println("ans : {}, res : {}",ans,res);

	n = 2, m = 3, hBars = {2,3}, vBars = {2,4};
	ans = 4;
	res = sol.maximizeSquareHoleArea(n,m,hBars,vBars);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
