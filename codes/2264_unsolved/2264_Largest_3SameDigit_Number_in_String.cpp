/**
* 2264. Largest 3-Same-Digit Number in String
* * You are given a string num representing a large integer. An integer is good if it meets the following conditions:
* 
* It is a substring of num with length 3.
* It consists of only one unique digit.
* Return the maximum good integer as a string or an empty string "" if no such integer exists.
* 
* Note:
* 
* A substring is a contiguous sequence of characters within a string.
* There may be leading zeroes in num or a good integer.
* 
* 
* Example 1:
* 
* Input: num = "6777133339"
* Output: "777"
* Explanation: There are two distinct good integers: "777" and "333".
* "777" is the largest, so we return "777".
* Example 2:
* 
* Input: num = "2300019"
* Output: "000"
* Explanation: "000" is the only good integer.
* Example 3:
* 
* Input: num = "42352338"
* Output: ""
* Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
* 
* 
* Constraints:
* 
* 3 <= num.length <= 1000
* num only consists of digits.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <queue>

using namespace std; //편의성위해..
class Solution {
public:
    string largestGoodInteger(string num) {
		priority_queue<char> subs;

		for(int i = 0 ; i < num.size()-2 ; ++i){
			if(num[i] == num[i+1] && num[i+1] == num[i+2]){
				subs.push(num[i]);
				if(i < num.size()-2){
					i += 2;
				}
			}
		}

		if(subs.empty())
			return "";

		return string(3, subs.top());
    }
};
int main() {
	Solution sol;
	string num;
	string ans,res;

	num = "6777133339";
	ans = "777";
	res = sol.largestGoodInteger(num);
	println("ans : {}, res :{}",ans,res);

	num = "2300019";
	ans = "000";
	res = sol.largestGoodInteger(num);
	println("ans : {}, res :{}",ans,res);

	num = "42352338";
	ans = "";
	res = sol.largestGoodInteger(num);
	println("ans : {}, res :{}",ans,res);


	cout << "Accepted!" <<endl;
    return 0;
}
