class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }
        //Now question converted to subarray with sum k
        
        unordered_map<int, int>m;
        m[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0; i<n; i++){
            
            sum+=nums[i];
            
            if(m.find(sum-k)!=m.end()){
                ans+=m[sum-k];
            }
            
            m[sum]++;

        }
        
        
        
        
      return ans;  
        
    }
};