class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int>mp;
        
        int prefixSum=0;
        
        for(int i=0;i<n;i++){
            
            prefixSum += nums[i];
            prefixSum %= k;
            
            //here as 0 is also a multiple of k we check whether sum becomes zero for more than i=0.
            if(prefixSum == 0 && i) return true;  //BASE CASE CONDITION KIND OF
            
            if(mp.find(prefixSum)!=mp.end()){
                 if(i - mp[prefixSum] > 1){
                     return true;
                 }
            }
            else{
                mp[prefixSum]=i;   
            }
            
        }
        
        
        return false;
        
    }
};