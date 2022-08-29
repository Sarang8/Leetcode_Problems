class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n=s.size();
        
        if(n==0 or k>n){
            return 0;
        }
        
        unordered_map<char,int>m;
        
        for(auto it:s){
            m[it]++;
        }
        
        int sub1, sub2;
        for(int i=0; i<n; i++){
            
            if(m[s[i]] < k){
                sub1 = longestSubstring(s.substr(0,i), k);
                sub2 = longestSubstring(s.substr(i+1),k);
                break;
            }
            
            if(i==n-1){
                return n;
            }
        }
        
        return max(sub1, sub2);
    }
};