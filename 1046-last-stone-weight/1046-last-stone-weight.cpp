class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        sort(stones.begin(), stones.end());
        int n=stones.size();
        
        while(stones.size()>1){
            
            int a=stones[stones.size()-1];
            int b=stones[stones.size()-2];
            
            if(a==b){
                stones.pop_back();
                stones.pop_back();
            }
            else if(a>b){
                stones.pop_back();
                stones.pop_back();
                stones.push_back(a-b);
                sort(stones.begin(), stones.end());
            }   
            
        }
        
        if(stones.size()==1)
            return stones[0];
        else return 0;
        
    }
};