class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int n=img1.size();
        vector<pair<int,int>>vecA;
        vector<pair<int,int>>vecB;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(img1[i][j]==1){
                    vecA.push_back({i, j});
                }
                if(img2[i][j]==1){
                    vecB.push_back({i, j});
                }
            }
        }
        
        int ans=0;
        map<pair<int,int>, int>mp;
        
        for(auto it1:vecA){
            for(auto it2 : vecB){
                mp[{it1.first-it2.first, it1.second-it2.second}]++;
                ans=max(ans, mp[{it1.first-it2.first, it1.second-it2.second}]);
            }
        }
        return ans;   
    }
};