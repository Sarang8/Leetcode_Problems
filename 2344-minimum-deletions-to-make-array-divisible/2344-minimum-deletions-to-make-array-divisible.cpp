class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int n=nums.size();
        map<int,int>m;
        int ans=0;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        
        for(auto it:m){
            
            int x=it.first;
            int y=it.second;
            
            int i;
            for(i=0;i<numsDivide.size(); i++){
                if(numsDivide[i] % x !=0){
                    ans+=y;
                    break;
                }
            }
            if(i==numsDivide.size()) break;
            
        }
        if(ans==n) return -1;
        return ans;
    }
};