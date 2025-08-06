/**
* 3479. Fruits Into Baskets III
* You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.
* 
* From left to right, place the fruits according to these rules:
* 
* Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
* Each basket can hold only one type of fruit.
* If a fruit type cannot be placed in any basket, it remains unplaced.
* Return the number of fruit types that remain unplaced after all possible allocations are made.
* 
*  
* 
* Example 1:
* 
* Input: fruits = [4,2,5], baskets = [3,5,4]
* 
* Output: 1
* 
* Explanation:
* 
* fruits[0] = 4 is placed in baskets[1] = 5.
* fruits[1] = 2 is placed in baskets[0] = 3.
* fruits[2] = 5 cannot be placed in baskets[2] = 4.
* Since one fruit type remains unplaced, we return 1.
* 
* Example 2:
* 
* Input: fruits = [3,6,1], baskets = [6,4,7]
* 
* Output: 0
* 
* Explanation:
* 
* fruits[0] = 3 is placed in baskets[0] = 6.
* fruits[1] = 6 cannot be placed in baskets[1] = 4 (insufficient capacity) but can be placed in the next available basket, baskets[2] = 7.
* fruits[2] = 1 is placed in baskets[1] = 4.
* Since all fruits are successfully placed, we return 0.
* 
*  
* 
* Constraints:
* 
* n == fruits.length == baskets.length
* 1 <= n <= 105
* 1 <= fruits[i], baskets[i] <= 10^9
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>

using namespace std; //편의성위해..
#if 1
struct SegmentTree {
    int n;
    vector<long long> tree;
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) tree[node] = arr[start];
        else {
            int mid = (start + end) / 2;
            build(arr, node*2, start, mid);
            build(arr, node*2+1, mid+1, end);
            tree[node] = max(tree[node*2], tree[node*2+1]);
        }
    }
    // fruit 이상을 담을 수 있는 가장 왼쪽 바구니 찾기
    int query(int node, int start, int end, long long fruit) {
        if (tree[node] < fruit) return -1; // 이 구간에 가능한 바구니 없음
        if (start == end) return start;
        int mid = (start + end) / 2;
        int left = query(node*2, start, mid, fruit);
        if (left != -1) return left;
        return query(node*2+1, mid+1, end, fruit);
    }
    void update(int node, int start, int end, int idx) {
        if (start == end) tree[node] = 0;
        else {
            int mid = (start + end) / 2;
            if (idx <= mid) update(node*2, start, mid, idx);
            else update(node*2+1, mid+1, end, idx);
            tree[node] = max(tree[node*2], tree[node*2+1]);
        }
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree seg(baskets);
        int unplaced = 0;
        for (int fruit : fruits) {
            int idx = seg.query(1, 0, baskets.size()-1, fruit);
            if (idx == -1) {
                unplaced++;
            } else {
                seg.update(1, 0, baskets.size()-1, idx);
            }
        }
        return unplaced;
    }
};
#else
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        unordered_map<int,bool> used_basket;
		int count = 0;
		for(int i = 0 ; i < fruits.size() ; ++i){
			int j = 0;
			while(j < baskets.size()){
				if(!used_basket[j] && baskets[j] >= fruits[i]){
					used_basket[j] = true;
					count ++;
					break;
				}
				j++;
			}
		}
		return fruits.size() - count;
    }
};
#endif
int main() {
	Solution sol;
	vector<int> fruits, baskets;
	int ans,res;

	fruits = {4,2,5};
	baskets = {3,5,4};
	ans = 1;
	res = sol.numOfUnplacedFruits(fruits,baskets);
	println("ans : {} , res : {}",ans,res);

	fruits = {3,6,1};
	baskets = {6,4,7};
	ans = 0;
	res = sol.numOfUnplacedFruits(fruits,baskets);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
