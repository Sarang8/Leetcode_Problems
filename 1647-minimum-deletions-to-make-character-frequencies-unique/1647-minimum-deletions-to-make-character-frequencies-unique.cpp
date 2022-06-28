class Solution {
public:
    static bool cmpr(int a, int b){
        return a>b;
    }
    
    int minDeletions(string s) {
        int n=s.size();
        int ans=0;
        vector<int>v(26);
        
        for(int i=0; i<n; i++){
            v[s[i]-'a']++;
        }
        
        sort(v.begin(), v.end(), cmpr);
        
        int MaxAlwdFreq = v[0];
        
        for(int i=0; i<v.size(); i++){
            
            if(v[i]>MaxAlwdFreq){
                
                if(MaxAlwdFreq>0){
                    ans+=(v[i]-MaxAlwdFreq);
                }
                else{
                    ans+=v[i];
                }
            }
           
            MaxAlwdFreq=min( MaxAlwdFreq-1, v[i]-1);    
        }
        
      return ans;  
        
        
    }
};