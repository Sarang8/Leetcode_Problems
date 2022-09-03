class Solution {
public:
    
    void dfs(int num, int n, int k, vector<int>&ans){
        //cout<<n<<endl;
        
        if(n==0){
            ans.push_back(num);
            return;
        }
        
        int last_digit = num%10;
        
        if(last_digit >= k){
            //num = num*10 + (last_digit - k);
            dfs(num*10 + (last_digit - k), n-1, k, ans);
        }
        
        if(k>0 && last_digit + k <= 9){
            //num = num*10 + (last_digit + k);
            dfs(num*10 + (last_digit + k),  n-1, k, ans);
        }

    }
    
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        if(n==1){
            ans.push_back(0);
        }
        
        for(int d=1; d<=9; d++){
            dfs(d, n-1, k, ans);
        }
        
        return ans;        
    }
};