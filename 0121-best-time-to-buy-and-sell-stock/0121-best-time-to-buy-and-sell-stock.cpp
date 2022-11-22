class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        int maxiP=0;
        int mini=prices[0];
        
        for(int i=1;i<n;i++){
            
            maxiP=max(maxiP, prices[i]-mini);
            mini=min(mini, prices[i]);
        }
        return maxiP;
    }
};