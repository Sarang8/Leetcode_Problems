class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int n=tokens.size();
        stack<int>st;
        
        for(int i=0; i<n; i++){
            
            if(tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="/" or tokens[i]=="*"){
                
                int temp=0;
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                
                
                if(tokens[i]=="+"){
                    temp=b+a;
                }
                else if(tokens[i]=="-"){
                    temp=b-a;
                }
                else if(tokens[i]=="*"){
                    temp=b*a;
                }
                else if(tokens[i]=="/"){
                    temp=b/a;
                }
                st.push(temp);
            }
            
            else{
                st.push(stoi(tokens[i]));                
            }
           
        }
        return st.top();    
    }
};