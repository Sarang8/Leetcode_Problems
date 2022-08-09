class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int res = INT_MIN;
//         int currProd = 1;
        
//         for(int i=0; i<n; i++){ 
//             currProd*=nums[i];
//             res = max(res, currProd);  
//             if(currProd==0){
//                 currProd=1;
//             } 
//         }
        
// //WE AE DOING HERE 2 PASSES FOR UNDERSTANDING.....
// //THIS IS FOR IF ARRAY CONTAIS 0 THEN WE WILL FIND LEFT PART MAX OF 0 ANS RIGHT PART MAX OF 0....
// //THIS CAN BE DONE IN SIGLR PASS AS WELL

//          currProd=1;
//          for(int i=n-1; i>=0; i--){ 
//             currProd*=nums[i];
//             res = max(res, currProd);  
//             if(currProd==0){
//                 currProd=1;
//             } 
//         }
        
//         //  
        
        //SOLUTION USING ONE SINGLE PASS
        int left=1, right=1;
        for(int i=0; i<n;i++){
            
            left*=nums[i];
            right*=nums[n-1-i];
            res = max(res, max(left, right));
            
            if(left==0) left=1;
            if(right==0) right=1;   
        }
        
        
        
        
                
        return res;
    }
};