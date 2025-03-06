/**
 * Knuth-Morris-Pratt (KMP) Algorithm
 *  - https://www-igm.univ-mlv.fr/~lecroq/string/node8.html#SECTION0080
 */
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

/* Preprocess the pattern to create the partial match table. This table helps
 * in skipping unnecessary character comparisons during the search. */
void pre_kmp(string& target, vector<int>& index)
{
	int size = target.size();
	index.resize(size);
	int j = 0;

	for(int i = 1; i < size ; i++){
		while (j>0 && target[i] != target[j])
			j = index[j-1];
		if(target[i] == target[j])
			index[i] = ++j;
	}
}

vector<int> kmp(string& target, string& str)
{
	const int ts = target.length();
	const int ss = str.length();
	/* index stores the longest proper prefix that is also a suffix for
	 * substrings of target. */
	vector<int> index(ts + 1, 0);
	vector<int> res;

	pre_kmp(target, index);

	int j = 0;
	for( int i = 0; i< ss; i++){
		while(j>0 && str[i] != target[j]){
			j = index[j-1];
		}
		if(str[i] == target[j]){
			if(j == ts-1){
				res.push_back(i-ts+2);
				j = index[j];
			}else{
				j++;
			}
		}
	}

	return res;
}

void print(const vector<int>& ret, const vector<int>& ans);

int main()
{
	string target;
	string str;
	vector<int> ret;
	vector<int> ans;

	str = "GCATCGCAGAGAGTATACAGTACG";
	target = "GCAGAGAG";
	ret = kmp(target, str);
	ans = {5};
	print(ret, ans);

	target = "gagggagg";
	str = "alskdjf alskdjflas gagggagg lkasjdflkasd lasjdflaskjd gagggagg";
	ret = kmp(target, str);
	ans = {19, 54};
	print(ret, ans);

	return 0;
}

void print(const vector<int>& ret, const vector<int>& ans)
{
	cout << "{";
	for (int i = 0; i < ans.size(); ++i) {
		assert(ret[i] == ans[i]);
		cout << ret[i];
		if (i != ans.size() - 1)
			cout << ",";
	}
	cout << "}" << endl;
}
