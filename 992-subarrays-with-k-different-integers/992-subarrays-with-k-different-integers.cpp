class Solution {
public:
    int SubArrWithAtmostB(vector<int>& nums, int B){
        
        int n=nums.size();
        unordered_map<int,int>m;
        
        int i=0;
        int j=0;
        int cnt=0;
        
        while(j<n){
            
            m[nums[j]]++;
            
            if(m.size()>B){
                while(m.size()>B){
                    m[nums[i]]--;
                    if(m[nums[i]]==0){
                        m.erase(nums[i]);
                    }
                    i++;
                }
            }
            
            cnt+=(j-i+1);
            j++;
        }
        //cout<<cnt<<endl;
        return cnt;
    }
    
    
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int ans = SubArrWithAtmostB(nums, k) - SubArrWithAtmostB(nums, k-1);
        
        
        return ans;
        
    }
};