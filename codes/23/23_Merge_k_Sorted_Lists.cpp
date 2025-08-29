/**
* 23. Merge k Sorted Lists
* You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
* 
* Merge all the linked-lists into one sorted linked-list and return it.
* 
*  
* 
* Example 1:
* 
* Input: lists = [[1,4,5],[1,3,4],[2,6]]
* Output: [1,1,2,3,4,4,5,6]
* Explanation: The linked-lists are:
* [
*   1->4->5,
*   1->3->4,
*   2->6
* ]
* merging them into one sorted linked list:
* 1->1->2->3->4->4->5->6
* Example 2:
* 
* Input: lists = []
* Output: []
* Example 3:
* 
* Input: lists = [[]]
* Output: []
*  
* 
* Constraints:
* 
* k == lists.length
* 0 <= k <= 104
* 0 <= lists[i].length <= 500
* -104 <= lists[i][j] <= 104
* lists[i] is sorted in ascending order.

**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;
        vals.reserve(1024); // 선택: 자잘한 reallocation 줄이기

        // 모든 리스트에서 값 수집
        for (ListNode* head : lists) {
            for (ListNode* p = head; p != nullptr; p = p->next) {
                vals.push_back(p->val);
            }
        }
        if (vals.empty()) return nullptr;

        // 정렬
        sort(vals.begin(), vals.end());

        // 정렬된 값으로 새 리스트 생성
        ListNode dummy(0);
        ListNode* tail = &dummy;
        for (int x : vals) {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
        return dummy.next;
    }
};

static ListNode* buildList(const vector<int>& v) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int x : v) {
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return dummy.next;
}

static vector<ListNode*> buildLists(const vector<vector<int>>& vv) {
    vector<ListNode*> lists;
    lists.reserve(vv.size());
    for (const auto& v : vv) {
        // 빈 벡터는 빈 리스트(nullptr)로 취급
        lists.push_back(v.empty() ? nullptr : buildList(v));
    }
    return lists;
}

static string to_string_list(const ListNode* head) {
    string s = "[";
    const ListNode* p = head;
    while (p) {
        s += std::to_string(p->val);
        if (p->next) s += ",";
        p = p->next;
    }
    s += "]";
    return s;
}

static bool equal_list(const ListNode* a, const ListNode* b) {
    while (a && b) {
        if (a->val != b->val) return false;
        a = a->next; b = b->next;
    }
    return a == nullptr && b == nullptr;
}

static void freeList(ListNode* head) {
    while (head) {
        ListNode* nx = head->next;
        delete head;
        head = nx;
    }
}

static void freeLists(vector<ListNode*>& lists) {
    for (auto* p : lists) freeList(p);
    lists.clear();
}

// ----- 단일 케이스 실행 -----
static void run_case(int case_no,
                     const vector<vector<int>>& input_lists,
                     const vector<int>& expected_vec) {
    Solution sol;

    // 입력 리스트 빌드 (주의: sol.mergeKLists가 내부 노드를 재사용할 수 있음)
    auto lists = buildLists(input_lists);

    // 기대값도 리스트로 만들어 비교
    ListNode* expected = buildList(expected_vec);

    // 실행
    ListNode* result = sol.mergeKLists(lists);

    // 결과 출력
    bool ok = equal_list(result, expected);
    std::println("Case {}: {}", case_no, ok ? "OK" : "FAIL");
    std::println("  input   : {}", [&]{
        // 입력도 보기 좋게 출력
        string s = "[";
        for (size_t i=0;i<input_lists.size();++i) {
            s += "[";
            for (size_t j=0;j<input_lists[i].size();++j) {
                s += to_string(input_lists[i][j]);
                if (j+1<input_lists[i].size()) s += ",";
            }
            s += "]";
            if (i+1<input_lists.size()) s += ",";
        }
        s += "]";
        return s;
    }());
    std::println("  expected: {}", to_string_list(expected));
    std::println("  result  : {}", to_string_list(result));

    // 메모리 정리
    // 주의: mergeKLists가 새 노드로 합쳤다면 원본 lists의 노드와 분리됨
    // 안전하게 result, expected 모두 free. 원본 lists도 free.
    freeList(result);
    freeList(expected);
    freeLists(lists);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example 1
    run_case(1, {{1,4,5},{1,3,4},{2,6}}, {1,1,2,3,4,4,5,6});

    // Example 2: lists = []
    run_case(2, {}, {});

    // Example 3: lists = [[]]
    // "빈 리스트 하나"를 의미하므로 입력에 빈 벡터를 하나 넣습니다.
    run_case(3, {{}}, {});

    return 0;
}
