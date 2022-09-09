class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int m=s1.size();
        int n=s2.size();
        
        if(m>n) return false;
        
        unordered_map<char, int>mp1, mp2;
        
        for(auto it:s1){
            mp1[it]++;
        }
        
        
        int i=0;
        int j=0;
        // string temp="";
        
        while(j<n){
          
            mp2[s2[j]]++;
            
            if((j-i+1) < m){
                j++;
            }
            
            else if((j-i+1) == m){
                
                if(mp2==mp1){
                    return true;
                }
                
                mp2[s2[i]]--;
                if(mp2[s2[i]]==0){
                    mp2.erase(s2[i]);
                }
                i++;
                j++;   
            }

        }
        return false;        
    }
};