/**
* 2353. Design a Food Rating System
* Design a food rating system that can do the following:
* 
* - Modify the rating of a food item listed in the system.
* - Return the highest-rated food item for a type of cuisine in the system.
* Implement the FoodRatings class:
* 
* - FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. The food items are described by foods, cuisines and ratings, all of which have a length of n.
*   - foods[i] is the name of the ith food,
*   - cuisines[i] is the type of cuisine of the ith food, and
*   - ratings[i] is the initial rating of the ith food.
* - void changeRating(String food, int newRating) Changes the rating of the food item with the name food.
* - String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. If there is a tie, return the item with the lexicographically smaller name.
* Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.
* 
* 
* 
* Example 1:
* 
* Input
* ["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
* [[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
* Output
* [null, "kimchi", "ramen", null, "sushi", null, "ramen"]
* 
* Explanation
* FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
* foodRatings.highestRated("korean"); // return "kimchi"
*                                     // "kimchi" is the highest rated korean food with a rating of 9.
* foodRatings.highestRated("japanese"); // return "ramen"
*                                       // "ramen" is the highest rated japanese food with a rating of 14.
* foodRatings.changeRating("sushi", 16); // "sushi" now has a rating of 16.
* foodRatings.highestRated("japanese"); // return "sushi"
*                                       // "sushi" is the highest rated japanese food with a rating of 16.
* foodRatings.changeRating("ramen", 16); // "ramen" now has a rating of 16.
* foodRatings.highestRated("japanese"); // return "ramen"
*                                       // Both "sushi" and "ramen" have a rating of 16.
*                                       // However, "ramen" is lexicographically smaller than "sushi".
* 
* 
* Constraints:
* 
* 1 <= n <= 2 * 104
* n == foods.length == cuisines.length == ratings.length
* 1 <= foods[i].length, cuisines[i].length <= 10
* foods[i], cuisines[i] consist of lowercase English letters.
* 1 <= ratings[i] <= 108
* All the strings in foods are distinct.
* food will be the name of a food item in the system across all calls to changeRating.
* cuisine will be a type of cuisine of at least one food item in the system across all calls to highestRated.
* At most 2 * 104 calls in total will be made to changeRating and highestRated.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

struct Cmp {
    // rating 내림차순, name 오름차순
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};

class FoodRatings {
private:
    unordered_map<string, string> food2cuisine;
    unordered_map<string, int>    food2rating;
    unordered_map<string, set<pair<int,string>, Cmp>> c2set;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        const int n = (int)foods.size();
        food2cuisine.reserve(n * 2);
        food2rating.reserve(n * 2);
        for (int i = 0; i < n; ++i) {
            const string& f = foods[i];
            const string& c = cuisines[i];
            int r = ratings[i];
            food2cuisine[f] = c;
            food2rating[f]  = r;
            c2set[c].insert({r, f});
        }
    }

    void changeRating(string food, int newRating) {
        auto& c = food2cuisine[food];
        int old = food2rating[food];

        auto& s = c2set[c];
        auto it = s.find({old, food});
        if (it != s.end()) s.erase(it);

        food2rating[food] = newRating;
        s.insert({newRating, food});
    }

    string highestRated(string cuisine) {
        const auto& s = c2set[cuisine];
        return s.begin()->second;
    }
};


#if 0
class FoodRatings {
private:
	unordered_map<string,string> cuisine_index;
	//menu : cusine
	unordered_map<string,map<int,vector<string>>> fr;
	//cusine ( rating: menus )
	unordered_map<string,int> rating_index;
	//menu: rating
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
		for(int i = 0; i < cuisines.size(); ++i){
			fr[cuisines[i]][ratings[i]].push_back(foods[i]);
			cuisine_index[foods[i]] = cuisines[i];
			rating_index[foods[i]] = ratings[i];
		}
    }
    void changeRating(string food, int newRating) {
		string cu = cuisine_index[food];
		int rate = rating_index[food];

		fr[cu][newRating].push_back(food);
		for(int i = 0 ; i < fr[cu][rate].size(); ++i){
			if(fr[cu][rate][i] == food)
				fr[cu][rate].erase(fr[cu][rate].begin()+i);
		}
    }
    string highestRated(string cuisine) {
		return fr[cuisine].begin().begin();
    }
};
#endif

int main() {
    vector<string> foods     = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines  = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int>    ratings   = {9, 12, 8, 15, 14, 7};

    FoodRatings foodRatings(foods, cuisines, ratings);

    cout << foodRatings.highestRated("korean") << "\n";   // kimchi
    cout << foodRatings.highestRated("japanese") << "\n"; // ramen

    foodRatings.changeRating("sushi", 16);
    cout << foodRatings.highestRated("japanese") << "\n"; // sushi

    foodRatings.changeRating("ramen", 16);
    cout << foodRatings.highestRated("japanese") << "\n"; // ramen (lexicographically smaller)

    return 0;
}
