class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n==1) return true;
        
        long long temp=3;
        while(temp<=n){
            if(temp==n){
                return true;
            }
            temp*=3;
        }
        return false;
    }
};