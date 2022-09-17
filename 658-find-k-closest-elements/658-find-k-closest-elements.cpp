class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>>MaxHeap;
        vector<int>ans;
        int n= arr.size();
        
        for(int i=0; i<n; i++){ 
            MaxHeap.push({abs(arr[i]-x), arr[i]});
            
            if(MaxHeap.size()>k){
                MaxHeap.pop();
            } 
        } 
        
        while(MaxHeap.size()>0){  
            ans.push_back(MaxHeap.top().second);
            MaxHeap.pop();        
        }
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};