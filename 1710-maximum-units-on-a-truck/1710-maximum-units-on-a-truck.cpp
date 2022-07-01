class Solution {
public:
    
    static bool compare(vector<int>&a, vector<int>&b){ 
        
        if(a[1]==b[1]) return a[0]<b[0];
        else
            return  a[1]>b[1];
    }
    
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
     
        int n = boxTypes.size();
        
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        // for(int i=0; i<n; i++){
        //     cout<<boxTypes[i][0]<<" "<<boxTypes[i][1]<<endl;
        // }
        int ans=0;
        
        for(int i=0; i<n; i++){
            if(truckSize>=boxTypes[i][0]){
                ans+=boxTypes[i][1]*boxTypes[i][0];
                //cout<<ans<<endl;
            }
            else{
                int temp = truckSize;
                //cout<<temp<<endl;
                ans += (temp*boxTypes[i][1]);
                //cout<<ans<<endl;
                break;
            }
           truckSize-= boxTypes[i][0];
        }
        return ans;
        
    }
};