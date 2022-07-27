class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        int N=2*n;
        vector<int>temp(N,0);
        
        for(int i=0; i<2*n; i++){
            temp[i] = nums[i%n];
        }
        
        stack<int>st;
        vector<int>res;
        
        for(int i=N-1; i>=0; i--){
            
            if(st.size()==0){
                res.push_back(-1);
            }
            
            else if(st.size()>0 && st.top()>temp[i]){
                res.push_back(st.top());
            }
            
            else if(st.size()>0 && st.top()<=temp[i]){
                
                while(st.size()>0 && st.top()<=temp[i]){
                    st.pop();
                }
                
                if(st.size()==0){
                    res.push_back(-1);
                }
                else{
                    res.push_back(st.top());
                }
                
            }
            st.push(temp[i]);   
        }
          
        vector<int>ans;
        for(int i=N-1; i>=N/2; i--){
            ans.push_back(res[i]);
        }
        
        return ans;
    }
};