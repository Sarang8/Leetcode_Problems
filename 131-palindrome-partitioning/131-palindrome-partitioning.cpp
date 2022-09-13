class Solution {
public:
    bool isPal(string &s, int low, int high){
        
        while(low<=high){
            if(s[low]!=s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
        
    }
    
    
    void solve(int ind, string s, vector<string>&ds, vector<vector<string>>&ans){
        
        if(ind>=s.size()){
            ans.push_back(ds);
            return;
        }
        
        
        for(int i=ind;i<s.size();i++){
            if(isPal(s, ind, i)){
                ds.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
        
        
    }
    
    
    vector<vector<string>> partition(string s) {
        
        int n=s.size();
        vector<string>ds;
        vector<vector<string>>ans;
        solve(0, s, ds, ans);
        return ans;   
    }
};