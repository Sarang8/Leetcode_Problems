class Solution {
public:
            
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string>dict(bank.begin(), bank.end());
        
        if(dict.find(end)==dict.end()){
            return -1;
        }
        
        queue<string>q;
        q.push(start);
        int ops=0;
        
        while(!q.empty()){
        
            int size=q.size();
            
            for(int i=0;i<size;i++){
                
                string curr=q.front();
                q.pop();
                
                if(curr==end){
                    return ops;
                }
                
                dict.erase(curr);
                
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    
                    temp[i]='A';
                    if(dict.find(temp)!=dict.end()){
                        q.push(temp);
                    }
                    
                    temp[i]='C';
                    if(dict.find(temp)!=dict.end()){
                        q.push(temp);
                    }
                    
                    temp[i]='G';
                    if(dict.find(temp)!=dict.end()){
                        q.push(temp);
                    }
                    
                    temp[i]='T';
                    if(dict.find(temp)!=dict.end()){
                        q.push(temp);
                    }   
                }
            }
            ops++;        
        }
        
        return -1;
        
    }
};