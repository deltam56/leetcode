/*

   2349. Design a Number Container System
   Design a number container system that can do the following:

   Insert or Replace a number at the given index in the system.
   Return the smallest index for the given number in the system.
   Implement the NumberContainers class:

   NumberContainers() Initializes the number container system.
   void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
   int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.


  Example 1:

   Input
   ["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
   [[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
   Output
   [NULL, -1, NULL, NULL, NULL, NULL, 1, NULL, 2]

   Explanation
   NumberContainers nc = new NumberContainers();
   nc.find(10); // There is no index that is filled with number 10. Therefore, we return -1.
   nc.change(2, 10); // Your container at index 2 will be filled with number 10.
   nc.change(1, 10); // Your container at index 1 will be filled with number 10.
   nc.change(3, 10); // Your container at index 3 will be filled with number 10.
   nc.change(5, 10); // Your container at index 5 will be filled with number 10.
   nc.find(10); // Number 10 is at the indices 1, 2, 3, and 5. Since the smallest index that is filled with 10 is 1, we return 1.
   nc.change(1, 20); // Your container at index 1 will be filled with number 20. Note that index 1 was filled with 10 and then replaced with 20. 
   nc.find(10); // Number 10 is at the indices 2, 3, and 5. The smallest index that is filled with 10 is 2. Therefore, we return 2.


   Constraints:

   1 <= index, number <= 109
   At most 105 calls will be made in total to change and find.

*/

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
class NumberContainers {

public:
    unordered_map<int, int> ind_num;
    unordered_map<int, set<int>> num_inds;
    void change(int index, int number) {
        auto it = ind_num.find(index);
        if (it != end(ind_num))
            num_inds[it->second].erase(index);
        ind_num[index] = number;
        num_inds[number].insert(index);
    }
    int find(int number) {
        auto it = num_inds.find(number);
        return it == end(num_inds) || it->second.empty() ? -1 : *begin(it->second);
    }
};

void print(vector <int> ans, vector <int> res ){

	cout << "{ " ;
	for (int i: ans)
		cout <<" "<< i <<" ";
	cout << " } ";

	cout << "{ " ;
	for (int i: res)
		cout <<" "<< i <<" ";
	cout << " } ";

	assert(ans == res);
}
#if 0
constexpr unsigned int HashA(const char* str) {
	unsigned int hash = 8603; // 초기값 설정
	while (*str) {
		hash = static_cast<unsigned int>(*str) + 0xEDB8832Full * hash;
		str++;
	}
	return hash;
}
int main() {

	vector <int> ans;
	vector <int> res;
	vector <string> opstr;
	vector <vector<int>> args;

	opstr = {"NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"};
	args = {{}, {10}, {2, 10}, {1, 10}, {3, 10}, {5, 10}, {10}, {1, 20}, {10}};
	ans = {NULL, -1, NULL, NULL, NULL, NULL, 1, NULL, 2};

	for (int i = 0;i<opstr.size();i++){
		if (opstr[i] == "NumberContainers") {

			// 이미 sol 객체가 있으므로 아무것도 하지 않음
		} else if (opstr[i] == "find") {
			res.push_back(sol.find(args[i][0])); // args[i][0] 사용
		} else if (opstr[i] == "change") {
			res.push_back(0); // NULL 대신 0 사용
			sol.change(args[i][0], args[i][1]);
		} else {
			cout << "Something went wrong!!" << endl;
		}
	}

	print(ans,res);
	cout << "Accepted!" <<endl;
	return 0;
}
#else
int main()
{
	NumberContainers nc;
	int ret;

	ret = nc.find(10);
	assert(ret == -1);
	cout << ret << endl;

	nc.change(2, 10);
	nc.change(1, 10);
	nc.change(3, 10);
	nc.change(5, 10);
	// Number 10 is at the indices 1, 2, 3, and 5. Since the smallest index
	// that is filled with 10 is 1, we return 1.
	ret = nc.find(10);
	assert(ret == 1);
	cout << ret << endl;

	nc.change(1, 20);

	ret = nc.find(10);
	assert(ret == 2);
	cout << ret << endl;

	return 0;
}
#endif
