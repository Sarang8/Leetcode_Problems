class Solution {
public:
    bool checkValidString(string s) {
        
        int leftMax=0;
        int leftMin=0;
        
        for(int i=0;i<s.size(); i++){
            
            if(s[i]=='('){
                leftMax++;
                leftMin++;
            }
            else if(s[i]==')'){
                leftMax--;
                leftMin--;
            }
            
            else if(s[i]=='*'){
                //2 options
                leftMax++;  //considering open paranthesis
                leftMin--;  //considering closed paranthesis
            }
            
            if(leftMax<0){
                return false;
            }
            
            if(leftMin<0){
                leftMin=0;
            }
            
            
        }
        
        return leftMin==0;
        
    }
};