class Solution {
public:
    void solve(int idx, vector<int>&nums, int t, int &ans){
        
        if(nums.size()==1){
            ans = nums[0];
            return;
        }
        
        idx = (idx+t)%nums.size();
        nums.erase(nums.begin()+idx);
        solve(idx, nums, t, ans);
    }
    
    int findTheWinner(int n, int k) {
        
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        
        int ans=-1;
        int t=k-1;
        int idx=0;
        solve(idx, nums, t, ans);
        
        return ans;
    }
};