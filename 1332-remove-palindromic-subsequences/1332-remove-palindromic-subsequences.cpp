class Solution {
public:
    bool isPalin(string s){ 
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++; 
            j--;
        }
        return true;
    }
    
    //VERU EASY ...ANSWER BE ALWAYS 2 IF THAT IS NOT PALINDROME
    int removePalindromeSub(string s) {
        
        if(s.size()==0){
            return 0;
        }
        
        if(isPalin(s)){
            return 1;
        }
        return 2; 
    }
};