// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int i, int j, int n){
        if(n==word.length()){
            return true;
        }
        
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]!=word[n]){
            return false;
        }
        
        board[i][j]='0';
        bool temp = ( solve(board, word, i-1, j, n+1) or
                        solve(board, word, i+1, j, n+1) or
                        solve(board, word, i, j-1, n+1) or
                        solve(board, word, i, j+1, n+1) );
        board[i][j]=word[n];
        return temp;
        
    }


    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    if(solve(board, word, i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends