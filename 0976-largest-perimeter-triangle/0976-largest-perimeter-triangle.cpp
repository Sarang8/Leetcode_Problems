class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int maxPer=0;
        
        for(int i=n-1;i>=2;i--){
            int j=i-1;
            int k=i-2;
            
            while(k>=0){
                int sum=nums[i]+nums[j]+nums[k];
                if(nums[k]+nums[j]>nums[i]){
                    maxPer = max(maxPer, sum);
                    break;
                    //cout<<maxPer<<endl;
                   // k++;
                }
                // else if(nums[k]+nums[j]<=nums[i]){
                //     k++;
                // }
                k--;
                
            }
        }
        
        return maxPer;
        
    }
};