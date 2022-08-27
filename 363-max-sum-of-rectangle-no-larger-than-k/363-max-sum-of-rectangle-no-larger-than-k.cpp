class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        int res=INT_MIN;
        vector<int>row_sum(m,0);
        
        for(int lcol=0; lcol<n; lcol++){
                
            fill(row_sum.begin(), row_sum.end(), 0);
            
            for(int rcol=lcol; rcol<n; rcol++){
                
                for(int row=0; row<m; row++){
                    row_sum[row] += matrix[row][rcol];
                }
                
                set<int>s{0};
                int run_sum=0;
                
                for(int sum:row_sum){
                    run_sum += sum;
                    auto it = s.lower_bound(run_sum - k);
                    if(it!=s.end()){
                        res = max(res, run_sum - *it);
                    }
                    
                    s.insert(run_sum);
                }
            }
        }
        return res;
    }
};