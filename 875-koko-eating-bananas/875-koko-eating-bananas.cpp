#define ll long long
class Solution {
public:
    
    bool canEatInHhour(vector<int>&piles, int h, ll mid){
        
        ll totalHr = 0;
        int n=piles.size();
        
        for(int i=0;i<n;i++){
            ll temp = piles[i]/mid;
            if(piles[i]%mid==0){
                totalHr+=temp;
            }
            else{
                totalHr+=temp+1;
            }
        }
        
        if(totalHr<=h){
            return true;
        }
        return false;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n=piles.size();
        
        // if(n==1){
        //     return 1;
        // }
        
        ll low=1;
        ll high=*max_element(piles.begin(), piles.end());
        
        //cout<<low<<" "<<high;
        ll ans=0;
        
        while(low<=high){
            
            ll mid = low+(high-low)/2;
            
            if(canEatInHhour(piles, h, mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        
        
        
        return ans;
        
    }
};