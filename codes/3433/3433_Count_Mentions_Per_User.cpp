/**
 * 3433. Count Mentions Per User
 * You are given an integer numberOfUsers representing the total number of users and an array events of size n x 3.
 * 
 * Each events[i] can be either of the following two types:
 * 
 * Message Event: ["MESSAGE", "timestampi", "mentions_stringi"]
 * This event indicates that a set of users was mentioned in a message at timestampi.
 * The mentions_stringi string can contain one of the following tokens:
 * id<number>: where <number> is an integer in range [0,numberOfUsers - 1]. There can be multiple ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.
 * ALL: mentions all users.
 * HERE: mentions all online users.
 * Offline Event: ["OFFLINE", "timestampi", "idi"]
 * This event indicates that the user idi had become offline at timestampi for 60 time units. The user will automatically be online again at time timestampi + 60.
 * Return an array mentions where mentions[i] represents the number of mentions the user with id i has across all MESSAGE events.
 * 
 * All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.
 * 
 * Note that a user can be mentioned multiple times in a single message event, and each mention should be counted separately.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]
 * 
 * Output: [2,2]
 * 
 * Explanation:
 * 
 * Initially, all users are online.
 * 
 * At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]
 * 
 * At timestamp 11, id0 goes offline.
 * 
 * At timestamp 71, id0 comes back online and "HERE" is mentioned. mentions = [2,2]
 * 
 * Example 2:
 * 
 * Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","12","ALL"]]
 * 
 * Output: [2,2]
 * 
 * Explanation:
 * 
 * Initially, all users are online.
 * 
 * At timestamp 10, id1 and id0 are mentioned. mentions = [1,1]
 * 
 * At timestamp 11, id0 goes offline.
 * 
 * At timestamp 12, "ALL" is mentioned. This includes offline users, so both id0 and id1 are mentioned. mentions = [2,2]
 * 
 * Example 3:
 * 
 * Input: numberOfUsers = 2, events = [["OFFLINE","10","0"],["MESSAGE","12","HERE"]]
 * 
 * Output: [0,1]
 * 
 * Explanation:
 * 
 * Initially, all users are online.
 * 
 * At timestamp 10, id0 goes offline.
 * 
 * At timestamp 12, "HERE" is mentioned. Because id0 is still offline, they will not be mentioned. mentions = [0,1]
 * 
 * 
 * 
 * Constraints:
* 
* 1 <= numberOfUsers <= 100
* 1 <= events.length <= 100
* events[i].length == 3
* events[i][0] will be one of MESSAGE or OFFLINE.
* 1 <= int(events[i][1]) <= 105
* The number of id<number> mentions in any "MESSAGE" event is between 1 and 100.
* 0 <= <number> <= numberOfUsers - 1
* It is guaranteed that the user id referenced in the OFFLINE event is online at the time the event occurs.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

class Solution {
public:
	vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
		vector<int> mentioned(numberOfUsers, 0);
		vector<int> nextmsgtime(numberOfUsers, 0);

		//timestapm 정렬
		sort(events.begin(), events.end(),
			 [](const vector<string>& a, const vector<string>& b) {
				 int ta = stoi(a[1]);
				 int tb = stoi(b[1]);
				 if (ta != tb) return ta < tb;

				 // 같은 timestamp 인 경우: OFFLINE 먼저 처리
				 bool aOffline = (a[0] == "OFFLINE");
				 bool bOffline = (b[0] == "OFFLINE");
				 if (aOffline != bOffline) return aOffline; // a가 OFFLINE이면 먼저

				 return false; // 그 외 순서는 상관 없음
			 });;

		string cmd;
		int timestamp;
		string msg;

		for(auto& event:events){
			cmd = event[0];
			timestamp = stoi(event[1]);
			msg = event[2];

			if (cmd == "MESSAGE") {
				// MESSAGE 처리
				if(msg == "ALL")
					transform(mentioned.begin(), mentioned.end(), mentioned.begin(),
							  [](int x){ return x + 1; });
				else if(msg == "HERE"){
					for(int i = 0 ; i < mentioned.size(); ++i){
						if(nextmsgtime[i] <= timestamp)
							mentioned[i]++;
					}
				}
				else{
					vector<int> ids;
					regex re("id(\\d+)");   // id + 숫자
					auto begin = sregex_iterator(msg.begin(), msg.end(), re);
					auto end   = sregex_iterator();

					for (auto it = begin; it != end; ++it) {
						mentioned[stoi((*it)[1])]++;
					}
				}
			}
			else if (cmd == "OFFLINE") {
				// nextmsgtime 을 t ~ t+60 으로 변경
				int user_idx = stoi(msg);
				nextmsgtime[user_idx] = timestamp + 60 ;
			}
		}
		return mentioned;
	}
};

int main() {
	Solution sol;
	int numberOfUsers;
	vector<vector<string>> events;
	vector<int> ans, res;

	numberOfUsers = 2, events = {{"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","71","HERE"}};
	ans = {2,2};
	res = sol.countMentions(numberOfUsers,events);
	println("ans : {}, res : {}",ans,res);

	numberOfUsers = 2, events = {{"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","12","ALL"}};
	ans = {2,2};
	res = sol.countMentions(numberOfUsers,events);
	println("ans : {}, res : {}",ans,res);

	numberOfUsers = 2, events = {{"OFFLINE","10","0"},{"MESSAGE","12","HERE"}};
	ans = {0,1};
	res = sol.countMentions(numberOfUsers,events);
	println("ans : {}, res : {}",ans,res);

	return 0;
}
