class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int>m;
        int sum=0;
        int ans=0;
        m[sum]=1;
            
            
            
        for(int i=0; i<n; i++){  
            sum+=nums[i];
            int target = sum-k;
            
            if(m.find(target)!=m.end()){
                ans+=m[target];
            }
            
            m[sum]++;   
        }
        return ans;
             
        
//IF THERE ARE ONLY POSITIVE NO.
        // int i=0; 
        // int j=0;
        // int sum=0;
        // int ans=0;
//         while(j<n){
            
//             sum+=nums[j]; 
            
//             if(sum==k){
//                 ans+=1;
//                 j++;
//             }
            
//             else if(sum>k){
//                 while(sum>k){
//                     sum-=nums[i];
//                     if(sum==k) ans+=1;
//                     i++;
//                 }
//                 j++;
                
//             }
//             else if(sum<k){
//                 j++; 
//             }    
//         }  
        
//      return ans; 
        
    }
};