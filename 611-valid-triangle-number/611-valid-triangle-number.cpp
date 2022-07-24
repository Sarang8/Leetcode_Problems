class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int ans=0;
        
        for(int i=n-1; i>=2; i--){
            
            int c=i;
            int b=c-1;
            int a=0;
            
            while(a<b){
                
                if(nums[a]+nums[b]>nums[c]){
                    ans+=(b-a);
                    b--;
                }
                else{
                    a++;
                }   
            }   
        }
        
        return ans; 
    }
};