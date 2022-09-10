class Solution {
public:
    vector<int>NSR(vector<int>&h){
        int n=h.size();
        stack<pair<int,int>>st;
        vector<int>ans;
        
        for(int i=n-1;i>=0;i--){
            
            if(st.empty()){
                ans.push_back(n);
            }
            else if(!st.empty() && st.top().first<h[i]){
                ans.push_back(st.top().second);
            }
            
            else if(!st.empty() && st.top().first>=h[i]){
                while(!st.empty() && st.top().first>=h[i]){
                    st.pop();
                }
                
                if(st.size()==0){
                    ans.push_back(n);
                }
                else{
                    ans.push_back(st.top().second);
                }
            }
            st.push({h[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    
    
    
    
    
    vector<int>NSL(vector<int>&h){
        int n=h.size();
        stack<pair<int,int>>st;
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            
            if(st.empty()){
                ans.push_back(-1);
            }
            else if(!st.empty() && st.top().first<h[i]){
                ans.push_back(st.top().second);
            }
            
            else if(!st.empty() && st.top().first>=h[i]){
                while(!st.empty() && st.top().first>=h[i]){
                    st.pop();
                }
                
                if(st.size()==0){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(st.top().second);
                }
            }
            st.push({h[i], i});
        }
       
        return ans;
    }
    
    
    
    
    
    
    
    
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        
        vector<int>nsrInd = NSR(heights);
        vector<int>nslInd = NSL(heights);
        
        
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            int width = nsrInd[i] - nslInd[i] - 1;
            ans = max(ans, width*heights[i]);
            
        }
        
        
        return ans;
        
    }
};