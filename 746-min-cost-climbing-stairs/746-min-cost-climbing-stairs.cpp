class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        int dp[n];
        //dp[1]=cost[0];
        //dp[2] = cost[1];
        
        for(int i=0; i<n; i++){
            
            if(i>=2){
                int onestep = dp[i-1];
                int twostep = dp[i-2];


                dp[i] = cost[i]+min(onestep,twostep);
                }
            else{
                dp[i] = cost[i];   
            }
            
        }
        
        return min(dp[n-1], dp[n-2]);
        
    }
};