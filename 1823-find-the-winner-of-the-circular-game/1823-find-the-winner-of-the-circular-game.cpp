class Solution {
public:
    void solve(vector<int>v, int p, int idx, int &ans){
        
        if(v.size()==1){
            ans = (v[0]);
            return;
        }
        
        idx = (idx + p) % v.size();
        v.erase(v.begin()+idx);
        solve(v, p, idx, ans);
        
    }
    
    
    
    int findTheWinner(int n, int k) {
        
        vector<int>v;
        
        for(int i=1; i<=n; i++){
            v.push_back(i);
        }
        
        int p = k-1;   
        int ans = -1;
        int idx = 0;
        
        solve(v, p, idx,ans);
        return ans;
        
    }
};