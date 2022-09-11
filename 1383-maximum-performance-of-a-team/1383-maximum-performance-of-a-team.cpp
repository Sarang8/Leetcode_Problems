#define ll long long
class Solution {
public:
    static bool cmpr(pair<ll,ll> &a, pair<ll,ll> &b){
        
        if(a.first>b.first){
            return true;
        }
        // else if(a.first==b.first){
        //     return a.second<b.second;
        // }
        
        return false;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<ll,ll>>v;
        int mod=1e9+7;
        
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i], speed[i]});
        }
        
        sort(v.begin(), v.end(), cmpr);
        priority_queue<ll, vector<ll>, greater<ll>>pq;
        
//         for(auto it:v){
//             cout<<it.first<<" "<<it.second<<endl;
//         }
        
        //pq.push(v[0].first * v[0].second);
        ll spd=0;
        ll maxi=INT_MIN;
        
        for(int i=0; i<n; i++){
            
            pq.push(v[i].second);
            spd = (spd + v[i].second);
            
            //cout<<maxi<<endl;
            
            if(pq.size()>k){
                spd-=pq.top();
                pq.pop();
            }
            
            maxi = max(maxi, (spd*(v[i].first)));

        }
        
        return maxi%mod;   
    }
};