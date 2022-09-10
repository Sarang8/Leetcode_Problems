class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n=position.size();
        vector<pair<int,double>>temp;
        stack<int>st;
        
        for(int i=0;i<n;i++){
            double t = (double)(target - position[i]) / (double)speed[i]; 
            
            temp.push_back({position[i], t});
        }
        
        sort(temp.begin(), temp.end());
        
        
        double slowest = temp[n-1].second;
        int ans=1;
        
        for(int i=n-2; i>=0; i--){
            
            if(temp[i].second > slowest){
                ans++;
                slowest = temp[i].second;
            }
            
        }
        return ans;
    }
};