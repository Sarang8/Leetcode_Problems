class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int>ans;
        unordered_map<char ,int>m;   // <char, lasIndx
        
        for(int i=0; i<s.size(); i++){
            m[s[i]] = i;
        }
        
        
        int prev=-1; 
        int maxi=0;
        
        for(int i=0; i<s.size(); i++){
            
            maxi = max(maxi, m[s[i]]);
            
            if(maxi==i){
                ans.push_back(maxi-prev);
                prev=maxi;
            }
            
        }
        
        return ans;
        
    }
};