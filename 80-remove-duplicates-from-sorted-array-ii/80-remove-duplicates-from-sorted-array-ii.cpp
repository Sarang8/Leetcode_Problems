class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        
        int p=0;
        
        for(int i=0; i<n; i++){
            
            if(p<2 or nums[i] > nums[p-2] ){
                nums[p]=nums[i];
                p++;
            } 
        }
        return p;
        
        
        
        
//         int i=0; 
//         int j=0;
//         int ele=nums[0];
//         int cnt=0;
//         int ans=0;
        
//         while(j<n){
            
//             if(nums[j]==ele && cnt<2){
//                 cnt++;
//                 j++;
//                 ans++;
//             }
//             else if(nums[j]==ele && cnt>=2){
//                 while(nums[j]==ele){
//                     j++;
//                 }
//                 i=j;
//                 ele=nums[j];
//                 cnt=0;
//             }
//             else if(nums[j]!=ele){
//                 i=j;
//                 ele=nums[j];
//                 cnt=0;
//             }
//         }
        
//         return ans;
    }
};