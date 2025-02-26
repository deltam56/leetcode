/**
* 2467. Most Profitable Path in a Tree
* There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
* 
* At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:
* 
* - the price needed to open the gate at node i, if amount[i] is negative, or,
* - the cash reward obtained on opening the gate at node i, otherwise.
* The game goes on as follows:
* - Initially, Alice is at node 0 and Bob is at node bob.
* - At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
* - For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
* - If the gate is already open, no price will be required, nor will there be any cash reward.
* - If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
* - If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
* Return the maximum net income Alice can have if she travels towards the optimal leaf node.
*
* Example 1:
* 
* 
* Input: edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
* Output: 6
* Explanation:
* The above diagram represents the given tree. The game goes as follows:
* - Alice is initially on node 0, Bob on node 3. They open the gates of their respective nodes.
*   Alice's net income is now -2.
* - Both Alice and Bob move to node 1.
*   Since they reach here simultaneously, they open the gate together and share the reward.
*   Alice's net income becomes -2 + (4 / 2) = 0.
* - Alice moves on to node 3. Since Bob already opened its gate, Alice's income remains unchanged.
*   Bob moves on to node 0, and stops moving.
* - Alice moves on to node 4 and opens the gate there. Her net income becomes 0 + 6 = 6.
* Now, neither Alice nor Bob can make any further moves, and the game ends.
* It is not possible for Alice to get a higher net income.
* Example 2:
* 
* 
* Input: edges = [[0,1]], bob = 1, amount = [-7280,2350]
* Output: -7280
* Explanation:
* Alice follows the path 0->1 whereas Bob follows the path 1->0.
* Thus, Alice opens the gate at node 0 only. Hence, her net income is -7280.
* 
* 
* Constraints:
* 
* 2 <= n <= 10^5
* edges.length == n - 1
* edges[i].length == 2
* 0 <= ai, bi < n
* ai != bi
* edges represents a valid tree.
* 1 <= bob < n
* amount.length == n
* amount[i] is an even integer in the range [-10^4, 10^4].
*
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

struct Node{
	int idx;
	int price;
	Node* up;
	vector<Node*> down;
	Node(int i,int p):idx(i),price(p){};
	Node(int i,int p,Node* u):idx(i),price(p),up(u){};
	Node(int i,int p,Node* u,vector<Node*> d):idx(i),price(p),up(u),down(d){};
};

#if 0
class Solution {
private:
void buildTree(vector<Node*>& nodes, vector<vector<int>> edges,vector<int> amount) {
	int n = edges.size();
    for(int i = 0; i < n; i++) {
        nodes[i] = new Node(i, amount[i]);
    }
    for(auto& edge : edges) {
        int a = edge[0], b = edge[1];
        nodes[a]->down.push_back(nodes[b]);
        nodes[b]->up = nodes[a];
    }
}
int findMaxIncome(int income, Node* alice, Node* bob){
	if(!alice)
		return income;

	if(alice == bob){
		income += alice->price/2;
	}else{
		bob->price = 0;
		income += income+alice->price;
	}

	for(Node* next : alice->down){
		income = findMaxIncome(income,next,bob->up);
	}

	return 0;
}
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
		vector<Node*> nodes;
		int n = edges.size();
		int income = 0;
		nodes.resize(n);
		buildTree(nodes, edges,amount);
		
		findMaxIncome(income,nodes[0],nodes[bob]);
		



		/* for(node : nodes)
		 * deleteNode(node);
		 */
    }
};
#else
#include <unordered_map>

class Solution {
private:
	void dfs1(unordered_map<int, vector<int>>& adj_list, vector<int>& distance,
			vector<int>& parent, int u, int p, int d) {
		parent[u] = p;
		distance[u] = d;

		// u -> v
		for (const int& v : adj_list[u]) {
			if (v == p)
				continue;
			dfs1(adj_list, distance, parent, v, u, d + 1);
		}
	}

	int dfs2(unordered_map<int, vector<int>>& adj_list, vector<int>& amount,
			int u, int p) {
		int res = amount[u];
		int income = 0;

		for (const int& v : adj_list[u]) {
			if (v == p)
				continue;
			income = max(income, dfs2(adj_list, amount, v, u));
		}

		return res + income;
	}

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
			vector<int>& amount) {
		const int n = amount.size();
		unordered_map<int, vector<int>> adj_list;
		vector<int> parent(n, -1);
		// Distance from the root, Alice
		vector<int> distance(n, 0);

		for (const vector<int>& edge : edges) {
			adj_list[edge[0]].push_back(edge[1]);
			adj_list[edge[1]].push_back(edge[0]);
		}

		/* Update paths from Alice. */
		dfs1(adj_list, distance, parent, 0, 0, 0);

		int curr = bob;
		int bob_dist = 0;

		while (curr != 0) {
			if (distance[curr] > bob_dist)
				amount[curr] = 0;
			else if (distance[curr] == bob_dist)
				amount[curr] /= 2;

			curr = parent[curr];
			bob_dist++;
		}
		// curr == 0
		return dfs2(adj_list, amount, 0, 0);
    }
};

#endif

int main() {
	Solution sol;
	vector<vector<int>> edges;
	int bob;
	vector<int> amount;
	int res,ans;


	edges = {{0,1},{1,2},{1,3},{3,4}};
	bob = 3;
	amount = {-2,4,2,-4,6};
	ans = 6;
	res = sol.mostProfitablePath(edges,bob,amount);
	println("ans : {}  res : {} " ,ans,res);
	assert(ans == res);


	edges = {{0,1}};
	bob = 1;
	amount = {-7280,2350};
	ans = -7280;
	res = sol.mostProfitablePath(edges,bob,amount);
	println("ans : {}  res : {} " ,ans,res);
	assert(ans == res);

	

	cout << "Accepted!" <<endl;
    return 0;
}
