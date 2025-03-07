/**
 * 2523. Closest Prime Numbers in Range
 * Given two positive integers left and right, find the two integers num1 and num2 such that:

 * - left <= num1 < num2 <= right .
 * - Both num1 and num2 are prime numbers.
 * - num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
 * Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].
 *
 *
 *
 * Example 1:
 *
 * Input: left = 10, right = 19
 * Output: [11,13]
 * Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
 * The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
 * Since 11 is smaller than 17, we return the first pair.
 * Example 2:
 *
 * Input: left = 4, right = 6
 * Output: [-1,-1]
 * Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
 *
 *
 * Constraints:
 *
 * 1 <= left <= right <= 10^6
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>

using namespace std; //편의성위해..

// class Solution {
// 	void makePrimeNet(vector<bool>& isPrime, int right) {
//         isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아님
//         for (int i = 2; i * i <= right; i++) {
//             if (isPrime[i]) {
//                 for (int j = i * i; j <= right; j += i) {
//                     isPrime[j] = false;
//                 }
//             }
//         }
//     }
// 	// void makePrimeNet(vector<bool>& eNet,int right){
// 	// 	for (int i = 2 ; i<right; i++)
// 	// 		if(eNet[i] == false)
// 	// 			for(int j = 2; (i*j)<right+1 ; j++)
// 	// 				eNet[i*j] = true;
	
// public:
// 	vector<int> closestPrimes(int left, int right) {
// 		vector<int> res(2,-1);
// 		vector<bool> eNet(right+1,false);
// 		vector<int> betweenPrimes;
// 		int sub = right-left;
// 		if(left == 1) left = 2;

// 		makePrimeNet(eNet,right);
// 		for(int i = left; i<=right ; i++)
// 			if(eNet[i] == false)
// 				betweenPrimes.push_back(i);

// 		if(betweenPrimes.size() <2 )
// 			res = {-1,-1};
// 		else
// 			for(int i = 0; i <betweenPrimes.size()-1; i++){
// 				int tmpsub = betweenPrimes[i+1] - betweenPrimes[i];
// 				if(sub > tmpsub){
// 					res = {betweenPrimes[i],betweenPrimes[i+1]};
// 					sub = tmpsub;
// 				}
// 			}

// 		return res;
// 	}
// };

class Solution {
    void makePrimeNet(vector<bool>& isPrime, int right) {
        isPrime[0] = isPrime[1] = false; 
        for (int i = 2; i * i <= right; i++) 
            if (isPrime[i]) 
                for (int j = i * i; j <= right; j += i) 
                    isPrime[j] = false;
    }
    
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> res(2, -1);
        vector<bool> isPrime(right + 1, true);
        vector<int> primes;

        if (left == 1) left = 2; 
        
        makePrimeNet(isPrime, right);
        
        for (int i = left; i <= right; i++) 
            if (isPrime[i]) primes.push_back(i);
        

        if (primes.size() < 2) return {-1, -1};

        int minDiff = INT_MAX;
        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                res = {primes[i], primes[i + 1]};
            }
        }

        return res;
    }
};


int main(){
	Solution sol;
	vector<int> closestPrimes(int left, int right);
	int left,right;
	vector<int> res;
	vector<int> ans;

	left = 710119;
	right = 710189;
	ans = {710119,710189};
	res = sol.closestPrimes(left,right);
	println("ans : {}  res : {}", ans, res);
	for(int i = 0; i < res.size(); i++)
		assert(ans[i] == res[i]);

	left = 17;
	right = 31;
	ans = {17,19};
	res = sol.closestPrimes(left,right);
	println("ans : {}  res : {}", ans, res);
	for(int i = 0; i < res.size(); i++)
		assert(ans[i] == res[i]);



	left        =   10;
	right       =   19;
	ans         =   {11,13};
	res = sol.closestPrimes(left,right);
	println("ans : {}  res : {}", ans, res);
	for(int i = 0; i < res.size(); i++)
		assert(ans[i] == res[i]);


	left = 4;
	right = 6;
	ans = {-1,-1};
	res = sol.closestPrimes(left,right);
	println("ans : {}  res : {}", ans, res);
	for(int i = 0; i < res.size(); i++)
		assert(ans[i] == res[i]);



}
