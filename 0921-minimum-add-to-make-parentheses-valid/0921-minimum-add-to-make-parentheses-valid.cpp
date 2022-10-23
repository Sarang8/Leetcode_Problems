class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int n=s.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                
                if(st.empty()){
                    ans++;
                }
                
                else if(st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                } 
            }   
        }
        
        return st.size()+ans;
    }
};