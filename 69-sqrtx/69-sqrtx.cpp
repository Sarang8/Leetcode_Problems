class Solution {
public:
    int mySqrt(int x) {
        
        long long s = 0;
        long long e = x;
        long long ans =0;
        if(x==0){
            return 0;
        }
        
        while(s<=e){
            
            long long m = s + (e-s)/2;
        
            if(m*m == x){
                return m;
            }
            
            else if(m*m<x){
                 s = m+1;
                ans = m;
            }
            else{
                e = m-1;  
            }
        }
        return ans;
    }
};