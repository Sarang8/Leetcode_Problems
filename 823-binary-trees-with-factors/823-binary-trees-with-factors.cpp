class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        int n=arr.size();
        int mod=1e9+7;
        sort(arr.begin(), arr.end());
        unordered_map<int,long long>m;
        
        for(auto it:arr){
            m[it]=1;
        }
        
        
        for(int i=1; i<n; i++){ 
            long long cnt=0;
            for(int j=0; j<i; j++){
                
                if(arr[i]%arr[j]==0){
                    if(m.find(arr[i]/arr[j])!=m.end()){
                        cnt += ((m[arr[j]])%mod * (m[arr[i]/arr[j]])%mod)%mod;
                    }
                }
            }
            
            m[arr[i]] = m[arr[i]]+cnt%mod; 
        }
        
        
        long long ans=0;
        for(auto it:m){
            ans = (ans + it.second%mod)%mod;
        }
        
        
        
        return ans%mod;
        
        
    }
};