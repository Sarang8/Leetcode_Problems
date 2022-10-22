class Solution {
public:
    int dp[35][3005];
    bool SubsetSum(vector<int>& v, int target, int i) {
        if(target == 0)
            return 1;
        if(i >= v.size())
            return 0;
        
        if(dp[i][target] != -1)
            return dp[i][target];
        
        
        if(v[i] > target)
            return dp[i][target] = SubsetSum(v, target, i+1);
        return dp[i][target] = SubsetSum(v, target - v[i], i+1) || SubsetSum(v, target, i+1);
    }
    
    
    
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for(auto i : stones)
            sum += i;
        
        int mindiff = INT_MAX;
        for(int i = (sum/2)+1; i >= 0; i--)     // i is sum of the partation
            if(SubsetSum(stones, i, 0)) 
                mindiff = min(mindiff, abs((sum - i)-i)); 
        
        return mindiff;
    }
    
    
    
};