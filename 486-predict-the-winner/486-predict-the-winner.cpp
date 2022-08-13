class Solution {
public:
    int dp[1001][1001];
    
        
    long long solve(vector<int>& arr, int n, int i, int j){
        
        if(i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        long long choice1 = arr[i] + min(solve(arr, n, i+2,j), solve(arr, n, i+1, j-1));
        
        long long choice2 = arr[j] + min(solve(arr, n, i+1,j-1), solve(arr, n, i, j-2));
        
        return dp[i][j] = max(choice1,choice2);
        
    }
    
    
    
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        int MaxFrstScore = solve(nums, n, 0, n-1);
        
        int Total = 0;
        for(int i=0; i<n; i++){
            Total = Total+nums[i];
        }
        
        if(MaxFrstScore >= Total-MaxFrstScore){
            return true;
        }
        else{
            return false;
        }
    }
};