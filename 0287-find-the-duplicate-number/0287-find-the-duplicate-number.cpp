class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        
        int slow=nums[0];
        int fast=nums[0];
        
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        int temp=nums[0];
        while(temp!=fast){
            temp=nums[temp];
            fast=nums[fast];
        }
        
        return temp;
    }
};