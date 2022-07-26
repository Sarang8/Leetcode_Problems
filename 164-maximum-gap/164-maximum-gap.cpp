class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n=nums.size();
        if(n<2) return 0;
        
        int mini=INT_MAX;
        int maxi=0;
        for(int i=0; i<n; i++){
            mini=min(mini, nums[i]);
            maxi=max(maxi, nums[i]);
        }
        
        //take the ceil of division
        int  interval = ceil(float((maxi-mini))/(n-1));
        //cout<<interval;
        
        vector<int>bucketMin(n-1, INT_MAX);
        vector<int>bucketMax(n-1, -1);
        
        for(int i=0; i<n; i++){
            
            if(nums[i]==mini or nums[i]==maxi) continue;
            
            //MAGIC FORMULA
            int index = (nums[i]- mini)/interval;
            bucketMin[index] = min(bucketMin[index], nums[i]);
            bucketMax[index] = max(bucketMax[index], nums[i]);
            
        }
        
        int prev=mini; 
        int maxGap=0;
        for(int i=0; i<bucketMin.size(); i++){
            
            if(bucketMax[i]==-1) continue;
            maxGap=max(maxGap, bucketMin[i]-prev);
            prev=bucketMax[i];    
        }
        
        
        maxGap=max(maxGap, maxi-prev);
        
        return maxGap;
        
        
        
    }
};