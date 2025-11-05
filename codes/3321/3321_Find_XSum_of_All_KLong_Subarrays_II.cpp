/**
 * 3321. Find X-Sum of All K-Long Subarrays II
 * You are given an array nums of n integers and two integers k and x.
 * 
 * The x-sum of an array is calculated by the following procedure:
 * 
 * Count the occurrences of all elements in the array.
 * Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
 * Calculate the sum of the resulting array.
 * Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
 * 
 * Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
 * 
 * Output: [6,10,12]
 * 
 * Explanation:
 * 
 * For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
 * For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
 * For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
 * Example 2:
 * 
 * Input: nums = [3,8,7,8,7,5], k = 2, x = 2
 * 
 * Output: [11,15,15,15,12]
 * 
 * Explanation:
 * 
 * Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].
 * 
 * 
 * 
 * Constraints:
 * 
 * nums.length == n
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= x <= k <= nums.length
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
#if 0
class Solution {
private:
	void inputn(){
		// tmp = freq[n]
		// freq[n]++
		// pq[tmp].delete(n)
		// pq[freq[n]].insert(n)
	}
	void deleten(){
		// tmp = freq[n]
		// freq[n]--
		// pq[tmp].delete(n)
		// pq[freq[n]].insert(n)
	}
	long long sumn(){
		// count = x
		//for i : pq
		//  for j : pq[i]
		//      count --
		//      sum += j*i
		//      if count = 0 return sum;
		//return sum
	}
public:
	vector<long long> findXSum(vector<int>& nums, int k, int x) {
		// freq : 각 원소 빈도
		// pq : 각 빈도별 원소 map<int, priority_queue<int,vector<int>,greater<int>>>
		// 루프에서 l, r 증가시키면서 window (size k) 유지
		// deleten(l), inputn(r)
		// ret.push_back(sumn)
		// return ret;
		unordered_map<int,int> freq;
		int n = nums.size();
		int l = 0;
		int r = k-1;


		//init
		for(int i = l; i < k; i++){
			freq[nums[i]] ++;
		}

		while(r <= n){

		}
	}
};

#endif
struct Node {
	int f;  // frequency
	int v;  // value
};

// 우선순위: f 내림차순, v 내림차순 (더 "큰" 게 먼저 오게)
struct Cmp {
	bool operator()(const Node& a, const Node& b) const {
		if (a.f != b.f) return a.f > b.f;
		return a.v > b.v;
	}
};
class Solution {
public:
	vector<long long> findXSum(vector<int>& nums, int k, int x) {
		int n = (int)nums.size();
		vector<long long> ans;
		ans.reserve(n - k + 1);

		unordered_map<int,int> freq; // value -> frequency
		freq.reserve(k * 2 + 7);

		// 두 집합: top(상위 x개), rest(나머지). comparator 는 "우선순위 큰 것이 앞"
		multiset<Node, Cmp> top, rest;

		auto makeNode = [&](int v) -> Node {
			return Node{freq[v], v};
		};

		long long S = 0;          // Σ freq[v]*v for v in top
		int distinct = 0;         // freq>0 인 값의 개수

		auto add_to_set = [&](int v, bool toTop) {
			Node nd{freq[v], v};
			if (toTop) {
				top.insert(nd);
				S += 1LL * nd.f * nd.v;
			} else {
				rest.insert(nd);
			}
		};

		auto erase_from_set_with = [&](int v, int f) {
			if (f <= 0) return;
			Node key{f, v};
			auto itTop = top.find(key);
			if (itTop != top.end()) {
				S -= 1LL * itTop->f * itTop->v;
				top.erase(itTop);
				return;
			}
			auto itRest = rest.find(key);
			if (itRest != rest.end()) rest.erase(itRest);
		};

		auto wantTopSize = [&]() -> int {
			return min(x, distinct);
		};

		auto swap_until_order = [&]() {
			// rest 최고 > top 최저 이면 서로 교환
			while (!rest.empty() && !top.empty()) {
				const Node& a = *rest.begin();     // rest 최고
				const Node& b = *prev(top.end());  // top 최저
												   // a 가 b 보다 우선이면 스왑
				Cmp cmp;
				if (cmp(a, b)) {
					// 이동 시 S 갱신
					S += 1LL * a.f * a.v;
					S -= 1LL * b.f * b.v;
					top.insert(a);
					rest.erase(rest.begin());
					rest.insert(b);
					top.erase(prev(top.end()));
				} else break;
			}
		};

		auto promote_from_rest = [&]() {
			while ((int)top.size() < wantTopSize() && !rest.empty()) {
				auto it = rest.begin(); // rest에서 가장 우선인 것
				S += 1LL * it->f * it->v;
				top.insert(*it);
				rest.erase(it);
			}
		};

		auto demote_from_top = [&]() {
			while ((int)top.size() > wantTopSize()) {
				auto it = prev(top.end()); // top에서 가장 덜 우선인 것
				S -= 1LL * it->f * it->v;
				rest.insert(*it);
				top.erase(it);
			}
		};

		auto insert_value = [&](int v) {
			int old = freq[v];
			if (old > 0) erase_from_set_with(v, old); // ✅ old로 삭제
			else distinct++;

			freq[v] = old + 1;                         // ✅ 그 다음 증가
			add_to_set(v, false);                      // 새 키로 임시 삽입
													   // 리밸런스
			promote_from_rest();
			swap_until_order();
		};

		auto remove_value = [&](int v) {
			int old = freq[v];
			erase_from_set_with(v, old);               // ✅ old로 삭제
			freq[v] = old - 1;                         // 감소
			if (freq[v] == 0) distinct--;
			else add_to_set(v, false);                 // 새 키로 재삽입
													   // 리밸런스
			demote_from_top();
			swap_until_order();
		};

		// 초기 윈도우 구성
		for (int i = 0; i < k; ++i) insert_value(nums[i]);
		// top 크기 보정 (초기 단계에선 promote가 이미 처리)
		promote_from_rest();
		demote_from_top();
		swap_until_order();

		ans.push_back(S);

		// 슬라이딩
		for (int i = k; i < n; ++i) {
			int outv = nums[i - k];
			int inv  = nums[i];
			remove_value(outv);
			insert_value(inv);
			promote_from_rest();
			demote_from_top();
			swap_until_order();
			ans.push_back(S);
		}

		return ans;
	}
};
int main() {
	Solution sol;
	vector<int> nums;
	int k,x;
	vector<long long> ans,res;

	nums = {1,1,2,2,3,4,2,3}, k = 6, x = 2;
	ans = {6,10,12};
	res = sol.findXSum(nums,k,x);
	println("ans : {}, res : {}",ans,res);


	nums = {3,8,7,8,7,5}, k = 2, x = 2;
	ans = {11,15,15,15,12};
	res = sol.findXSum(nums,k,x);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
