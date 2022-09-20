class Solution {
public:
    void solve(int i, string s, string op, vector<string>&ans){
        
        if(i>=s.size()){
            ans.push_back(op);
            return;
        }
        
        if(isdigit(s[i])){
            string op3=op;
            op3.push_back((s[i]));
            solve(i+1, s, op3, ans);
        }
        
        else{
            
            string op1=op;
            op1.push_back(tolower(s[i]));
            solve(i+1, s, op1, ans);
            
            string op2=op;
            op2.push_back(toupper(s[i]));
            solve(i+1, s, op2, ans); 
        }
    }
    
    
    
    vector<string> letterCasePermutation(string s) {
        
        int n=s.size();
        
        vector<string>ans;
        string op="";
        solve(0, s, op, ans);
        return ans;
        
        
    }
};