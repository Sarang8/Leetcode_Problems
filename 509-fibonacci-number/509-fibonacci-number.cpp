class Solution {
public:
    int fib(int n) {
        
        if(n==0){
            return 0;
        }
        
        vector<int>dp(n+1, 0);
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2; i<n+1; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        
        return dp[n];
        

//         int n1 = 0;
//         int n2 = 1;
//         int sum=0;
//         while(n>0){
//             sum = n1+n2;
//             n1=n2;
//             n2=sum;
//             n--;
//         }
//         return n1;
        
    }
};