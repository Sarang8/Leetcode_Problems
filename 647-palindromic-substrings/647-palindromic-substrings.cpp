class Solution {
public:      
    int countSubstrings(string s) {
        
        int n=s.size();
        
        int l=0,r=0;
        int ans=0;
        
        for(int i=0; i<n; i++){
            
            //FOR ODD LENGTH STRING
            l=r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                ans++;
                l--; 
                r++;
            }
            
            //FOR EVeN LENGTH STRING
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                ans++;
                l--; 
                r++;
            }
        }
        
       return ans; 
    }        
};