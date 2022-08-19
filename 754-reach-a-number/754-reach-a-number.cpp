class Solution {
public:
    int reachNumber(int target) {
        
        target=abs(target);
        int sum=0;
        int step=0;
        
        while(sum<target){
            sum+=step;
            step++;
        }
        
        while( (sum-target)%2 ==1 ){
            sum+=step;
            step++;
        }
        
        return step-1;
    
    }
};