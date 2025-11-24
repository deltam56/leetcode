/**
* 757. Set Intersection Size At Least Two
* You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.
* 
* A containing set is an array nums where each interval from intervals has at least two integers in nums.
* 
* For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
* Return the minimum possible size of a containing set.
* 
* 
* 
* Example 1:
* 
* Input: intervals = [[1,3],[3,7],[8,9]]
* Output: 5
* Explanation: let nums = [2, 3, 4, 8, 9].
* It can be shown that there cannot be any containing array of size 4.
* Example 2:
* 
* Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
* Output: 3
* Explanation: let nums = [2, 3, 4].
* It can be shown that there cannot be any containing array of size 2.
* Example 3:
* 
* Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
* Output: 5
* Explanation: let nums = [1, 2, 3, 4, 5].
* It can be shown that there cannot be any containing array of size 4.
* 
* 
* Constraints:
* 
* 1 <= intervals.length <= 3000
* intervals[i].length == 2
* 0 <= starti < endi <= 10^8
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(),
			[](const vector<int>& a, const vector<int>& b) {
				return a[1] < b[1];
			});

		// vector (0 ~ interval.end()[1]+1, 0)
		// line swip 으로 겹치는 부분 알아냄
		// interval 내 에서 큰값 두개 선정, set 에 push
		// set 갯수 return

		int endnum = intervals.back()[1];
		vector<int> diff(endnum+1,0);

		for(vector<int> i: intervals){
			diff[i[0]]++;
			diff[i[1]+1]--;
		}
		partial_sum(diff.begin(), diff.end(),diff.begin());
		set<int> ret;
		for(vector<int> interval : intervals){
			int first = -1e9, second = -1e9;
			int fi=-1, si=-1;
			for(int x = interval[0] ;x < interval[1] ; x++){
				if(diff[x] > first){
					second = first;
					si = fi;
					first = diff[x];
					fi = x;
				}else if (diff[x] > second){
					second = diff[x];
				}
			}
			ret.insert(fi);
			ret.insert(si);
		}

		return ret.size();
    }
};

int main() {
	Solution sol;
	vector<vector<int>> intervals;
	int ans,res;

	intervals = {{1,3},{3,7},{8,9}};
	ans = 5;
	res = sol.intersectionSizeTwo(intervals);
	println("ans : {}, res : {}",ans,res);

	intervals = {{1,3},{1,4},{2,5},{3,5}};
	ans = 3;
	res = sol.intersectionSizeTwo(intervals);
	println("ans : {}, res : {}",ans,res);

	intervals = {{1,2},{2,3},{2,4},{4,5}};
	ans = 5;
	res = sol.intersectionSizeTwo(intervals);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
