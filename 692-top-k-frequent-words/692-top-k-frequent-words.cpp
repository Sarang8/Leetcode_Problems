class Solution {
public:
    
    struct cmpr{
        bool operator()(pair<int,string> &a, pair<int,string> &b){
            
            if(a.first==b.first){
                return a.second < b.second;   
            }
            else{
                return a.first > b.first;   
            }  
        }
    };
    
    
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
       
        int n=words.size();
        unordered_map<string,int>mp;
        
        for(auto it:words){
            mp[it]++;
        }
        
        priority_queue< pair<int,string>, vector<pair<int,string>>, cmpr>pq;
        for(auto it:mp){
            pq.push({it.second, it.first});
            
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<string>ans;
        
        while(!pq.empty()){
            
            string temp=pq.top().second;
            pq.pop();
            ans.push_back(temp);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};