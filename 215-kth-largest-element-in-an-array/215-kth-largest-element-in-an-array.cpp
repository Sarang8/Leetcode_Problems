class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans; 
        priority_queue<int, vector<int>, greater<int>>minheap;
        
        for(int i=0; i<nums.size(); i++){
            
            minheap.push(nums[i]);
            
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        
        
        return minheap.top();
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         priority_queue<int ,vector<int>, greater<int>>minH;
        
//         for(int i=0; i<nums.size(); i++){
            
//             minH.push(nums[i]);
            
//             if(minH.size()>k){
//                 minH.pop();
//             }
//         }
        
//         ans = minH.top();
//         return ans;
     }
};