/**
* 2081. Sum of k-Mirror Numbers
* A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.
* 
* For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
* On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
* Given the base k and the number n, return the sum of the n smallest k-mirror numbers.
* 
*  
* 
* Example 1:
* 
* Input: k = 2, n = 5
* Output: 25
* Explanation:
* The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
*   base-10    base-2
*     1          1
*     3          11
*     5          101
*     7          111
*     9          1001
* Their sum = 1 + 3 + 5 + 7 + 9 = 25. 
* Example 2:
* 
* Input: k = 3, n = 7
* Output: 499
* Explanation:
* The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
*   base-10    base-3
*     1          1
*     2          2
*     4          11
*     8          22
*     121        11111
*     151        12121
*     212        21212
* Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
* Example 3:
* 
* Input: k = 7, n = 17
* Output: 20379000
* Explanation: The 17 smallest 7-mirror numbers are:
* 1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
*  
* 
* Constraints:
* 
* 2 <= k <= 9
* 1 <= n <= 30
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std; //편의성위해..
#if 0
class Solution {
private:
	bool convert_base(int n,int base){
		if (n == 0) return "0";

		string result;
    	string tmp_result;
		while (n > 0) {
    	    result += '0' + (n % base);
    	    n /= base;
    	}
		tmp_result = result;
		std::reverse(result.begin(), result.end());

		if(tmp_result == result)
			return true;
		else
			return false;

	}
	bool mirror_base(int n){
		string num = to_string(n);
		string tmp = num;

		reverse(begin(num),end(num));

		if(tmp == num)
			return true;
		else
			return false;

	}
public:
    long long kMirror(int k, int n) {
		vector<int> mirrors;
		int num = 1;
		while(mirrors.size() < n){
			if(convert_base(num,k)&&mirror_base(num))
				mirrors.push_back(num);
			num++;
		}
		return accumulate(begin(mirrors),end(mirrors),0);
    }
};
#else
class Solution {
private:
    bool is_palindrome(const string& s) {
        return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }

    string to_base(long long n, int base) {
        string res;
        while (n > 0) {
            res += '0' + (n % base);
            n /= base;
        }
        return res;
    }

public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        // 1자리수 palindrome 먼저
        for (int i = 1; i < 10 && count < n; ++i) {
            if (is_palindrome(to_base(i, k))) {
                sum += i;
                ++count;
            }
        }

        int len = 1;
        while (count < n) {
            // Even-length palindromes
            for (int half = pow(10, len - 1); half < pow(10, len) && count < n; ++half) {
                string half_s = to_string(half);
                string full_s = half_s + string(half_s.rbegin(), half_s.rend());
                long long num = stoll(full_s);
                if (is_palindrome(to_base(num, k))) {
                    sum += num;
                    ++count;
                }
            }

            // Odd-length palindromes
            for (int half = pow(10, len - 1); half < pow(10, len) && count < n; ++half) {
                string half_s = to_string(half);
                for (char mid = '0'; mid <= '9' && count < n; ++mid) {
                    string full_s = half_s + mid + string(half_s.rbegin(), half_s.rend());
                    long long num = stoll(full_s);
                    if (is_palindrome(to_base(num, k))) {
                        sum += num;
                        ++count;
                    }
                }
            }

            ++len;
        }

        return sum;
    }
};
#endif

int main() {
	Solution sol;
	int k, n;
	long long ans,res;

	k = 2, n = 5;
	ans = 25;
	res = sol.kMirror(k,n);
	println("ans : {} , res : {}",ans,res);

	k = 3, n = 7;
	ans = 499;
	res = sol.kMirror(k,n);
	println("ans : {} , res : {}",ans,res);

	k = 7, n = 17;
	ans = 20379000;
	res = sol.kMirror(k,n);
	println("ans : {} , res : {}",ans,res);

    return 0;
}
