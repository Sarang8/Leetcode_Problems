class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        //FIRST FIND PREFIX SUM in same matrix only
        for(int i=0; i<n; i++){
            for(int j=1; j<m;j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
//       for(int i=0; i<n; i++){
//             for(int j=0; j<m;j++){
//                 cout<<matrix[i][j]<<endl;
//             }
//         }
        
        unordered_map<int,int>mp;  
        int count=0;
        
        for(int c1=0; c1<m; c1++){
            for(int c2=c1; c2<m; c2++){  
                //mp[0]=1;
                mp = {{0,1}};
                int sum=0;
                for(int r=0; r<n; r++){
                    
                    sum+=matrix[r][c2];
                    if(c1>0){
                        sum -= matrix[r][c1-1];   
                    }
                            
                    if(mp.find(sum-target) != mp.end()){
                        count += mp[sum-target];
                    }
                    //count += mp.find(sum - target) != mp.end() ? mp[sum - target] : 0;
                    mp[sum]++;
                }
            }
        }
        return count; 
    }
};