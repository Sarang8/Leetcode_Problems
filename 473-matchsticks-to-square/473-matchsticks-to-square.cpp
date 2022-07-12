class Solution {
public:
    bool backtrack(vector<int>& nums, vector<bool> &visited, int target, int curr_sum, int i, int k, int &unvisited) {
        if (k == 1) 
            return true;
        
        if(unvisited == 0 || i >= nums.size())
            return false;
        
        if (curr_sum == target) 
            return backtrack(nums, visited, target, 0, 0, k-1, unvisited);
        
        for (int j = i; j < nums.size(); j++) {
            if (visited[j] || curr_sum + nums[j] > target) continue;
            
            visited[j] = true;
            unvisited--;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k, unvisited)) return true;
            visited[j] = false;
            unvisited++;
        }
        
        return false;
    }
    
    
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        
        int k=4;
        if (matchsticks.size() < k || sum % k) return false;
        
        vector<bool> visited(matchsticks.size(), false);
        int univisited = matchsticks.size();
        return backtrack(matchsticks, visited, sum / k, 0, 0, k, univisited);
    }
};