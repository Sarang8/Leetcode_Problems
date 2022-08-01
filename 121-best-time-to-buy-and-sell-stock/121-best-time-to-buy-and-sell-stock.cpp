class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = prices[0];
        int max_profit=0;
        
        for(int i=1; i<prices.size(); i++){
            
            int cost = prices[i] - mini;
            max_profit = max(max_profit, cost);
            mini = min(mini, prices[i]);
        }
        return max_profit;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int mini = INT_MAX;
//         int max_prof = 0;
        
//         for(int i=0; i<prices.size(); i++){
            
//             mini = min(mini, prices[i]);
            
//             max_prof = max(max_prof,(prices[i] - mini));   
//         }
//         return max_prof;
        
    }
};