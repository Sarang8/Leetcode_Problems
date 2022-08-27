class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int size = s.size();
        
        if(size==1 or size==0){
            return size;
        }
        
        
        unordered_map<char, int>m;
        int i=0;
        int j=0;
        int maxi=INT_MIN;
        
        while(j<size){
            
            m[s[j]]++;
            
            if(m.size()<(j-i+1)){
                while(m.size()<(j-i+1)){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
            
            else if(m.size()==(j-i+1)){
                maxi = max(maxi, (j-i+1));
                j++;  
            }
        }
        return maxi;
        
        
//         if(s.size()==0){
//             return 0;
//         }  
//         int size = s.size();
//         int i=0;
//         int j =0;
//         unordered_map<char,int>mp;
//         int mx = INT_MIN;
        
//         while(j<size){
            
//             mp[s[j]]++;
            
//             if(mp.size() < (j-i+1)){  
//                 while(mp.size() < (j-i+1)){
//                     mp[s[i]]--;
//                     if(mp[s[i]]==0){
//                         mp.erase(s[i]);
//                     }
//                     i++;
//                 }
//                 j++;
//             }
            
//             else if(mp.size()==(j-i+1)){
//                 mx = max(mx, (j-i+1));
//                 j++;
//             }
//         }
//         return mx;
        
          
//         vector<int>m(256,-1);
//         int len=0;
//         int left=0;
//         int right = 0;
//         int n =s.size();
        
//        while(right<n){
           
//            if(m[s[right]] != -1){
//                left = max(left, m[s[right]]+1);
//            }
           
//            m[s[right]] = right; 
           
//            len = max(len, right-left+1);
//            right++;
//        }
//         return len;
        
        
    }
};