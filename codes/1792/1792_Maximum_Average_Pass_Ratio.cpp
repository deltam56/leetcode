/**
 * 1792. Maximum Average Pass Ratio
 * There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
 * 
 * You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.
 * 
 * The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
 * 
 * Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
 * Output: 0.78333
 * Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
 * Example 2:
 * 
 * Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
 * Output: 0.53485
 * 
 * 
 * Constraints:
 * 
 * 1 <= classes.length <= 10^5
 * classes[i].length == 2
 * 1 <= passi <= totali <= 10^5
 * 1 <= extraStudents <= 10^5
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <numeric>
using namespace std;
#if 0
class Solution {
public:
	double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		vector<double> pass_ratio;

		for(vector<int>& c: classes){
			pass_ratio.push_back(1.0*c[0]/c[1]);
		}

		for(int i = 0; i < extraStudents; ++i){
			pair<double,int> max_gap = {0.0,-1};
			for(int j = 0; j < pass_ratio.size() ; ++j){
				double gap = (1.0*(classes[j][0]+1)/(classes[j][1]+1)) - pass_ratio[j];
				if(gap > max_gap.first){
					max_gap = {gap, j};
				}
			}
			classes[max_gap.second][0] ++;
			classes[max_gap.second][1] ++;
			pass_ratio[max_gap.second] += max_gap.first;
		}

		return 1.0*accumulate(pass_ratio.begin(), pass_ratio.end(), 0.0)/pass_ratio.size();
	}
};
#else

class Solution {
private:
	struct Node {
	    int p, t;
	    long double gain() const {
	        return (long double)(t - p) / ((long double)t * (t + 1));
	    }
	    long double ratio() const {
	        return (long double)p / (long double)t;
	    }
	};
	struct Cmp {
	    bool operator()(const Node& a, const Node& b) const {
	        return a.gain() < b.gain();
	    }
	};

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Node, vector<Node>, Cmp> pq;
        pq = decltype(pq)();

        for (auto &c : classes) {
            pq.push(Node{c[0], c[1]});
        }

        while (extraStudents--) {
            auto cur = pq.top(); pq.pop();
            ++cur.p; ++cur.t;
            pq.push(cur);
        }

        long double sum = 0.0L;
        while (!pq.empty()) {
            sum += pq.top().ratio();
            pq.pop();
        }
        long double avg = sum / (long double)classes.size();
        return (double)avg;
    }
};
#endif
int main() {
	Solution sol;
	vector<vector<int>> classes;
	int extraStudents;
	double ans, res;

	classes = {{1,2},{3,5},{2,2}};
	extraStudents = 2;
	ans = 0.78333;
	res = sol.maxAverageRatio(classes,extraStudents);
	println("ans : {}, res : {}",ans,res);

	classes = {{2,4},{3,9},{4,5},{2,10}};
	extraStudents = 4;
	ans = 0.53485;
	res = sol.maxAverageRatio(classes,extraStudents);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
