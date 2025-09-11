/**
* 1733. Minimum Number of People to Teach
* On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.
* 
* You are given an integer n, an array languages, and an array friendships where:
* 
* There are n languages numbered 1 through n,
* languages[i] is the set of languages the i​​​​​​th​​​​ user knows, and
* friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the users u​​​​​​​​​​​i​​​​​ and vi.
* You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.
* 
* Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.
*  
* 
* Example 1:
* 
* Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
* Output: 1
* Explanation: You can either teach user 1 the second language or user 2 the first language.
* Example 2:
* 
* Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
* Output: 2
* Explanation: Teach the third language to users 1 and 3, yielding two users to teach.
*  
* 
* Constraints:
* 
* 2 <= n <= 500
* languages.length == m
* 1 <= m <= 500
* 1 <= languages[i].length <= n
* 1 <= languages[i][j] <= n
* 1 <= u​​​​​​i < v​​​​​​i <= languages.length
* 1 <= friendships.length <= 500
* All tuples (u​​​​​i, v​​​​​​i) are unique
* languages[i] contains only unique values
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
						 vector<vector<int>>& friendships) {
		// 애들별로 돌아가며 아는 언어 치환해놓음 (bit)
		// ex 1,2 알면 11  1 알면 10 2 만 알면 01
		// 각 친구쌍 돌며 앞놈 뒷놈 and 하고, 1 이상이면 넘어가고, 0 이라면
		// *앞놈꺼 하나 뒷놈한테 가르침 (관건) , count ++
		// return count 하면 될듯

        
    }
};

int main() {
	Solution sol;
	int n;
	vector<vector<int>> languages, friendships;
	int ans, res;

	n = 2;
	languages = {{1},{2},{1,2}};
	friendships = {{1,2},{1,3},{2,3}};
	ans = 1;
	res = sol.minimumTeachings(n,languages,friendships);
	println("ans : {} , res : {}",ans,res);

	n = 3;
	languages = {{2},{1,3},{1,2},{3}};
	friendships = {{1,4},{1,2},{3,4},{2,3}};
	ans = 2;
	res = sol.minimumTeachings(n,languages,friendships);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
