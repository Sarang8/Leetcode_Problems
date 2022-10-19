class Solution {
public:
    
    struct cmpr{
        bool operator()(pair<int,string>&a, pair<int,string>&b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n=words.size();
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            m[words[i]]++;
        }
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, cmpr>pq;
        for(auto it:m){
            pq.push({it.second, it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<string> ans;
        
        while(k>0){
            
            string a = pq.top().second;
            pq.pop();
            ans.push_back(a);
            k--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};