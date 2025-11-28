/**
* 2872. Maximum Number of K-Divisible Components
* There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
* 
* You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.
* 
* A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.
* 
* Return the maximum number of components in any valid split.
* 
* 
* 
* Example 1:
* 
* 
* Input: n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
* Output: 2
* Explanation: We remove the edge connecting node 1 with 2. The resulting split is valid because:
* - The value of the component containing nodes 1 and 3 is values[1] + values[3] = 12.
* - The value of the component containing nodes 0, 2, and 4 is values[0] + values[2] + values[4] = 6.
* It can be shown that no other valid split has more than 2 connected components.
* Example 2:
* 
* 
* Input: n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [3,0,6,1,5,2,1], k = 3
* Output: 3
* Explanation: We remove the edge connecting node 0 with 2, and the edge connecting node 0 with 1. The resulting split is valid because:
* - The value of the component containing node 0 is values[0] = 3.
* - The value of the component containing nodes 2, 5, and 6 is values[2] + values[5] + values[6] = 9.
* - The value of the component containing nodes 1, 3, and 4 is values[1] + values[3] + values[4] = 6.
* It can be shown that no other valid split has more than 3 connected components.
* 
* 
* Constraints:
* 
* 1 <= n <= 3 * 104
* edges.length == n - 1
* edges[i].length == 2
* 0 <= ai, bi < n
* values.length == n
* 0 <= values[i] <= 10^9
* 1 <= k <= 10^9
* Sum of values is divisible by k.
* The input is generated such that edges represents a valid tree.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;

class Solution {
private:
    int n;
    long long k;
    vector<vector<int>> adj;
    vector<int> values;
    int ans = 0;

    long long dfs(int u, int p) {
        long long sum = values[u] % k;

        for (int v : adj[u]) {
            if (v == p) continue;
            sum += dfs(v, u);
            sum %= k;
        }

        if (sum % k == 0) {
            ans++;
            return 0;
        }

        return sum;
    }
public:
    int maxKDivisibleComponents(int n_, vector<vector<int>>& edges,
								vector<int>& values_, int k_) {
		//0을 기준으로 트리를 만들고,
		//각 간선에 하위 합을 다 기록해놓기  (가능하면 이 단계에서 그냥 %3 을 해 둠)
		//하위합 %3 ==0 인 값 +1 이 답이 될거같은데
        n = n_;
        k = k_;
        values = values_;
        adj.assign(n, {});
        for (auto &e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        long long total = 0;
        for (int x : values) {
            total += x;
        }

        if (total % k != 0) return 0;
        dfs(0, -1);

        return ans;
    }
};

int main() {
	Solution sol;
	int n;
	vector<vector<int>> edges;
	vector<int> values;
	int k;
	int ans,res;

	n = 5, edges = {{0,2},{1,2},{1,3},{2,4}}, values = {1,8,1,4,4}, k = 6;
	ans = 2;
	res = sol.maxKDivisibleComponents(n,edges,values,k);
	println("ans : {}, res : {}",ans,res);

	n = 7, edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}}, values = {3,0,6,1,5,2,1}, k = 3;
	ans = 3;
	res = sol.maxKDivisibleComponents(n,edges,values,k);
	println("ans : {}, res : {}",ans,res);

    return 0;
}
