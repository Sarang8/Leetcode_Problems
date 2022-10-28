class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>>ans;
        int n=strs.size();
        if(n==0) return ans;
        
        unordered_map<string, vector<string>>m;
        
        for(int i=0; i<n; i++){
            
            string temp=strs[i];
            sort(temp.begin(), temp.end());
          
            m[temp].push_back(strs[i]); 
        }
        
        for(auto it:m){
            vector<string>temp;
            for(auto y : it.second){
                temp.push_back(y);
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};