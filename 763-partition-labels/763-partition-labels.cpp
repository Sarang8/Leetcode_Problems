class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n=s.size();
        unordered_map<char, int>m;
        
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }
        
        vector<int>ans;
        int maxi=0;
        int prev=-1;
        
        for(int i=0;i<n;i++){
            
            maxi=max(maxi, m[s[i]]);
            
            if(maxi==i){
                ans.push_back(maxi - prev);
                prev=maxi;
            }
            
        }
        
        return ans;
        
        
    }
};