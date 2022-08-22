class Solution {
public:
    bool isPowerOfFour(int n) {
       
        long long temp=4;
        
        if(n==1) return true;
        
        while(temp<=n){
            
            if(temp==n){
                return true;
            }
            temp*=4;
        }
        
        return false;
    }
};