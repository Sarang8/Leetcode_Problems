#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>ans;
        int n=nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            
            for(int j=i+1; j<n; j++){
                
                long long temp = nums[i]+nums[j];
                long long newTar = target - temp;
                
                int c=j+1;
                int d=n-1;
                
                while(c<d){
                    int sum=nums[c]+nums[d];
                    
                    
                    if(sum==newTar){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[c]);
                        temp.push_back(nums[d]);
                        ans.push_back(temp);
                       // cout<<i<<j<<c<<d<<endl;
                        
                        while(c<d && nums[c]==nums[c+1]) c++;
                        while(c<d && nums[d]==nums[d-1]) d--;
                        
                        c++;
                        d--;
                    }
                    else if(sum>newTar){
                        d--;
                    }
                    else{
                        c++;
                    }  
                }
            while(j+1<n && nums[j+1]==nums[j]){
                j++;
            }

            while(i+1<n && nums[i+1]==nums[i]){
                i++;
            }
            }
        }
        
      return ans;  
        
    }
};