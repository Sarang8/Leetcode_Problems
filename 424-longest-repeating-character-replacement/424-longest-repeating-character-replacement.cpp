class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n=s.size();
        unordered_map<char, int>m;
        
        int i=0;
        int j=0;
        int ans=0;
        int maxrepeat=0;
        
        while(j<n){
            
            m[s[j]]++;
            maxrepeat=max(maxrepeat, m[s[j]]);
    
            
            if((j-i+1)-maxrepeat > k){
                while((j-i+1)-maxrepeat > k){
                    m[s[i]]--;
                    i++;
                }
            }
            
            ans=max(ans, j-i+1);
            
            j++;
        }
        
        
        
        return ans;
    }
};