class Solution {
public:
    int res=0;
    
    bool check(string s){
        vector<int>cnt(26, 0);
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(cnt[i]>1){
                return false;
            }
        }
        return true;
    }
    
    
    void solve(int ind, string op, vector<string>&arr){
        
        if(check(op)==false){
            return;
        }
        int b=op.size();
        res = max(res, b);
        string temp = op;
        
        if(ind>=arr.size()){
            return;
        }
        
        
        solve(ind+1, op+arr[ind], arr);
        solve(ind+1, op, arr);
        
        
        
        
        
//         for(int i=ind;i<arr.size();i++){
//             temp += arr[i];
//             if(check(temp)){
//                 int t=temp.size();
//                 res = max(res, t);
//                 solve(i+1, temp,  arr);
                
//             }
//             else{
//                 res=max(res, b);
//                 solve(i+1, op, arr);
//             }
//             temp.pop_back();
//         }
        

        
    }
    
    int maxLength(vector<string>& arr) {
        
        int n=arr.size();
        string op="";
        solve(0, op, arr);
        
        return res;
    }
};