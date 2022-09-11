class Solution {
public:
    bool checkValidString(string s) {
        
        
        //GREEDY BASED Solution
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
    
    //Recursive dp
    
//     public boolean checkValidString(String s) {
//         return checkValidString(s, 0, 0);
//     }

//     private boolean checkValidString(String s, int index, int open) {
//         if (index == s.length()) {
//             return open == 0;
//         }
//         if (s.charAt(index) == '(') {
//             return checkValidString(s, index + 1, open + 1);
//         } else if (s.charAt(index) == ')') {
//             return open != 0 && checkValidString(s, index + 1, open - 1);
//         } else {
//             return checkValidString(s, index + 1, open)
//                     || checkValidString(s, index + 1, open + 1)
//                     || open != 0 && checkValidString(s, index + 1, open - 1);
//         }
//     }
    
    
    
    
    
};