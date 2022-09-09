class Solution {
public:
    bool static compr(vector<int>&a, vector<int>&b){
        
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        
        return a[0]<b[0];
        
    }
    
    
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        
        int n=p.size();
        sort(p.begin(), p.end(), compr);
        int ans=0;
        int MaxTillNow=INT_MIN;
        
        for(int i=n-1; i>=0; i--){
            
            if(p[i][1] < MaxTillNow){
                ans++;
            }
            
            MaxTillNow = max(MaxTillNow, p[i][1]);   
        }
        
     
        
        return ans;
    }
};