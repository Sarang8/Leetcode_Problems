class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int>m;
        vector<int>ans;
        
        for(auto it:nums){
            m[it]++;
        }
        
        int j=-1;
        for(int i=1;i<=n;i++){
            if(m[i]==2){
                ans.push_back(i);
            }
            if(m[i]==0){
                j=i;
            }
        }
        ans.push_back(j);
        return ans;
    }
};