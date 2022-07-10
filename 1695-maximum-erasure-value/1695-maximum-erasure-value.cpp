class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int, int>mp;        
        int n=nums.size();
        int i=0;
        int j=0;
        int sum = 0;
        int ans=INT_MIN;
        
        
        while(j<n){
            
            mp[nums[j]]++;
            sum+=nums[j];
            
            if(mp.size()<(j-i+1)){
                while(mp.size()<(j-i+1)){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    } 
                    sum-=nums[i]; 
                    i++;
                }
            }
            ans = max(ans, sum);
            j++;
        }
        
        return ans;        
    }
};