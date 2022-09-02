class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        
        for(int i=0; i<=n-3; i++){
           
             if(i==0 or (i>0 && nums[i]!=nums[i-1])){
                 
                int target = 0-nums[i];

                int j=i+1;
                int k=n-1;

                while(j<k){


                    vector<int>temp;

                    if(nums[j]+nums[k]==target){
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        ans.push_back(temp);

                        while(j<k && nums[j]==nums[j+1])  j++;
                        while(j<k && nums[k]==nums[k-1])  k--;
                        
                        j++;
                        k--;
                    }

                    else if(nums[j]+nums[k] > target){
                        k--;
                    }
                    else{
                        j++;
                    }   
                }
             }
             
        }
        
        
        
       return ans; 
        
    }
};