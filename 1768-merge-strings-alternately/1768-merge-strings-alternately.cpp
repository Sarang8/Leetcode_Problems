class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int n=word1.size();
        int m = word2.size();
        string ans="";
        
        int i=0,j=0;
        int k=0;
        
        while(i<n && j<m){
            ans+=word1[i];
            i++;
            
            ans+=word2[j];
            j++;          
        }
        
        if(j<m){
            while(j<m){
                ans+=word2[j];
                j++;
            }
        }
        
        else{
            while(i<n){
                ans+=word1[i];
                i++;
            }
        }
        
        
        
     return ans;   
    }
};