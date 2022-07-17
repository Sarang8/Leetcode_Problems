class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int n=nums.size();
        
        int GCD=numsDivide[0];
        for(int i=1; i<numsDivide.size();i++){
            GCD = __gcd(GCD, numsDivide[i]);
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++){
            if(nums[i]>GCD) return -1;
            if(GCD%nums[i]==0) return i;
        }
        
        return -1;
        
//         int n=nums.size();
//         map<int,int>m;
//         int ans=0;
//         for(int i=0; i<n; i++){
//             m[nums[i]]++;
//         }
        
//         for(auto it:m){
            
//             int x=it.first;
//             int y=it.second;
            
//             int i;
//             for(i=0;i<numsDivide.size(); i++){
//                 if(numsDivide[i] % x !=0){
//                     ans+=y;
//                     break;
//                 }
//             }
//             if(i==numsDivide.size()) break;
//         }
//         if(ans==n) return -1;
//         return ans;
    }
};