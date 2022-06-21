class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>minHeap;
    int size;
    
    KthLargest(int k, vector<int>& nums) {
        
        int n = nums.size();
        size=k;
        
        for(int  i=0; i<n; i++){
            
            minHeap.push(nums[i]);
            
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        
        minHeap.push(val);
        while(minHeap.size()>size){
            minHeap.pop();
        }
        return minHeap.top();  
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */