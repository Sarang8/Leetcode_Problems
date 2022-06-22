class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char, int>m;
        
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        
        priority_queue<pair<int, char>>pq;
        
        for(auto i:m){
            pq.push({i.second, i.first});
        }
        
        string ans="";
        while(pq.size()>1){
            
            auto x = pq.top();
            pq.pop();
            auto y= pq.top();
            pq.pop();
            
            ans+=x.second;
            ans+=y.second;
            
            x.first--;
            y.first--;
            
            if(x.first>0){
                pq.push(x);
            }
            if(y.first>0){
                pq.push(y);
            }
        }
        
        if(!pq.empty()){
            if(pq.top().first > 1){
                return "";
            } 
            else{
                ans+=pq.top().second;
            }  
        }
        
        
        return ans;
        
        
        
        
    }
};