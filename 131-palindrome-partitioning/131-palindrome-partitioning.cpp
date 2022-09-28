class Solution {
public:
    bool isPal(string &s){
        int low=0;
        int high=s.size()-1;
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
        
        string temp="";
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(isPal(temp)){
                ds.push_back(temp);
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