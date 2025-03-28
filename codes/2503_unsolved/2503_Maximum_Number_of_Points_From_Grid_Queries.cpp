/**
* 2503. Maximum Number of Points From Grid Queries
* You are given an m x n integer matrix grid and an array queries of size k.
* 
* Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
* 
* If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
* Otherwise, you do not get any points, and you end this process.
* After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
* 
* Return the resulting array answer.
* 
*  
* 
* Example 1:
* 
* 
* Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
* Output: [5,8,1]
* Explanation: The diagrams above show which cells we visit to get points for each query.
* Example 2:
* 
* 
* Input: grid = [[5,2,1],[1,1,2]], queries = [3]
* Output: [0]
* Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
*  
* 
* Constraints:
* 
* m == grid.length
* n == grid[i].length
* 2 <= m, n <= 1000
* 4 <= m * n <= 10^5
* k == queries.length
* 1 <= k <= 10^4
* 1 <= grid[i][j], queries[i] <= 10^6
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <utility>
#include <unordered_map>

using namespace std; //편의성위해..
struct pair_hash {
	size_t operator()(const pair<int, int>& p) const {
		return hash<int>()(p.first) ^ hash<int>()(p.second);
	}
};

#if 0
class Solution {
private:
	int findPathCount(unordered_map<pair<int,int>, bool,pair_hash>& footPrint,
					  vector<vector<int>>& grid,
					  int query, pair<int,int> index){

		if(index.first >= grid.size() || index.second >= grid[0].size()) {
			return 0;
		}
		int count = 0;
		if(!footPrint[index]){
			if(grid[index.first][index.second] < query){
				count ++;
			}else{
				return 0;
			}
		}
		footPrint[index] = true;
		count += findPathCount(footPrint, grid, query, {index.first + 1 , index.second});
		count += findPathCount(footPrint, grid, query, {index.first , index.second + 1});
		return count;
	}
public:
	vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries){
		vector<int> res;



		for(int i = 0; i <queries.size();i++){
			unordered_map<pair<int,int>,bool,pair_hash> footPrint;
			res.push_back(findPathCount(footPrint, grid, queries[i], {0,0}));
		}

		return res;

    }
};
#else
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(queries.size());
        vector<tuple<int, int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); ++i)
            sortedQueries.emplace_back(queries[i], i, 0); // (queryValue, originalIndex, result)

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        pq.emplace(grid[0][0], 0, 0);
        visited[0][0] = true;

        int count = 0;
        int qIdx = 0;

        for (auto& [query, idx, _] : sortedQueries) {
            while (!pq.empty() && get<0>(pq.top()) < query) {
                auto [val, x, y] = pq.top(); pq.pop();
                ++count;

                for (auto [dx, dy] : vector<pair<int, int>>{{0,1},{1,0},{-1,0},{0,-1}}) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                        pq.emplace(grid[nx][ny], nx, ny);
                        visited[nx][ny] = true;
                    }
                }
            }
            res[idx] = count;
        }

        return res;
    }
};
#endif
int main() {
	Solution sol;
	vector<vector<int>> grid;
	vector<int> queries;
	vector<int> ans, res;

	grid = {{1,2,3},{2,5,7},{3,5,1}};
	queries = {5,6,2};
	ans = {5,8,1};
	res = sol.maxPoints(grid, queries);
	println("ans : {} , res : {}", ans, res);

	grid = {{5,2,1},{1,1,2}};
	queries = {3};
	ans = {0};
	res = sol.maxPoints(grid, queries);
	println("ans : {} , res : {}", ans, res);

    return 0;
}
