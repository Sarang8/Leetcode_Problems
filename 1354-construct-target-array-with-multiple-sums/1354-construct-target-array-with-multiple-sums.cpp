class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        int n = target.size();
        priority_queue<int> pq;
        long long  sum=0;
        
        for(int i=0;i<n;i++){
            sum+=target[i];
            pq.push(target[i]);
        }
        
        
        while(pq.top()!=1){
           
            int value = pq.top();
            pq.pop();
            long long  diff = sum - value;
           
            
            if(diff==1)  return true;
            
            if(diff>value || diff==0 || value%diff==0)  return false;
            
            value = value%diff;
            sum = diff+value;
            pq.push(value);
      
        }
        return true;    
    }
};