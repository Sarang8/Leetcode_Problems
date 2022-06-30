class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        int ans=0;
        sort(nums.begin(), nums.end());
        int sum=0;
        
        int low=0;
        int high=n-1;       
        int mid = (n)/2;
        int temp=nums[mid];
        
        for(int i=0; i<n; i++){
            nums[i]=abs(nums[i]-temp);
        }
        // for(int i=0; i<n; i++){
        //     cout<<nums[i]<<endl;
        // }
        for(int i=0; i<n; i++){
            ans+=nums[i];
        }
        return ans;
        
    }
};