class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U' ){
            return true;
        }
        return false;
    }
    
    string reverseVowels(string str) {
        
        int n=str.size();
        int s=0;
        int e=n-1;
        
        while(s<e){
            
            while(s<e && !isVowel(str[s])) s++;
            
            while(s<e && !isVowel(str[e])) e--;
            
            swap(str[s], str[e]);
            s++;
            e--;
        }
        
        return str;
        
        
    }
};