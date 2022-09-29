class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++){
            
            pq.push({abs(x-arr[i]), arr[i]});
            
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        
        vector<int>ans;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};