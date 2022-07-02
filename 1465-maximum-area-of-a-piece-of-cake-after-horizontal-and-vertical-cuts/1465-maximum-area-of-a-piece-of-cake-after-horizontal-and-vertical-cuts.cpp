class Solution {
public:
    int mod = 1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        long long ans=0;
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        verticalCuts.push_back(w);
        verticalCuts.push_back(0);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        vector<long long>height(horizontalCuts.size(),0);
        vector<long long>width(verticalCuts.size(),0);
       
        long long maxH=0;
        for(int i=0; i<horizontalCuts.size()-1; i++){
            height[i]=(horizontalCuts[i+1]%mod-horizontalCuts[i]%mod)%mod;
            maxH = max(maxH , height[i]);
            //cout<<maxH;
            
        }
        
        long long maxW=0;
        for(int i=0; i<verticalCuts.size()-1; i++){
            width[i]=(verticalCuts[i+1]%mod-verticalCuts[i]%mod)%mod;
            maxW = max(maxW , width[i]);
            //cout<<maxW;
        }
        
        ans=(maxH*maxW)%mod;
        return ans;   
    }
};