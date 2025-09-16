/**
* 2197. Replace Non-Coprime Numbers in Array
* You are given an array of integers nums. Perform the following steps:
* 
* - Find any two adjacent numbers in nums that are non-coprime.
* - If no such numbers are found, stop the process.
* - Otherwise, delete the two numbers and replace them with their LCM (Least Common Multiple).
* - Repeat this process as long as you keep finding two adjacent non-coprime numbers.
* Return the final modified array. It can be shown that replacing adjacent non-coprime numbers in any arbitrary order will lead to the same result.
* 
* The test cases are generated such that the values in the final array are less than or equal to 108.
* 
* Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y.
* 
*  
* 
* Example 1:
* 
* Input: nums = [6,4,3,2,7,6,2]
* Output: [12,7,6]
* Explanation: 
* - (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [12,3,2,7,6,2].
* - (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [12,2,7,6,2].
* - (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [12,7,6,2].
* - (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
* There are no more adjacent non-coprime numbers in nums.
* Thus, the final modified array is [12,7,6].
* Note that there are other ways to obtain the same resultant array.
* Example 2:
* 
* Input: nums = [2,2,1,1,3,3,3]
* Output: [2,1,1,3]
* Explanation: 
* - (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3,3].
* - (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3].
* - (2, 2) are non-coprime with LCM(2, 2) = 2. Now, nums = [2,1,1,3].
* There are no more adjacent non-coprime numbers in nums.
* Thus, the final modified array is [2,1,1,3].
* Note that there are other ways to obtain the same resultant array.
*  
* 
* Constraints:
* 
* 1 <= nums.length <= 105
* 1 <= nums[i] <= 105
* The test cases are generated such that the values in the final array are less than or equal to 108.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <numeric>

using namespace std;

static long long safe_lcm(long long a, long long b) {
    long long g = std::gcd(a, b);
    __int128 t = (__int128)(a / g) * b;
    return (long long)t;
}

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st;
        st.reserve(nums.size());

        for (int x : nums) {
            long long cur = x;
            while (!st.empty()) {
                long long g = std::gcd(st.back(), cur);
                if (g == 1) break;
                cur = safe_lcm(st.back(), cur);
                st.pop_back();
            }
            st.push_back(cur);
        }
        vector<int> ans;
        ans.reserve(st.size());
        for (long long v : st) ans.push_back((int)v);
        return ans;
    }
};

int main() {
	Solution sol;
	vector<int> nums;
	vector<int> ans, res;


	nums = {6,4,3,2,7,6,2};
	ans = {12,7,6};
	res = sol.replaceNonCoprimes(nums);
	println("ans : {}, res : {}",ans, res);
	

	nums = {2,2,1,1,3,3,3};
	ans = {2,1,1,3};
	res = sol.replaceNonCoprimes(nums);
	println("ans : {}, res : {}",ans, res);

    return 0;
}
