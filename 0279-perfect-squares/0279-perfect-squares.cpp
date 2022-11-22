class Solution {
public:
    
    int dp[102][10004];
    
    int unbooundedKnapSack(int ind, vector<int>&nums, int sum){
        
        if(sum==0){
            return dp[ind][sum]=0;
        }
        
        if(ind<0){
            return 1e8;
        }
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        if(nums[ind] <= sum){
            return dp[ind][sum] = min (1+unbooundedKnapSack(ind, nums, sum-nums[ind]),   unbooundedKnapSack(ind-1, nums, sum));
        }
        
        else{
            return dp[ind][sum] = unbooundedKnapSack(ind-1, nums, sum);
        }  
    }
    
    
    int numSquares(int n) {
    
        vector<int>nums;    
        for(int i=1; i<=n; i++){
            if(i*i<=n) 
              nums.push_back(i*i);
        }
        
        //int size=nums.size();
        memset(dp,-1, sizeof(dp));
        //vector<vector<int>>dp(n+1, vector<int>(size+1, -1));
        int size=nums.size();
        return unbooundedKnapSack( size-1,  nums, n);
        
        
        
        
        
//         int dp[102][10002];

//     int UKS (vector<int> &nums, int n, int sum) { 
    
//         if (sum == 0) { 
//             return dp[n][sum] = 0;
//         } 
        
//         else if (n <= 0) { 
//             return dp[n][sum] = 1e8;
//         } 
         
//         else if (dp[n][sum] != -1) { 
//             return dp[n][sum];
//         }
//         else if (nums[n-1] > sum) { 
//             return dp[n][sum] = UKS (nums, n-1, sum);
//         } 
        
//         return dp[n][sum] = min(1 + UKS(nums, n, sum-nums[n-1]), UKS (nums, n-1, sum));
    
//     } 

//     int numSquares(int n) {  
        
//         vector<int> nums;  
        
//         memset(dp, -1, sizeof dp);
        
//         for (int i = 1; i <= n; i++) { 
            
//             if (i * i <= n) { 
                
//                 nums.push_back(i*i);
            
//             }
        
//         }  
            
//        return UKS (nums, nums.size(), n);
    }
        
    
};