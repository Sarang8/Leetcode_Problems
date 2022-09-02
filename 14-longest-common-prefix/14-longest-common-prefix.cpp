#include <string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans="";
        int n = strs.size();
        
        //IT WILL SORT VECTOR AS ["flight","flow","flower"]***********
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[n-1];
        
        for(int i=0; i<first.size(); i++){
            
            if(first[i]==last[i]){
                ans = ans+first[i];
            }
            else{
                break;
            }
            
        }
        
        
        return ans;
        
        
        
    }
};