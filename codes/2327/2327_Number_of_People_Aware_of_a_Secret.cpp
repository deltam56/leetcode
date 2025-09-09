/**
* 2327. Number of People Aware of a Secret
* On day 1, one person discovers a secret.
* 
* You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.
* 
* Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.
* 
* 
* 
* Example 1:
* 
* Input: n = 6, delay = 2, forget = 4
* Output: 5
* Explanation:
* Day 1: Suppose the first person is named A. (1 person)
* Day 2: A is the only person who knows the secret. (1 person)
* Day 3: A shares the secret with a new person, B. (2 people)
* Day 4: A shares the secret with a new person, C. (3 people)
* Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
* Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
* Example 2:
* 
* Input: n = 4, delay = 1, forget = 3
* Output: 6
* Explanation:
* Day 1: The first person is named A. (1 person)
* Day 2: A shares the secret with B. (2 people)
* Day 3: A and B share the secret with 2 new people, C and D. (4 people)
* Day 4: A forgets the secret. B, C, and D share the secret with 3 new people. (6 people)
* 
* 
* Constraints:
* 
* 2 <= n <= 1000
* 1 <= delay < forget <= n
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std;
#if 0
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
		vector<int> peoples;
		peoples.push_back(1);
		int count = 1;

		for(int i = 2 ; i <= n ; ++i){
			for(int j = 0; j < peoples.size(); ++j){
				if(peoples[j] == forget+1){
					peoples[j] = INT_MIN;
					count --;
				}
				if(peoples[j] > delay){
					peoples.push_back(1);
					count++;
				}
				peoples[j]++;
			}
		}
		return count;
    }
};
#else
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1'000'000'007;
        vector<long long> newPeople(n + 1, 0);
        newPeople[1] = 1;

        long long shareable_sum = 0;
        long long aware_sum = 1;

        for (int d = 2; d <= n; ++d) {
            if (d - forget >= 1) {
                aware_sum = (aware_sum - newPeople[d - forget]) % MOD;
                if (aware_sum < 0) aware_sum += MOD;
                shareable_sum = (shareable_sum - newPeople[d - forget]) % MOD;
                if (shareable_sum < 0) shareable_sum += MOD;
            }

            if (d - delay >= 1) {
                shareable_sum = (shareable_sum + newPeople[d - delay]) % MOD;
            }

            newPeople[d] = shareable_sum;

            aware_sum = (aware_sum + newPeople[d]) % MOD;
        }

        return (int)(aware_sum % MOD);
    }
};
#endif
int main() {
	Solution sol;
	int n, delay,forget;
	int ans,res;

	n = 6, delay = 2, forget = 4;
	ans = 5;
	res = sol.peopleAwareOfSecret(n,delay,forget);
	println("ans : {} , res : {}",ans,res);

	n = 4, delay = 1, forget = 3;
	ans = 6;
	res = sol.peopleAwareOfSecret(n,delay,forget);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
