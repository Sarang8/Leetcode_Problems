class Solution {
public:
    
    int solve(vector<int> s1, vector<int> s2, int n, int m){
        
        int t[n+1][m+1];
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 or j==0){
                    t[i][j]=0;
                }
            }
        }
        
        //int maxi = INT_MIN;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                
                if(s1[i-1]==s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                    //maxi = max(maxi, t[i][j]);
                }
                else{
                    t[i][j]=0;
                }
            }
        }
        
        int maxi = INT_MIN;
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                maxi = max(maxi, t[i][j]);
            }
        }
        return maxi;
    }
    
    
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size();
        int y = nums2.size();
        return solve(nums1, nums2, x, y);
        
    }
};