/**
* 2140. Solving Questions With Brainpower
* You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].
* 
* The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.
* 
* For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
* If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
* If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
* Return the maximum points you can earn for the exam.
* 
*  
* 
* Example 1:
* 
* Input: questions = [[3,2],[4,3],[4,4],[2,5]]
* Output: 5
* Explanation: The maximum points can be earned by solving questions 0 and 3.
* - Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
* - Unable to solve questions 1 and 2
* - Solve question 3: Earn 2 points
* Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.
* Example 2:
* 
* Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
* Output: 7
* Explanation: The maximum points can be earned by solving questions 1 and 4.
* - Skip question 0
* - Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
* - Unable to solve questions 2 and 3
* - Solve question 4: Earn 5 points
* Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
*  
* 
* Constraints:
* 
* 1 <= questions.length <= 105
* questions[i].length == 2
* 1 <= pointsi, brainpoweri <= 105
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <queue>

using namespace std; //편의성위해..
#if 0
class Solution {
private:
	void find(priority_queue<long long>& leaf,long long val,
			  int index, vector<vector<int>>& questions){
		if (index >= questions.size()) {
			leaf.push(val);
			return;
		}
		find(leaf,val + questions[index][0], index + questions[index][1] + 1, questions);
		find(leaf,val, index + 1, questions);
	}
public:
    long long mostPoints(vector<vector<int>>& questions) {
        priority_queue<long long> leaf;
		find(leaf,0,0,questions);
		return leaf.top();
    }
};
#else

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            int point = questions[i][0];
            int brain = questions[i][1];
            long long next = i + brain + 1 < n ? dp[i + brain + 1] : 0;
            dp[i] = max(dp[i + 1], point + next);
        }

        return dp[0];
    }
};

#endif
int main() {
	Solution sol;
	vector<vector<int>> questions;
	long long ans,res;

	questions ={{12,46},{78,19},{63,15},{79,62},{13,10}};
	ans = 79;
	res = sol.mostPoints(questions);
	println("ans: {} , res : {} ",ans,res);

	questions = {{3,2},{4,3},{4,4},{2,5}};
	ans = 5;
	res = sol.mostPoints(questions);
	println("ans: {} , res : {} ",ans,res);

	questions = {{1,1},{2,2},{3,3},{4,4},{5,5}};
	ans = 7;
	res = sol.mostPoints(questions);
	println("ans: {} , res : {} ",ans,res);

	cout << "Accepted!" <<endl;
    return 0;
}
