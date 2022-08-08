class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int j = 0;
        for(int i=m; i<nums1.size(); i++){
            nums1[i] = nums2[j];
            j++;
        }
        
        int gap = (m+n+1)/2;
        
        while(gap>0){
            int i=0;
            int j = gap;
            
            while(j<nums1.size()){
                if(nums1[i]>nums1[j]){
                    swap(nums1[i], nums1[j]);
                }
                i++; 
                j++;
            }
            
            
            if(gap<=1){
                break;
            }
            else{
                gap = (gap+1)/2;
            }   
        }   
        
        
//         int j=0;
//         for(int i=m; i<nums1.size(); i++){
//             nums1[i] = nums2[j];
//             j++;
//         }
        
//         int gap = (m+n+1) / 2;
        
//         while(gap>0)
//         {
//             int i = 0;
//             int j=gap;
            
//                 while(j<m+n){

//                     if(nums1[i]>nums1[j]){
//                         swap(nums1[i], nums1[j]);
//                     }
//                     i++;
//                     j++;  
//                 }

//                 if(gap==1){
//                     gap = 0;
//                 }
//                 else{
//                     gap = (gap+1) / 2;
//                 }
//           }        
        
        
        
 
//         int i=m-1,j=n-1,k=m+n-1;
//         while(i>=0 && j>=0)
//         {
//             if(nums1[i]>nums2[j])
//             {
//                 nums1[k]=nums1[i];
//                 k--;
//                 i--;
//             }
//             else
//             {
//                 nums1[k]=nums2[j];
//                 k--;
//                 j--;
//             }
//         }
//         while(j>=0)
//         {
//             nums1[k]=nums2[j];
//             k--;
//             j--;
//         }
              
            
        
      
    }
};