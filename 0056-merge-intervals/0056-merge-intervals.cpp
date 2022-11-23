class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        
        int n=inter.size();
        
        sort(inter.begin(), inter.end());
        
        vector<vector<int>>ans;
        
        vector<int>temp;
        temp=inter[0];
        
        for(int i=0;i<n;i++){
            
            if(temp[1]>=inter[i][0]){
                temp[1]=max(temp[1], inter[i][1]);
            }
            else{
                ans.push_back(temp);
                temp.clear();
                temp=inter[i];
                //temp.push_back(inter[i]);
            }
        }
        
        ans.push_back(temp);
        return ans;
    }
};