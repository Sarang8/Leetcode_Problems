class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        vector<int>ans;
        int n=changed.size();
        if(n&1){
            return ans;
        }
        
        sort(changed.begin(), changed.end());
        
        unordered_map<int,int>mp;
        for(auto it:changed){
            mp[it]++;
        }
        
        for(int i=0;i<n;i++){
            
            if(mp.find(2*changed[i])!=mp.end() && mp[changed[i]]!=0 && mp[2*changed[i]]!=0){
                
                mp[changed[i]]--;
                mp[2*changed[i]]--;
                ans.push_back(changed[i]);
            }
        }
        
        for(auto it:mp){
            if(it.second!=0){
                return {};
            }
        }
        
        
       return ans; 
        
        
    }
};