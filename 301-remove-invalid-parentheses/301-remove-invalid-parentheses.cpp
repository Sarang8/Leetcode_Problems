class Solution {
public:
    
    int getInv(string s){
        
        stack<char>st;
        
        for(int i=0; i<s.size(); i++){
            
            if(s[i]=='('){
                st.push(s[i]);
            }
            
            else if(s[i]==')'){
                
                if(st.size()>0 && st.top()=='('){
                    st.pop();
                }
                else{
                   st.push(s[i]);
                }
            }  
        }
        return st.size();
    }
    
    void solve(string s, int Invcnt, vector<string>&ans, unordered_map<string, bool>&m){
        
        if(m[s]==true){
            return;
        }
        else{
            m[s]=true;
        }
        
        
        if(Invcnt<0) return;
        
        if(Invcnt==0){  
            int n = getInv(s);
            if(n==0){
                ans.push_back(s);
                return;
            }  
        }
        
        for(int i=0; i<s.length(); i++){
            
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            string temp = left+right;
            solve(temp, Invcnt-1,ans,m); 
        }  
    }
    
    
    
    
    
    
    vector<string> removeInvalidParentheses(string s) {
        
        int Invcnt = getInv(s);
        vector<string>ans;
        unordered_map<string, bool>m;
        solve(s, Invcnt, ans, m);
        return ans;
        
        
        
        
        
    }
};