/**
* 2115. Find All Possible Recipes from Given Supplies
* You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.
* 
* You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
* 
* Return a list of all the recipes that you can create. You may return the answer in any order.
* 
* Note that two recipes may contain each other in their ingredients.
* 
*  
* 
* Example 1:
* 
* Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
* Output: ["bread"]
* Explanation:
* We can create "bread" since we have the ingredients "yeast" and "flour".
* Example 2:
* 
* Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
* Output: ["bread","sandwich"]
* Explanation:
* We can create "bread" since we have the ingredients "yeast" and "flour".
* We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
* Example 3:
* 
* Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
* Output: ["bread","sandwich","burger"]
* Explanation:
* We can create "bread" since we have the ingredients "yeast" and "flour".
* We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
* We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
*  
* 
* Constraints:
* 
* n == recipes.length == ingredients.length
* 1 <= n <= 100
* 1 <= ingredients[i].length, supplies.length <= 100
* 1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
* recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
* All the values of recipes and supplies combined are unique.
* Each ingredients[i] does not contain any duplicate values.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std; //편의성위해..
#if 0
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
		unordered_map<string,int> supplies_map;
		vector<string> res;
		for (const string& item : supplies)
		    supplies_map[item] = 1;

		for(int i = 0; i < ingredients.size();i++){
			bool possible = true;
			for(const string& ci:ingredients[i]){
				if(supplies_map[ci] == 0){
					possible = false;
					break;
				}
			}
			if(possible){
				res.push_back(recipes[i]);
				supplies_map[recipes[i]] = 1;
			}
		}
		return res;
    }
};
#else

class Solution {
public:
	vector<string> findAllRecipes(vector<string>& recipes,
			vector<vector<string>>& ingredients, vector<string>& supplies) {
		// {ingredient : {recipes}}
		unordered_map<string, vector<string>> rev_adj_list;
		// {recipe : indegree}
		unordered_map<string, int> indegree;
		unordered_set<string> lookup(begin(supplies), end(supplies));

		for (const string& recipe : recipes)
			indegree[recipe] = 0;

		for (int i = 0; i < recipes.size(); ++i)
			for (const string& ingredient : ingredients[i])
				if (lookup.find(ingredient) == lookup.end()) {
					rev_adj_list[ingredient].push_back(recipes[i]);
					indegree[recipes[i]]++;
				}

		// recipe
		queue<string> q;
		vector<string> res;

		for (const auto& [recipe, in] : indegree)
			if (in == 0)
				q.push(recipe);

		// Topological sort
		// Kahn's algorithm
		while (!q.empty()) {
			string curr = q.front();
			q.pop();
			res.push_back(curr);

			for (const string& nei : rev_adj_list[curr]) {
				indegree[nei]--;

				if (indegree[nei] == 0)
					q.push(nei);
			}
		}

		return res;
    }
};

#endif
int main() {
	Solution sol;
	vector<string> recipes;
	vector<vector<string>> ingredients;
	vector<string> supplies;
	vector<string> ans;
	vector<string> res;

	recipes = {"bread"};
	ingredients = {{"yeast","flour"}};
	supplies = {"yeast","flour","corn"};
	ans = {"bread"};
	res = sol.findAllRecipes(recipes, ingredients,supplies);
	println("ans : {} \nres: {}",ans,res);

	recipes = {"bread","sandwich"};
	ingredients = {{"yeast","flour"},{"bread","meat"}};
	supplies = {"yeast","flour","meat"};
	ans = {"bread","sandwich"};
	res = sol.findAllRecipes(recipes, ingredients,supplies);
	println("ans : {} \nres: {}",ans,res);


	recipes = {"bread","sandwich","burger"};
	ingredients = {{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}};
	supplies = {"yeast","flour","meat"};
	ans = {"bread","sandwich","burger"};
	res = sol.findAllRecipes(recipes, ingredients,supplies);
	println("ans : {} \nres: {}",ans,res);


	cout << "Accepted!" <<endl;
    return 0;
}
