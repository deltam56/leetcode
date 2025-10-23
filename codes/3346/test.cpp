#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        using int64 = long long;

        // base[x]: 원래 값이 x인 개수
        unordered_map<int64,int> base;
        base.reserve(nums.size()*2);
        for (int x : nums) base[x]++;

        // 차분 이벤트: [a-k, a+k] 구간을 +1 로 덮음 (정수 구간이므로 R+1 에 -1)
        map<int64,int64> diff;
        diff.clear();
        for (int x : nums) {
            int64 L = (int64)x - k;
            int64 R = (int64)x + k;
            diff[L] += 1;
            diff[R + 1] -= 1;
        }

        // 스위프해야 할 포인트들: 이벤트 지점들과 원래 값들(=base key)
        vector<int64> pts;
        pts.reserve(diff.size() + base.size());
        for (auto &p : diff) pts.push_back(p.first);
        for (auto &p : base)  pts.push_back(p.first);
        sort(pts.begin(), pts.end());
        pts.erase(unique(pts.begin(), pts.end()), pts.end());

        // 빠른 base 조회를 위해 정렬된 키도 준비
        // (unordered_map은 직접 조회하면 충분)
        int ans = 1;
        for (auto &kv : base) ans = max(ans, kv.second); // 바꾸지 않아도 가능한 빈도

        // 스위프 진행
        int64 cover = 0;
        size_t di = 0; // diff 포인터 (diff는 map으로 정렬됨)
        auto itDiff = diff.begin();

        for (size_t i = 0; i < pts.size(); ++i) {
            int64 x = pts[i];

            // 현재 x에서 시작되는 이벤트들을 적용하여 cover(x)를 만든다
            while (itDiff != diff.end() && itDiff->first <= x) {
                cover += itDiff->second;
                ++itDiff;
            }

            // 1) 정확히 x를 목표로 할 때 (x가 원래 값으로 존재하는 지점이라면 base 이용)
            auto itBase = base.find(x);
            if (itBase != base.end()) {
                int64 b = itBase->second;         // base[x]
                int64 c = cover;                  // cover[x]
                int64 canChange = max<int64>(0, c - b);
                int64 add = min<int64>(numOperations, canChange);
                ans = max<int>(ans, (int)(b + add));
            }

            // 2) x와 x_next 사이의 어떤 정수점을 목표로 할 때 (대개 base=0 이 유리)
            if (i + 1 < pts.size()) {
                int64 nx = pts[i + 1];
                // 정수 지점이 존재하는 구간이면, 그 구간 내 임의의 정수에서
                // freq = min(numOperations, cover) (base=0이 최적)
                if (nx > x) {
                    int cand = (int)min<int64>(numOperations, cover);
                    ans = max(ans, cand);
                }
            } else {
                // 마지막 이후 구간은 고려할 필요 없음 (이벤트 없음)
            }
        }

        // 전체 원소 수를 넘을 수는 없음
        ans = min<int>(ans, (int)nums.size());
        return ans;
    }
};
