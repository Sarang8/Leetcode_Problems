class Solution {
public:
    bool solve(string s, string t,int i, int j){
        
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        
        if(i==s.size()){
            return true;
        }
        return false;
        
    }
    
    bool isSubsequence(string s, string t) {
        
        return solve(s, t, 0,0);
        
    }
};