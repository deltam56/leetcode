/**
 *
 *
 */
#include <cassert>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int tupleSameProduct(vector<int>& nums) {
            const int n = nums.size();
            int cnt = 0;
            unordered_map<int, int> hmap;

            for (int i = 1; i < n; ++i)
                for (int j = 0; j < i; ++j) {
                    int prod = nums[i] * nums[j];
                    cnt += hmap[prod] * 8;
                    hmap[prod]++;
                }

            return cnt;
        }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int ret;

    nums = {2,3,4,6};
    ret = sol.tupleSameProduct(nums);
    assert(ret == 8);
    cout << ret << endl;

    nums = {1,2,4,5,10};
    ret = sol.tupleSameProduct(nums);
    assert(ret == 16);
    cout << ret << endl;

    return 0;
}
