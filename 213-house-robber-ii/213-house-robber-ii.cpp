class Solution {
public:
    
    int solve(vector<int>& temp){
        
        int n=temp.size();
        vector<int>dp(n);
        int pick;
        int Notpick;
        
        dp[0] = temp[0];
        
        for(int i=1; i<n; i++){
            
            pick = temp[i];
            if(i>1){
                pick += dp[i-2];
            }
            Notpick = dp[i-1];
            dp[i] = max(pick, Notpick);
        } 
        return dp[n-1];
    }
    
    
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        vector<int>temp1,temp2;
        
        for(int i=0; i<n; i++){
            
            if(i!=0)   temp1.push_back(nums[i]);
            
            if(i!=n-1)   temp2.push_back(nums[i]);
        }
        
        return max(solve(temp1), solve(temp2));
        
        
    }
};