class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n==1){
            return "";
        }
        
        string ans="";
        string temp=palindrome;
        
        for(int i=0;i<n/2; i++){
            
            if(temp[i]!='a'){
                temp[i]='a';
                return temp;
            }
        }
        
        temp[n-1]='b'; //JUST TO HANDLE 'aaa' or 'aaaaaaa'
        return temp;
    }
};