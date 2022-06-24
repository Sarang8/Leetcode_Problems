class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
//         unordered_map<int,int>m;
//         vector<int>ans;
//         set<int>s;
        
//         for(int i=0; i<nums1.size(); i++){
//             m[nums1[i]]++;
//         }
        
//         for(int i=0; i<nums2.size(); i++){
//             if(m.find(nums2[i])!=m.end()){
//                 s.insert(nums2[i]);
//                 //ans.push_back(nums2[i]);
//             }
//         }
        
//         for(auto it:s){
//             ans.push_back(it);
//         }
        
//         return ans;
        
        unordered_set<int>s;
        vector<int>ans;
        
        for(int i=0; i<nums1.size(); i++){
            s.insert(nums1[i]);
        }
        
        for(int i=0; i<nums2.size(); i++){
            if(s.count(nums2[i])){
                ans.push_back(nums2[i]);
                s.erase(nums2[i]);
            }   
        }
        
        return ans;
    }
};