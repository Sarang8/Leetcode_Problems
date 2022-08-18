class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int h=n/2;
        cout<<n<<endl;
        
        unordered_map<int,int>m;
        
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        
        priority_queue<pair<int,int>>pq;
        
        
        for(auto it:m){
            pq.push({it.second, it.first});
            cout<<it.second<<" "<<it.first<<endl;
        }
        
        
        cout<<endl;
        int ops=0;
        
        while(true){
            
            auto t=pq.top();
            pq.pop();
            
            n = n-t.first;
            cout<<n<<endl;
            ops++;
            
            if(n<=h){
               break; 
            }
        }
        return ops;
    }
};