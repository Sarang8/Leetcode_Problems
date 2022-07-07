class Solution {
public:
    int dp[205][205];
    
    bool solve(string s1, string s2, string s3, int p1, int p2, int p3){
        
        //BC
        if(p3<0){
            if(p1<0 && p2<0){
                return true;
            }
        }

        
        if(p1>=0 && p2>=0 && p3>=0 && dp[p1][p2]!=-1){
            return dp[p1][p2];
        }
        
        if(p1>=0 && p2>=0 && p3>=0 && s1[p1]==s3[p3] && s2[p2]==s3[p3]){
            return dp[p1][p2] = (solve(s1,s2,s3,p1-1,p2,p3-1)  or solve(s1,s2,s3,p1,p2-1,p3-1));
        }
        
        else if(p1>=0 && p3>=0 && s1[p1]==s3[p3]){
            return solve(s1,s2,s3,p1-1,p2,p3-1);
        }
        
        else if(p2>=0 && p3>=0 && s2[p2]==s3[p3]){
            return solve(s1,s2,s3,p1,p2-1,p3-1);
        }
        return false;  
    }
    
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        if((l1+l2)!=l3){
            return false;
        }
        
        int p1=l1-1;
        int p2=l2-1; 
        int p3=l3-1;
        memset(dp, -1, sizeof(dp));
        
        return solve(s1,s2,s3,p1,p2,p3);
    }
};