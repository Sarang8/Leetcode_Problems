class Solution {
public:
    
    bool checkpalin(string temp){
        int i=0; 
        int j = temp.size()-1;
        
        while(i<=j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void remove(string s, string &temp){
        
        for(int i=0; i<s.size(); i++){
            if((s[i]>='a' && s[i]<='z') or (s[i]>='0' && s[i]<='9') ){
                temp.push_back(s[i]);
            }
        }
        cout<<temp;
    }
    
    
    bool isPalindrome(string s) {
        
        string temp = "";
        
        for(int i=0;i<s.size(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = tolower(s[i]);
            }
        }
        
        remove(s, temp);
        if(checkpalin(temp)){
            return true;
        }
        return false;
           
    }
};