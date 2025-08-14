/**
* 904. Fruit Into Baskets
* You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
*
* You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
* 
* You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
* Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
* Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
* Given the integer array fruits, return the maximum number of fruits you can pick.
* 
*  
* 
* Example 1:
* 
* Input: fruits = [1,2,1]
* Output: 3
* Explanation: We can pick from all 3 trees.
* Example 2:
* 
* Input: fruits = [0,1,2,2]
* Output: 3
* Explanation: We can pick from trees [1,2,2].
* If we had started at the first tree, we would only pick from trees [0,1].
* Example 3:
* 
* Input: fruits = [1,2,3,2,2]
* Output: 4
* Explanation: We can pick from trees [2,3,2,2].
* If we had started at the first tree, we would only pick from trees [1,2].
*  
* 
* Constraints:
* 
* 1 <= fruits.length <= 10^5
* 0 <= fruits[i] < fruits.length
* 
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std; //편의성위해..

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
		int l = 0, r = 0;
		// fruit : count, lastindex
		unordered_map<int,pair<int,int>> fruitinfo;

		while(r < fruits.size()){
			fruitinfo[fruits[r]].first++;
			fruitinfo[fruits[r]].second = r;
			++r;
		}

		//r 증가
		//r 과일 종류 봄
		//기존에 있던거 :
		//  count 증가
		//기존에 없던거 :
		//  l 을 r-1 과일이 아닌것의 마지막 인덱스 까지 count 빼고, 거기까지 감
		//
		//  maxcount 연산
		//  return maxcount

		return 0;
    }
};

int main() {
	Solution sol;
	vector<int> fruits;
	int ans,res;

	fruits = {1,2,1};
	ans = 3;
	res = sol.totalFruit(fruits);
	println("ans : {} , res : {}",ans ,res);

	fruits = {0,1,2,2};
	ans = 3;
	res = sol.totalFruit(fruits);
	println("ans : {} , res : {}",ans ,res);

	fruits = {1,2,3,2,2};
	ans = 4;
	res = sol.totalFruit(fruits);
	println("ans : {} , res : {}",ans ,res);


    return 0;
}
