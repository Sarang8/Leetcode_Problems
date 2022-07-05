class Solution {
public:
    
    void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<bool>>& ocean){
        
        if(i<0 or j<0 or i>=heights.size() or j>=heights[0].size()){
            return;
        }
        if(heights[i][j]<prev or ocean[i][j]==true){
            return;
        }
        
        ocean[i][j]=true;
        
        dfs(heights, i+1, j, heights[i][j], ocean);
        dfs(heights, i-1, j, heights[i][j], ocean);
        dfs(heights, i, j+1, heights[i][j], ocean);
        dfs(heights, i, j-1, heights[i][j], ocean); 
    }
    
    
    
    
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>>ans;
        if(heights.size()==0 or heights[0].size()==0){
            return ans;
        }
        
        int row=heights.size();
        int col=heights[0].size();
        
        vector<vector<bool>>pacific(row, vector<bool>(col, false));
        vector<vector<bool>>atlantic(row, vector<bool>(col, false));
        
        //For 1st ans Last ROw(iterate over col)
        for(int p=0; p<col; p++){
            dfs(heights, 0, p, INT_MIN, pacific);
            dfs(heights, row-1, p, INT_MIN, atlantic);
            
        }
        
        //For 1st ans Last col(iterate over row)
        for(int q=0; q<row; q++){
            dfs(heights, q, 0, INT_MIN, pacific);
            dfs(heights, q, col-1, INT_MIN, atlantic);    
        }
        

    //Find the common true between both vectors        
        for(int i=0; i<row; i++){
            for(int j=0; j<col;j++){
                vector<int>temp;
                if(pacific[i][j]==true && atlantic[i][j]==true){
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }   
            }
        }
        
      return ans;  
        
    }
};