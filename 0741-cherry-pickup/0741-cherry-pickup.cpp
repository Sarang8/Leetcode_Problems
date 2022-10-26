// class Solution {
// public:
//     bool fl=0;
    
//     int solve2(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp2){
//         int n=grid.size();
//         int m=grid[0].size();
        
//         if(i==0 && j==0){
//             return grid[i][j];
//         }
        
//         if(i<0 or j<0 or grid[i][j]==-1){
//             return -1e8;
//         }
//         if(dp2[i][j]!=-1) return dp2[i][j];
        
//         int t1=0,t2=0;
        
//         if(grid[i][j]==1){
//             //grid[i][j]=0;
//             t1 += 1 + max(solve2(i-1, j, grid, dp2),solve2(i, j-1, grid, dp2));
//         }
//         else if(grid[i][j]==0){
//             t2+=0+max(solve2(i-1, j, grid, dp2),solve2(i, j-1, grid, dp2));
//         }
        
        
        
//         return dp2[i][j]=max(t1, t2);  
//     }
    
    
//     int solve1(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp1){
        
//         int n=grid.size();
//         int m=grid[0].size();
        
//         if(i==n-1 && j==m-1){
//             fl=1;   
//             return grid[i][j];
//         }
        
//         if(i>=n or grid[i][j]==-1 or j>=m) return -1e8;
        
//         if(dp1[i][j]!=-1) return dp1[i][j];
        
//         int t1=0,t2=0;
        
//         if(grid[i][j]==1){
//             grid[i][j]=0;
//             t1 += 1 + max(solve1(i+1, j, grid, dp1),solve1(i, j+1, grid, dp1));
//         }
//         else if(grid[i][j]==0){
//             t2+=0+max(solve1(i+1, j, grid, dp1),solve1(i, j+1, grid, dp1));
//         }
        
        
//         // if(t1-1==-1e8 && t2==-1e8){
//         //     return -1e8;
//         // }
//         // if(t1>t2){
//         //     grid[i][j]=0;
//         // }
//         return dp1[i][j]=max(t1, t2);
        
//     }
    
    
//     // HERE I USED BOOL FLAG JUST TO ENSURE THAT THE WE CAN REACH TO LAST CELL
//     //I.E THERE IS PATH TO REACH TO LAST CELL THATS IT
    
//     int cherryPickup(vector<vector<int>>& grid) {
        
//         int n=grid.size();
//         int m=grid[0].size();
        
//         if(n==1) return grid[0][0];
        
//         if(grid[0][0]==-1 or grid[n-1][m-1]==-1) return 0;
        
//         vector<vector<int>>dp1(n+1, vector<int>(m+1, -1));
//         vector<vector<int>>dp2(n+1, vector<int>(m+1, -1));
//         int temp1 = solve1(0, 0, grid, dp1);
//         //cout<<temp1;
//         //cout<<fl<<endl;
//         if(fl==0) return 0;
        
//         int temp2=solve2(n-1, m-1, grid, dp2);
//         //cout<<temp2;
        
        
//         return temp1+temp2;
//     }
// };






class Solution {
public:
//     int solve(vector<vector<int>>& grid,int i1,int j1,int i2,int j2,vector<vector<vector<vector<int>>>> &dp)
//     {
//         int m=grid[0].size(),n=grid.size();
        
// if(j1>=m || i1>=n || j2>=m || i2>=n || grid[i1][j1]==-1 || grid[i2][j2]==-1)
//             return -1e8;
//         if(dp[i1][j1][i2][j2]!=-1)
//             return dp[i1][j1][i2][j2];
//         if(i1==n-1 and j1==m-1)
//         {
//             return grid[i1][j1];
//         }
        
//         int x=0;
//         if(i1==i2 and j1==j2)
//             x=grid[i1][j1];
//         else   
// 	    	x=grid[i1][j1]+grid[i2][j2];
           
//       // P1     |      P2
//     //   DOWN    |     DOWN
//     //   DOWN    |     RIGHT
//     //   RIGHT   |     DOWN
//     //   RIGHT   |     RIGHT
//         x+=max({solve(grid,i1+1,j1,i2+1,j2,dp),solve(grid,i1+1,j1,i2,j2+1,dp),
//                solve(grid,i1,j1+1,i2+1,j2,dp),solve(grid,i1,j1+1,i2,j2+1,dp)
//                 });
//         return dp[i1][j1][i2][j2]=x;
        
//     }
//     int cherryPickup(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//  vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(m,-1))));
// return max(0,solve(grid,0,0,0,0,dp));        
//     }
    
    
    
    
    
    
    int cherry_picker(vector<vector<int>>& grid,vector<vector<vector<int>>>&dp,int r1,int c1,int c2,int n)
    {
        int r2 = r1 + c1 - c2;//explanation in the above section 
        //if any of the current rows or colums goes out of bound or there is a thorn on a current block then return INT_MIN
        if(r1>=n || r2>=n || c1>=n || c2>=n|| grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
        if(dp[r1][c1][c2]!=-1)//if we have already calculated the value for current state then return that value
            return dp[r1][c1][c2];
        //if we are right most bottom corner then simply return grid value
        if(r1==n-1 && c1 == n-1)
            return grid[r1][c1];
        //ans will be the ans for current state + future state
        int ans = grid[r1][c1];
        if(r1!=r2)//this is put in place to not pickup a cherry that is already picked up
            ans += grid[r2][c2];//if the cherry is not picked up already then pick it up
        //Now we need to take the max of 4 cases for both traversals
        //1.) Right Right
        //2.) Down Down
        //3.) Right Down
        //4.) Down Right
        int temp = max({cherry_picker(grid,dp,r1,c1+1,c2+1,n),cherry_picker(grid,dp,r1+1,c1,c2,n),
                       cherry_picker(grid,dp,r1,c1+1,c2,n),cherry_picker(grid,dp,r1+1,c1,c2+1,n)});
        ans += temp;//add it to the ans
        dp[r1][c1][c2] = ans;//memorise the answer
        return ans;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,cherry_picker(grid,dp,0,0,0,n));
    }
    
    
};