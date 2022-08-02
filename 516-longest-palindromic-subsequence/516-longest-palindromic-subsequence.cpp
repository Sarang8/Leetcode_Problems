class Solution {
public:
    
    int solve(string &s, string &p, int &x, int &y){
        
        int t[x+1][y+1];
        
        for(int i=0; i<x+1; i++){
            for(int j=0; j<y+1; j++){
                
                if(i==0 or j==0){
                    t[i][j]=0;
                }
            }
        }
        
          for(int i=1; i<x+1; i++){
            for(int j=1; j<y+1; j++){
                
                if(s[i-1]==p[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                
                else{
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                    
                }
            }
             
          }
        
        return t[x][y];
        
    }

    
    
    
    
    
    int longestPalindromeSubseq(string s) {
        
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int x = s1.size();
        int y = s2.size();
        
        return solve(s1, s2 , x, y);   
    }
};