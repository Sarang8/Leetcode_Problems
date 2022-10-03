class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n=colors.size();
        int i=0;
        int j=1;
        int ans=0;
        while(j<n){
            
            if(colors[j]==colors[i]){
                int temp=0;
                if(neededTime[i]<=neededTime[j]){
                    temp = neededTime[i]; 
                    i=j;
                }
                else{
                    temp = neededTime[j];
                    
                }
                ans += temp;
            }
            
            else{
                i=j;
            }
            
            //cout<<i<<endl;
            
            j++;
        }
        return ans;
        
    }
};