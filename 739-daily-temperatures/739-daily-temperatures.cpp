class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int>ans;
        stack<pair<int, int>>st;
        int n=temperatures.size();
        
        for(int i=n-1; i>=0; i--){
            
            if(st.empty()){
                ans.push_back(0);
            }
            
            else if(!st.empty() && st.top().first>temperatures[i]){
                st.push({st.top().first, st.top().second});
                ans.push_back(st.top().second);
            }
            
            else if(!st.empty() && st.top().first<=temperatures[i]){
                
                while(!st.empty() && st.top().first<=temperatures[i]){
                    st.pop();
                }
                
                if(st.size()==0){
                     ans.push_back(0);
                }
                else{
                     ans.push_back(st.top().second);
                }
                
            }
            
            st.push({temperatures[i], i});
        }
        
        reverse(ans.begin(), ans.end());
        vector<int>res;
        for(int i=0;i<n;i++){
            if(ans[i]!=0){
                res.push_back(ans[i]-i);
            }
            else{
                res.push_back(0);
            }
        }
        
        return res;
        
    }
};