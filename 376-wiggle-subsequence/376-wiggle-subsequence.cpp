class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1){
            return n;
        }
        int CurrDiff;
        int diff = nums[1]-nums[0];
        int ans = 0;
        
        if(diff!=0){
            ans=2;
        }
        else{
            ans=1;
        }
        
        for(int i=1; i<n-1; i++){
            
            CurrDiff = nums[i+1]-nums[i];
            
            if((diff>=0 && CurrDiff<0)  or  (diff<=0 && CurrDiff>0)){
                
                diff= CurrDiff;
                ans++;    
            }  
        }
        
        
        return ans;
        
    }
};