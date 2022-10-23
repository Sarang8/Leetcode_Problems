class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        if(n%k !=0 ) return false;
        
        map<int,int>m;
        
        for(auto it:nums){
            m[it]++;
        }
        
        for(auto it=m.begin(); it!=m.end(); ){
            
            if(it->second > 0){
                for(int i=0;i<k;i++){
                    if(m[it->first + i] > 0){
                        m[it->first + i]--;
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                it++;
            }
        }
        
        
        return true;
        
        
        
    }
};