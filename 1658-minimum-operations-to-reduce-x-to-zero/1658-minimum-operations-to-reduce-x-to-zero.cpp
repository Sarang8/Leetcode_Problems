class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        int Totalsum=0;
        
        for(int i=0; i<n; i++){
            Totalsum=Totalsum+nums[i];
        }
        
        if(Totalsum == x) return n;
        int target = Totalsum-x;
        
        if(target<0)  return -1;
        
        
        int i=0;
        int currSum=0;
        int len=0;
        int j=0;
        
        while(j<n){
            
            currSum+=nums[j];
                
             while(currSum>target){
                    currSum-=nums[i];
                    i++;
                }
            
             if(currSum==target){
                len = max(len, j-i+1);
            }
                j++;
        }
        
        if(len==0) return -1;
        else return  n-len;  
    }
};