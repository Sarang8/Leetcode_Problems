class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
       //SEE HOW TO DECLARE 2D VECTOR..........///////***************
        vector<vector<int>> ans(n, vector<int> (n));
        int strtR=0;
        int strtC=0;
        int EndR=n-1;
        int EndC=n-1;
        int p = 1;
        
        while( strtR<=EndR && strtC<=EndC ){
            
            for(int i=strtC; i<=EndC; i++){
                ans[strtR][i] = p;
                p++;
            }
            strtR++;
            if(strtR>EndR)  break;
            
            for(int i=strtR; i<=EndR; i++){
                ans[i][EndC] = p;
                p++;
            }
            EndC--;
            if(EndC<strtC)  break;
            
            for(int i=EndC; i>=strtC; i--){
                ans[EndR][i] = p;
                p++;
            }
            EndR--;
            if(EndR<strtR)  break;
            
            for(int i=EndR; i>=strtR; i--){
                ans[i][strtC] = p;
                p++;
            }
            strtC++;
            if(strtC>EndC)  break;
            
        }         
            return ans;
    }
};