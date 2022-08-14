class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>st;
        int n=tokens.size();
        
        //ONLY PROBLEM CAN COME WHEN '-' && '/' SIGN COME BECAUSE YOU HAVE TO TAKE CARE OF B-A ANS B/A
        
        for(int i=0; i<n; i++){
            string ch=tokens[i];
            
            if(tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="/"){
                
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int temp=0;
                
                if(tokens[i]=="+"){
                    temp = b+a;
                }
                else if(tokens[i]=="-"){
                    temp=b-a;             //CAREFULLY LOOK THAT IT WILL BE B-A 
                }
                else if(tokens[i]=="*"){
                    temp=b*a;
                }
                else if(tokens[i]=="/"){
                    temp=b/a;          //CAREFULLY LOOK THAT IT WILL BE B/A
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