class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        
        map<int,int>m;
        
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        int ans=0;
        
        for(auto it:m){
            if(m[it.first - 1]>0 && m[it.first]>0){
                ans = max(ans, m[it.first - 1]+m[it.first]);
            }
        }
        return ans;
    }
};