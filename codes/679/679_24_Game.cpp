/**
* 679. 24 Game
* You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.
* 
* You are restricted with the following rules:
* 
* The division operator '/' represents real division, not integer division.
* For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
* Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
* For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
* You cannot concatenate numbers together
* For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
* Return true if you can get such expression that evaluates to 24, and false otherwise.
* 
* 
* 
* Example 1:
* 
* Input: cards = [4,1,8,7]
* Output: true
* Explanation: (8-4) * (7-1) = 24
* Example 2:
* 
* Input: cards = [1,2,1,2]
* Output: false
* 
* 
* Constraints:
* 
* cards.length == 4
* 1 <= cards[i] <= 9
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#

using namespace std; //편의성위해..
#if 1
class Solution {
    static constexpr double TARGET = 24.0;
    static constexpr double EPS = 1e-6;

    bool closeTo24(double x) const {
        return fabs(x - TARGET) < EPS;
    }

    bool dfs(vector<double>& nums) {
        const int n = nums.size();
        if (n == 1) return closeTo24(nums[0]);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                vector<double> next;
                next.reserve(n - 1);
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }
                next.push_back(nums[i] + nums[j]);
                if (dfs(next)) return true;
                next.pop_back();
                next.push_back(nums[i] - nums[j]);
                if (dfs(next)) return true;
                next.pop_back();
                next.push_back(nums[i] * nums[j]);
                if (dfs(next)) return true;
                next.pop_back();
                if (fabs(nums[j]) > EPS) {
                    next.push_back(nums[i] / nums[j]);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
};
#else
class Solution {
private:
	string dfs(string& expression,vector<int> cards,int index,int opt){
		// 숫자 연산자 숫자 연산자 순으로 붙임
		expression += to_string(opt) + to_string(cards[index]);
		if(expression.size() > 7)
			return expression;
		dfs(expression,cards,index+1,0); //+
		dfs(expression,cards,index+1,1); //-
		dfs(expression,cards,index+1,2); //*
		dfs(expression,cards,index+1,3); ///
		return expression;
	};
	bool compute(string expression){
		//무조건 앞에서부터 숫자 -> 연산자 -> 숫자 순서로 읽어서 연산함
		//이렇게 하고 모든 숫자 조합을 다 연산하면 괄호를 굳이 안넣어도될듯)
		return false;
	}
public:
    bool judgePoint24(vector<int>& cards) {
		// +-*/ ()
		// 1~9
		// dfs?
		cards.insert(begin(cards),end(cards),end(cards)); // 한바퀴 돌리려고 그냥 두배함
		for(int i = 0; i < 4 ; ++i){
			string exp = to_string(cards[i]);
			println("exp : {}",dfs(exp,cards,0,0));

		}
    }
};
#endif
int main() {
	Solution sol;
	vector<int> cards;
	bool ans,res;

	cards = {4,1,8,7};
	ans = true;
	res = sol.judgePoint24(cards);
	println("ans : {} , res : {} ",ans,res);

	cards = {1,2,1,2};
	ans = false;
	res = sol.judgePoint24(cards);
	println("ans : {} , res : {} ",ans,res);

    return 0;
}
