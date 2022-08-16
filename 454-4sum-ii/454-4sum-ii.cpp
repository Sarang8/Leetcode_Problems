class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        
        unordered_map<int,int>m;
        int ans=0;
        
        for(auto it1:nums1){
            for(auto it2:nums2){
                m[it1+it2]++;
            }
        }
        
        
        for(auto it3:nums3){
            for(auto it4:nums4){
                if(m.find(0-it3-it4)!=m.end()){
                    ans += m[0-it3-it4]; 
                }
            }
        }
        
      return ans;  
        
    }
};