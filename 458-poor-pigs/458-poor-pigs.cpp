class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        
        int temp = (minutesToTest/minutesToDie) + 1;
        int pig=0;
        while( pow(temp, pig)  < buckets ){
            pig+=1;
        }
        
        
        return pig;
        
        
    }
};