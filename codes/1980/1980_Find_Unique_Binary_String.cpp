/**
* 1980. Find Unique Binary String
* 
* Given an array of strings nums containing n unique binary strings each of 
* length n, return a binary string of length n that does not appear in nums. 
* If there are multiple answers, you may return any of them.
* 
* 
* 
* Example 1:
* 
* Input: nums = ["01","10"]
* Output: "11"
* Explanation: "11" does not appear in nums. "00" would also be correct.
* Example 2:
* 
* Input: nums = ["00","01"]
* Output: "11"
* Explanation: "11" does not appear in nums. "10" would also be correct.
* Example 3:
* 
* Input: nums = ["111","011","001"]
* Output: "101"
* Explanation: "101" does not appear in nums. "000", "010", "100", and "110" 
* would also be correct.
* 
* 
* Constraints:
* 
* n == nums.length
* 1 <= n <= 16
* nums[i].length == n
* nums[i] is either '0' or '1'.
* All the strings of nums are unique.
* 
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..
#if 0
class Solution {
private:
	void setCheckBinary(vector<string>& nums,vector<bool>& check){
		for(string& num : nums){
			int convertedNumber = stoi(num, nullptr, 2);
			check[convertedNumber] = true;
		}
	}

public:
    string findDifferentBinaryString(vector<string>& nums) {
		string res;
		const int size = nums.size();
		int maxNum = 1<<size;	
		vector<bool> check(maxNum,false);
		setCheckBinary(nums,check);

		for(int i =0 ; i<maxNum ; i++){
			if(check[i]==false){
				res = bitset<16>(i).to_string().substr(16 - size);
				return res;
			}
		}
		return "";
    }
};
#else
class Solution {
public:
	string findDifferentBinaryString(vector<string>& nums) {
		string res = nums[0];

		for (int i = 0; i < nums.size(); ++i)
			res = nums[i][i] ^ 1;

		return res;
	}
};
#endif

int main() {
	Solution sol;
	vector<string> nums;

	string ans,res;

	nums = {"1"};
	ans = "0";
	res = sol.findDifferentBinaryString(nums);
	println("ans : {} \n res : {}",ans, res);
	assert(res == ans);

	nums = {"01","10"};
	ans = "11";
	res = sol.findDifferentBinaryString(nums);
	println("ans : {} \n res : {}",ans, res);
	assert(res == ans);
 
	nums = {"00","01"};
	ans = "11";
 	res = sol.findDifferentBinaryString(nums);
	println("ans : {} \n res : {}",ans, res);
	assert(res == ans);

	nums = {"111","011","001"};
	ans = "101";
	res = sol.findDifferentBinaryString(nums);
	println("ans : {} \n res : {}",ans, res);
	assert(res == ans);

	cout << "Accepted!" <<endl;
    return 0;
}
