/**
* 3484. Design Spreadsheet
* A spreadsheet is a grid with 26 columns (labeled from 'A' to 'Z') and a given number of rows. Each cell in the spreadsheet can hold an integer value between 0 and 105.
* 
* Implement the Spreadsheet class:
* 
* Spreadsheet(int rows) Initializes a spreadsheet with 26 columns (labeled 'A' to 'Z') and the specified number of rows. All cells are initially set to 0.
* void setCell(String cell, int value) Sets the value of the specified cell. The cell reference is provided in the format "AX" (e.g., "A1", "B10"), where the letter represents the column (from 'A' to 'Z') and the number represents a 1-indexed row.
* void resetCell(String cell) Resets the specified cell to 0.
* int getValue(String formula) Evaluates a formula of the form "=X+Y", where X and Y are either cell references or non-negative integers, and returns the computed sum.
* Note: If getValue references a cell that has not been explicitly set using setCell, its value is considered 0.
* 
* 
* 
* Example 1:
* 
* Input:
* ["Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"]
* [[3], ["=5+7"], ["A1", 10], ["=A1+6"], ["B2", 15], ["=A1+B2"], ["A1"], ["=A1+B2"]]
* 
* Output:
* [null, 12, null, 16, null, 25, null, 15]
* 
* Explanation
* 
* Spreadsheet spreadsheet = new Spreadsheet(3); // Initializes a spreadsheet with 3 rows and 26 columns
* spreadsheet.getValue("=5+7"); // returns 12 (5+7)
* spreadsheet.setCell("A1", 10); // sets A1 to 10
* spreadsheet.getValue("=A1+6"); // returns 16 (10+6)
* spreadsheet.setCell("B2", 15); // sets B2 to 15
* spreadsheet.getValue("=A1+B2"); // returns 25 (10+15)
* spreadsheet.resetCell("A1"); // resets A1 to 0
* spreadsheet.getValue("=A1+B2"); // returns 15 (0+15)
* 
* 
* Constraints:
* 
* 1 <= rows <= 103
* 0 <= value <= 105
* The formula is always in the format "=X+Y", where X and Y are either valid cell references or non-negative integers with values less than or equal to 105.
* Each cell reference consists of a capital letter from 'A' to 'Z' followed by a row number between 1 and rows.
* At most 104 calls will be made in total to setCell, resetCell, and getValue.
*
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <regex>
#include <unordered_map>

using namespace std;
#if 0
class Spreadsheet {
private:
	unordered_map<char,vector<int>> sheet;
	pair<char,int> seperateCell(string cell){
		regex re("([A-Z])([0-9]+)");
		smatch match;

		if (regex_match(cell,match,re))
			return {match[1].str()[0],stoi(match[2].str())};

		return {'e',stoi(cell)};

	}
public:
    Spreadsheet(int rows) {
		for(int i = 0 ; i < 26 ; ++i){
			sheet[i+'A'] = vector<int>(rows+1);
		}
    }
    void setCell(string cell, int value) {
       pair<char,int> locate = seperateCell(cell);
	   sheet[locate.first][locate.second] = value;
	}
    void resetCell(string cell) {
		pair<char,int> locate = seperateCell(cell);
		sheet[locate.first][locate.second] = 0;
    }
    
    int getValue(string formula) {
		regex form(R"(=([A-Z][0-9]+|\d+)\+([A-Z][0-9]+|\d+))");
		smatch form_match;
		int one = 0, two = 0;

		if(regex_match(formula,form_match,form)){
			pair<char,int> foo = seperateCell(form_match[1].str());
			pair<char,int> bar = seperateCell(form_match[2].str());
			if(foo.first != 'e')
				one = sheet[foo.first][foo.second];
			else
				one = foo.second;
			if(bar.first != 'e')
				two = sheet[bar.first][bar.second];
			else
				two = bar.second;
		}
		return one+two;

    }
};
#else
class Spreadsheet {
private:
    vector<vector<int>> sheet;
    int evalTerm(const string& s, size_t l, size_t r) const {
        if (isdigit(s[l])) {
            int v = 0;
            for (size_t i = l; i < r; ++i) v = v * 10 + (s[i] - '0');
            return v;
        } else {
            int col = s[l] - 'A';
            int row = 0;
            for (size_t i = l + 1; i < r; ++i) row = row * 10 + (s[i] - '0');
            return sheet[col][row];
        }
    }

public:
    Spreadsheet(int rows) : sheet(26, vector<int>(rows + 1, 0)) {}

    void setCell(const string& cell, int value) {
        int col = cell[0] - 'A';
        int row = 0;
        for (size_t i = 1; i < cell.size(); ++i) row = row * 10 + (cell[i] - '0');
        sheet[col][row] = value;
    }

    void resetCell(const string& cell) {
        int col = cell[0] - 'A';
        int row = 0;
        for (size_t i = 1; i < cell.size(); ++i) row = row * 10 + (cell[i] - '0');
        sheet[col][row] = 0;
    }

    int getValue(const string& formula) {
        size_t plusPos = formula.find('+');
        int left  = evalTerm(formula, 1, plusPos);
        int right = evalTerm(formula, plusPos + 1, formula.size());
        return left + right;
    }
};
#endif

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

int main() {
	int rows = 3;
	Spreadsheet *st = new Spreadsheet(rows);

	println("ans : {}",st->getValue("=5+7"));
	st->setCell("A1", 10);
	println("ans : {}",st->getValue("=A1+6"));
	st->setCell("B2", 15);
	println("ans : {}",st->getValue("=A1+B2"));
	st->resetCell("A1");
	println("ans : {}",st->getValue("=A1+B2"));

    return 0;
}
