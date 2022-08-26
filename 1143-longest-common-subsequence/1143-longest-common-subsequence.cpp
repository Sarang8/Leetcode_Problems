class Solution {
public:
    
    int solve(string s1, string s2, int x, int y){
        
        int t[x+1][y+1];
        
        for(int i=0; i<x+1; i++){
            for(int j=0; j<y+1; j++){
                if(i==0 or j==0){
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i=1; i<x+1; i++){
            for(int j=1; j<y+1; j++){
        
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }      
            }
        }
        return t[x][y];  
    }
    
    
    
    
    
    
    int longestCommonSubsequence(string text1, string text2) {

        int x= text1.length();
        int y= text2.length();
        return solve(text1, text2, x,y);
        
    }
};