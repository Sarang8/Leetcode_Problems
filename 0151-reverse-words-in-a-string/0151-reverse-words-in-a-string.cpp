class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.size();
        int i=0;
       
        string ans="";
        
        while(i<n){
            
            
            while(i<n && s[i]==' '){
                i++;
            }
            
            if(i>=n) break;
            
            int j=i;
            string temp="";
            
            while(j<n && s[j]!=' '){
                temp+=s[j];
                j++;
            }
            
            i=j+1;
            
            
            if(ans.length()==0){
                ans = ans + temp;
            }
            else{
                ans = temp + ' ' + ans;
            }  
        }
        
        
        return ans;
        
    }
};