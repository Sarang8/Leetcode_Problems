class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int>maxH;
        int n = heights.size();
        int ans;
        
        for(int i=0; i<n-1; i++){
            
            int diff = heights[i+1]-heights[i];
            
            if(diff<=0){
                continue;
            }
            
            else{
                
                if(diff<=bricks){
                    maxH.push(diff);
                    bricks-=diff;  
                    
                }
                else if(ladders>0){
                    
                    if(maxH.size()>0){
                        int currMaxBricks = maxH.top();
                        if(currMaxBricks>diff){
                            bricks+=currMaxBricks;
                            maxH.pop();
                            maxH.push(diff);
                            bricks-=diff;
                        }  
                    }
                    ladders--;
                }
                
                else{
                    ans=i;
                    return ans;
                }
            }   
        }
        
        return n-1;
    }
};