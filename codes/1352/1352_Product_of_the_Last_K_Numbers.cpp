/*
1352. Product of the Last K Numbers
Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

 

Example:

Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
 

Constraints:

0 <= num <= 100
1 <= k <= 4 * 104
At most 4 * 104 calls will be made to add and getProduct.
The product of the stream at any point in time will fit in a 32-bit integer.
 

Follow-up: Can you implement both GetProduct and Add to work in O(1) time complexity instead of O(k) time complexity?


*/

#include <iostream>
#include <cassert>
#include <vector>
#include <forward_list>
#include <print>

using namespace std; //편의성위해..

#if 0
class ProductOfNumbers {
private:
	forward_list<int> nums;
public:
    ProductOfNumbers() {
    }

    void add(int num) {
		nums.push_front(num);
    }
    int getProduct(int k) {
        int product = 1;
        auto it = nums.begin(); // 첫 번째 요소부터 시작
        for (int i = 0; i < k && it != nums.end(); ++i, ++it) {
            product *= *it;
        }
        return product;
    }
};
#else
class ProductOfNumbers {
private:
	vector<int> prefix_prod {1};

public:
	ProductOfNumbers() {

	}

	void add(int num) {
		if (num == 0)
			prefix_prod = {1};
		else
			prefix_prod.push_back(prefix_prod.back() * num);
	}

	int getProduct(int k) {
		if (k >= prefix_prod.size())
			return 0;
		return prefix_prod.back() / prefix_prod[prefix_prod.size() - 1 - k];
	}
};
#endif
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
void printV(vector<int>& ans, vector<int>& res){
	println("ans : {}",ans);
	println("res : {}",res);
	for(int i =0; i<ans.size() ; i++){
		assert(ans[i]==res[i]);
	}
}

int main() {
	ProductOfNumbers numbers;	
	vector<string> input1;
	vector<vector<int>> input2;
	vector<int> ans;
	vector<int> res;
	input1 = {"ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"};
	input2 =  {{},{3},{0},{2},{5},{4},{2},{3},{4},{8},{2}};
	ans = {NULL,NULL,NULL,NULL,NULL,NULL,20,40,0,NULL,32};

	for(int i = 0; i<input1.size() ; i++){
		if(input1[i] == "ProductOfNumbers")
			res.push_back(NULL);
		else if(input1[i] == "add"){
			numbers.add(input2[i][0]);
			res.push_back(NULL);
		}else if(input1[i] == "getProduct"){
			res.push_back(numbers.getProduct(input2[i][0]));
		}
	}
	printV(ans,res);

	cout << "Accepted!" <<endl;
    return 0;
}
