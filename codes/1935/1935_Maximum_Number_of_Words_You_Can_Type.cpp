/**
 * 1935. Maximum Number of Words You Can Type
 * There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
 * 
 * Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: text = "hello world", brokenLetters = "ad"
 * Output: 1
 * Explanation: We cannot type "world" because the 'd' key is broken.
 * Example 2:
 * 
 * Input: text = "leet code", brokenLetters = "lt"
 * Output: 1
 * Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
 * Example 3:
 * 
 * Input: text = "leet code", brokenLetters = "e"
 * Output: 0
 * Explanation: We cannot type either word because the 'e' key is broken.
 *  
 * 
 * Constraints:
 * 
 * 1 <= text.length <= 104
 * 0 <= brokenLetters.length <= 26
 * text consists of words separated by a single space without any leading or trailing spaces.
 * Each word only consists of lowercase English letters.
 * brokenLetters consists of distinct lowercase English letters.
 **/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	int canBeTypedWords(string text, string brokenLetters) {
		int count = 0;
		vector<string> words;
		istringstream iss(text);
		string word;
		while(iss >> word){
			words.push_back(word);
		}

		for(string w : words){
			bool broken = false;
			for(char c: brokenLetters){
				if(w.find(c) != string::npos){
					broken = true;
					break;
				}
			}
			if(!broken)
				count++;
		}

		return count;
	}
};

int main() {
	Solution sol;
	string text, brokenLetters;
	int ans,res;

	text = "hello world", brokenLetters = "ad";
	ans = 1;
	res = sol.canBeTypedWords(text,brokenLetters);
	println("ans : {}, res : {}",ans,res);

	text = "leet code", brokenLetters = "lt";
	ans = 1;
	res = sol.canBeTypedWords(text,brokenLetters);
	println("ans : {}, res : {}",ans,res);

	text = "leet code", brokenLetters = "e";
	ans = 0;
	res = sol.canBeTypedWords(text,brokenLetters);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
