class Solution {
public:
    string decodeString(string s) {
        
        int n=s.size();
        stack<char>st;
        
        for(int i=0; i<n; i++){
            
            if(s[i] != ']'){
                st.push(s[i]);
            }
            
            else{
                string temp="";
                while(st.top()!='['){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                
                string num = "";
                while(st.size()>0 && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }
                
                int kTimes = stoi(num);
                //string temp2=""
                while(kTimes){
                    for(int t=0; t<temp.size(); t++){
                        st.push(temp[t]);
                    }
                    kTimes--;
                }  
            }  
        }
        
        string ans="";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};