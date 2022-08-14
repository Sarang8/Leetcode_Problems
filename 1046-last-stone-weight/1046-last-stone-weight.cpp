class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
//         sort(stones.begin(), stones.end());
//         int n=stones.size();
        
//         while(stones.size()>1){
            
//             int a=stones[stones.size()-1];
//             int b=stones[stones.size()-2];
            
//             if(a==b){
//                 stones.pop_back();
//                 stones.pop_back();
//             }
//             else if(a>b){
//                 stones.pop_back();
//                 stones.pop_back();
//                 stones.push_back(a-b);
//                 sort(stones.begin(), stones.end());
//             }   
            
//         }
        
//         if(stones.size()==1)
//             return stones[0];
//         else return 0;
        
        
            priority_queue<int> pq(stones.begin(),stones.end());
    
            while(pq.size()>1)
            {
                int y=pq.top();
                pq.pop();
                int x=pq.top();
                pq.pop();
                if(x!=y)pq.push(y-x);
            }
            return pq.empty()?0:pq.top();
        
    }
};