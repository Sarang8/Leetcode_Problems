class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.size();
        int i=0,j;
        string ans="";
        
        while(i<n){
            
            j=i;
            string temp="";
            while(j<n && s[j]!=' '){
                j++;
            }
            
            temp = s.substr(i, j-i);
            reverse(temp.begin(), temp.end());
            
            if(ans.size()==0){
                ans += temp;
            }
            else{
                ans = ans + " "+ temp;
            }
            
            
            
            i=j+1;
        }
        
        
        
        return ans;
    }
};