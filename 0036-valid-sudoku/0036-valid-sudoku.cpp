class Solution {
public:
    
//     bool check(vector<vector<char>>& board, int row, int col, char k){
        
//         for(int i=0; i<9; i++){
            
//             if(i!=row && board[row][i]==k){
//                 return false;
//             }
            
//             if(i!=col && board[i][col]==k){
//                 return false;
//             }
            
            
//             if( board[3*(row/3)+i/3][3*(col/3)+i%3] == k){
//                 return false;
//             }
//         }
//         return true;
//     }
    
    
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<int>>rowBox(9,vector<int>(9));
        vector<vector<int>>colBox(9,vector<int>(9));
        vector<vector<int>>sqrBox(9,vector<int>(9));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j]=='.') continue;
                
                int num=board[i][j]-'0'-1;
                
                if( rowBox[i][num] or colBox[j][num] or sqrBox[3*(i/3) + j/3][num] ){
                    return false;
                }
                
                rowBox[i][num]=1;
                colBox[j][num] =1;
                sqrBox[3*(i/3) + j/3][num]= 1;     
            }
        }
        
        
        return true;
        
        
    }
};