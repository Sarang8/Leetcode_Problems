/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*>map;
    
    int dfs(int id){
        
        Employee* emp = map[id];
        int ans = emp->importance;
        
        for(auto it:emp->subordinates){
                ans += dfs(it);
            }
        
        
        return ans;
        
    }
    
    
    int getImportance(vector<Employee*> employees, int id) {
       
        int n=employees.size();
        
        
        for(auto it:employees){
            map[it->id] = it;
        }
        
        
        return dfs(id);
    }
};