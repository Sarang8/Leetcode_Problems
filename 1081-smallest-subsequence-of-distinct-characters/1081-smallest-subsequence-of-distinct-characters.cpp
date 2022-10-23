class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }
        
        vector<bool>visi(26, false);
        stack<char>st;
        
        for(int i=0;i<n;i++){
            
            if(visi[s[i]-'a']) continue;
            
            while(!st.empty() && st.top()>s[i] && i<m[st.top()]){
                visi[st.top()-'a']=false;
                st.pop();
            }
            
            st.push(s[i]);
            visi[s[i]-'a']=true;
            
        }
        
        string ans = "";
        while (st.size() > 0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
        
        
    }
};