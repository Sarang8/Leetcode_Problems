class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>ans(n,1);
        
        int prefix=1;
        int postfix=1;
        
        for(int i=1; i<n; i++){
            ans[i] = nums[i-1]*prefix;
            prefix = ans[i];
        }
        
        for(int i=n-2; i>=0; i--){
            ans[i] = ans[i]*nums[i+1]*postfix;
            postfix = nums[i+1]*postfix;
        }
        
        return ans;
        
    }
};