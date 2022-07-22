class Solution {
public:
    string removeKdigits(string num, int k) {
        
       if(k>=num.size())
            return "0";
        stack<char>st;
        int n = num.size();
        st.push(num[0]);
        for(int i = 1;i<n;i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                k--;
                st.pop();
            }
            if(st.empty() && num[i]=='0')
                continue;
            
            st.push(num[i]);
        }
        while(!st.empty()&& k--){
            st.pop();
        }
        if(st.empty())
            return "0";
        string ans ="";
        while(st.size()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};