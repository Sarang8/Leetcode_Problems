class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 1;
        long long high = n;
     
        while(low<=high){
            
            long long mid = low + (high-low)/2;
            
            long long temp = mid*(mid+1)/2;
            
            if(temp==n)  return mid;
            
            else if(temp>n)  high = mid-1;
            
            else if(temp<n) {
                low= mid+1;  
            } 
            
        }
        return low-1;
        
    }
};