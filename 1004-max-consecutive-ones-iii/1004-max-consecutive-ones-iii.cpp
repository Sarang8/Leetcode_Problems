class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     
        int n=nums.size();
        int Zerocnt=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                Zerocnt++;
            }
        }
        if(Zerocnt<=k) return n;
        
        int i=0;
        int j=0;
        int ans=0;
        int ZeroCnt=0;
        
        while(j<n){
            
            if(nums[j]==0){
                ZeroCnt++;
            }
            
            if(ZeroCnt<=k && j<n){
                ans=max(ans, j-i+1);
                j++;
            }
            
            if(ZeroCnt>k){
                while(ZeroCnt>k){
                    if(nums[i]==0){
                        ZeroCnt--;
                    }
                    i++;
                }
                j++;
            }
            
        }

        
        return ans;
        
    }
};