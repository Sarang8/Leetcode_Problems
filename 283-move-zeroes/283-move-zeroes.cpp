class Solution {
public:
    void moveZeroes(vector<int>& nums) {
//    int ind = 0;
//    for(int i=0; i<nums.size(); i++){
//        if(nums[i]!=0){
//            swap(nums[i], nums[ind]);
//            ind++;
//        }
       
//    }
//    return;
        
        int n=nums.size();
        int i=0; int j=0;
        
        while(j<n){
            
            if(nums[j]!=0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else{
                j++;
            }
        }
    
        return;
    
        
    }
};