class Solution {
public:
//     int ones=0;
//     int zeros=0;
//     bool check(string s, int &ones, int &zeros, int m, int n){
        
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='1'){
//                 ones+=1;
//             }
//             else{
//                 zeros+=1;
//             }
//         }
        
//         if(ones<=n && zeros<=n){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
    
    int solve(int ind, int ones, int zeros, vector<string>& strs, int m, int n,  vector<vector<vector<int>>>&dp){
        
        if(ind>=strs.size()){
            return 0;
        }
        
         if(ones > n || zeros > m)
            return 0;
        
        if(dp[ind][ones][zeros]!=-1) return dp[ind][ones][zeros];
        
        
        int t1=0, t0=0;
        
        string s=strs[ind];
        for(int i=0;i<strs[ind].size();i++){
            if(s[i]=='1'){
                t1+=1;
            }
            else{
                t0+=1;
            }
        }
        
        int op1=0, op2=0, op3=0;
        
        if(ones+t1<=n && zeros+t0<=m){
           op1 += 1+solve(ind+1, ones+t1, zeros+t0, strs, m, n, dp); 
           op2 += 0+solve(ind+1, ones, zeros, strs, m, n, dp);
        }
        else{
            op3 += 0+solve(ind+1, ones, zeros, strs, m, n, dp);
        }
        
        // if(check(strs[ind], ones, zeros,m, n)){
        //     t1 += 1+solve(ind+1, ones, zeros, strs, m, n); 
        // }
        // else{
        //     t2 = 0+solve(ind+1, ones, zeros, strs, m, n);
        // }
        
        
        return dp[ind][ones][zeros]=max(op3, max(op1,op2));
    }
    
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int size=strs.size();
        vector<vector<vector<int>>>dp(size+1, vector<vector<int>>(105, vector<int>(105, -1)));
        
        return solve(0, 0, 0, strs, m,n, dp);
        
    }
};