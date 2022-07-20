class Solution {
public:
//     int dp[50001][5001];
    
//     bool isSubsequence(string s, string t, int i, int j){
        
//         if(i<0 && j<0) return true; 
//         if(i<0) return false;
//         if(j<0) return true;
        
//         if(dp[i][j]=-1) return dp[i][j];
        
//         bool t1,t2;
//         if(s[i]==t[j]){
//             t1 = isSubsequence(s,t,i-1,j-1) + isSubsequence(s,t,i-1,j);
//         }
//         else{
//             t2=isSubsequence(s,t,i-1,j);
//         }
        
        
//         return dp[i][j]= (t1 or t2);
        
        
//     }
    
    
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int ans=0;
        int n=words.size();
        int size=s.size();
//         memset(dp,-1,sizeof(dp));
        
//         for(int i=0; i<n; i++){
            
//             string temp=words[i];
//             int j = temp.size();
//             if(isSubsequence(s, words[i], size-1, j-1)){
//                 ans+=1;
//             }
            
//         }
        
//         return ans;
        
        
        unordered_map<string,int>m;
        
        for(int i=0; i<n; i++){
            m[words[i]]++;
        }
        
        
        for(auto it:m){
            
            string temp=it.first;
            int i=0;  //for temp size
            int j=0;
            
            while(i<temp.size() && j<s.size()){
                if(temp[i]==s[j]){
                    i++;
                    j++;
                }

                else{
                    j++;
                }
            }
            
            if(i==temp.size()){
                ans+=it.second;
            }
        }
        return ans;  
    }
};