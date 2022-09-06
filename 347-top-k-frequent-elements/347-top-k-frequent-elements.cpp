class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>ans;
        if(n==1){
            return nums;
        }
        
        unordered_map<int, int>m;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        
        for(auto it:m){
            
            minHeap.push({it.second, it.first});
                
                if(minHeap.size()>k){
                    minHeap.pop();
                }
        }
        
        while(minHeap.size()>0){
              ans.push_back(minHeap.top().second);
                  minHeap.pop();   
        }
        
        
        return ans;
    }
};