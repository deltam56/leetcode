/**
* 3408. Design Task Manager
* There is a task management system that allows users to manage their tasks, each associated with a priority. The system should efficiently handle adding, modifying, executing, and removing tasks.
* 
* Implement the TaskManager class:
* 
* TaskManager(vector<vector<int>>& tasks) initializes the task manager with a list of user-task-priority triples. Each element in the input list is of the form [userId, taskId, priority], which adds a task to the specified user with the given priority.
* 
* void add(int userId, int taskId, int priority) adds a task with the specified taskId and priority to the user with userId. It is guaranteed that taskId does not exist in the system.
* 
* void edit(int taskId, int newPriority) updates the priority of the existing taskId to newPriority. It is guaranteed that taskId exists in the system.
* 
* void rmv(int taskId) removes the task identified by taskId from the system. It is guaranteed that taskId exists in the system.
* 
* int execTop() executes the task with the highest priority across all users. If there are multiple tasks with the same highest priority, execute the one with the highest taskId. After executing, the taskId is removed from the system. Return the userId associated with the executed task. If no tasks are available, return -1.
* 
* Note that a user may be assigned multiple tasks.
* 
*  
* 
* Example 1:
* 
* Input:
* ["TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"]
* [[[[1, 101, 10], [2, 102, 20], [3, 103, 15]]], [4, 104, 5], [102, 8], [], [101], [5, 105, 15], []]
* 
* Output:
* [null, null, null, 3, null, null, 5]
* 
* Explanation
* 
* TaskManager taskManager = new TaskManager([[1, 101, 10], [2, 102, 20], [3, 103, 15]]); // Initializes with three tasks for Users 1, 2, and 3.
* taskManager.add(4, 104, 5); // Adds task 104 with priority 5 for User 4.
* taskManager.edit(102, 8); // Updates priority of task 102 to 8.
* taskManager.execTop(); // return 3. Executes task 103 for User 3.
* taskManager.rmv(101); // Removes task 101 from the system.
* taskManager.add(5, 105, 15); // Adds task 105 with priority 15 for User 5.
* taskManager.execTop(); // return 5. Executes task 105 for User 5.
*  
* 
* Constraints:
* 
* 1 <= tasks.length <= 10^5
* 0 <= userId <= 10^5
* 0 <= taskId <= 10^5
* 0 <= priority <= 10^9
* 0 <= newPriority <= 10^9
* At most 2 * 10^5 calls will be made in total to add, edit, rmv, and execTop methods.
* The input is generated such that taskId will be valid.
**/

#include <iostream>
#include <cassert>
#include <vector>
#include <print>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class TaskManager {
private:
    map<int, map<int, int>> buckets;
    unordered_map<int, int> task_to_prio;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& t : tasks) {
            int userId = t[0], taskId = t[1], prio = t[2];
            buckets[prio][taskId] = userId;
            task_to_prio[taskId] = prio;
        }
    }

    void add(int userId, int taskId, int priority) {
        buckets[priority][taskId] = userId;
        task_to_prio[taskId] = priority;
    }

    void edit(int taskId, int newPriority) {
        int oldP = task_to_prio[taskId];
        auto& inner = buckets[oldP];
        auto it = inner.find(taskId);
        int userId = it->second;
        inner.erase(it);
        if (inner.empty()) buckets.erase(oldP);
        buckets[newPriority][taskId] = userId;
        task_to_prio[taskId] = newPriority;
    }

    void rmv(int taskId) {
        int prio = task_to_prio[taskId];
        auto& inner = buckets[prio];
        inner.erase(taskId);
        if (inner.empty()) buckets.erase(prio);
        task_to_prio.erase(taskId);
    }

    int execTop() {
        if (buckets.empty()) return -1;
        auto oit = buckets.rbegin();
        int prio = oit->first;
        auto& inner = const_cast<map<int,int>&>(oit->second);

        auto iit = inner.rbegin();
        int taskId = iit->first;
        int userId = iit->second;

        inner.erase(taskId);
        if (inner.empty()) {
            buckets.erase(prio);
        }
        task_to_prio.erase(taskId);

        return userId;
    }
};

/*
class TaskManager {
private:
	map<int,unordered_map<int,int>> taskmaps;
		// prio( task : user)
	unordered_map<int,int> task_index;
		// task: prio
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto t: tasks){
			taskmaps[t[2]][t[1]] = t[0];
			task_index[t[1]] = t[2];
		}
    }
    void add(int userId, int taskId, int priority) {
        taskmaps[priority][taskId] = userId;
    }
    void edit(int taskId, int newPriority) {
        //delete priv
		int user = taskmaps[task_index[taskId]];
		auto& it = taskmaps[task_index[taskId]].find(taskId);
		taskmaps[task_index[taskId]].erase(it);
		//insert new
		taskmaps[newPiority][taskId] = 
    }
    
    void rmv(int taskId) {
        //delete Task
		auto& it = taskmaps[task_index[taskId]].find(taskId);
		taskmaps[task_index[taskId]].erase(it);
    }
    
    int execTop() {
		int ret = taskmaps.begin().begin();
    }
};
*/
/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

int main() {
	vector<vector<int>> init = {{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
	TaskManager tm(init);
	tm.add(4, 104, 5);
	tm.edit(102, 8);
	println("execTop : {}",tm.execTop());
	tm.rmv(101);
	tm.add(5, 105, 15);
	println("execTop : {}",tm.execTop());


    return 0;
}
