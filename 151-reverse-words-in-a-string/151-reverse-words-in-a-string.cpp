class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.size();
        string ans="";
        
        int i=0;
        
        while(i<n){
            
            while(i<n && s[i]==' '){
                i++;
            }
            if(i>=n) break;
            
            int j=i;
            
            string temp="";
            while(j<n && s[j]!=' '){
                temp += s[j];
                j++;
            }
            
            if(ans.size()==0){
                ans = temp;
            }
            else{
                ans = temp + ' ' + ans;
            }
            
            i=j+1;
        }
        
        
        
        return ans;
        
        
        
    }
};