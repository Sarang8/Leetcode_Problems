class Solution {
public:
    string decodeString(string s) {
        
        int n=s.size();
        stack<char>st;
        
        for(int i=0; i<n; i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            
            else{
                string temp="";
                
                while(st.size()>0 && st.top()!='['){
                    temp = st.top()+temp;
                    st.pop();
                }
                
                st.pop();
                
                string num="";
                while(st.size()>0 && isdigit(st.top())){
                    num = st.top()+num;
                    st.pop();
                }
                
                int kTimes = stoi(num);
                
                while(kTimes>0){
                    for(int t=0;t<temp.size();t++){
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