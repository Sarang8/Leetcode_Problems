class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n=nums.size();
        vector<int>lesser;
        vector<int>greater;
        int cntOfEqual=0;
        
        for(int i=0; i<n; i++){
            if(nums[i]<pivot){
                lesser.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                greater.push_back(nums[i]);
            }
            else{
               cntOfEqual++; 
            }
        }
        
        while(cntOfEqual>0){
            lesser.push_back(pivot);
            cntOfEqual--;
        }
        
        for(int i=0; i<greater.size(); i++){
            lesser.push_back(greater[i]);
        }
        
        
       return lesser; 
        
        
    }
};