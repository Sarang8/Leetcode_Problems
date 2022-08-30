class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        int n=g.size();
        sort(g.begin(), g.end());
        if(s.size()==0) return 0;
        priority_queue<int>pq;
        for(auto it:s){
            pq.push(it);
        }
        int ans=0;
        
        for(int i=n-1; i>=0; i--){
            if(!pq.empty() && g[i] > pq.top()){
                continue;
            }
            else if(!pq.empty() && g[i] <= pq.top()){
                ans++;
                pq.pop();
            }
        }
        
        return ans;
    }
};