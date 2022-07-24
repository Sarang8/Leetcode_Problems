class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n=nums.size();
        sort(nums.begin(), nums.end());
        
        int closest=nums[0]+nums[1]+nums[2];
        //int closest=abs(target-currSum);
        
        for(int i=0; i<=n-3; i++){
            
            int first=i;
            
            if(i>0 && nums[first]==nums[first-1]) continue;
            
            int second=i+1;
            int third=n-1;
            
            while(second<third){
                int currSum=nums[first]+nums[second]+nums[third];
                
                if(currSum==target){
                    return currSum;
                }
                
                if(abs(closest-target)>abs(currSum-target)){
                    closest=currSum;
                }
               
                
                if(currSum>target){
                    third--;
                }
                else if(currSum<target){
                    second++;
                }
            }   
        }
        return closest;
        
    }
};