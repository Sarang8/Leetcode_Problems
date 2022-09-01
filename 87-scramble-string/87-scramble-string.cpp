class Solution {
public:
    bool solve(string a, string b, unordered_map<string , bool>&m){
        
        if(a==b){
            return true;
        }
        
        if(a.length()==1){
            return false;
        }
        
        string key = a + "_" + b;
       
        if(m.find(key)!=m.end()){
            return m[key];
        }
        
        
        
        int n=a.length();
        bool fl=false;
        
        for(int i=1; i<=n-1; i++){
            
            bool case1 = solve(a.substr(0, i),  b.substr(n-i, i), m) && 
                            solve(a.substr(i, n-i), b.substr(0, n-i), m);
            
            if(case1 == true){
                return m[key]=true;
            }
            
            
            bool case2 = solve(a.substr(0, i),  b.substr(0, i), m) && 
                            solve(a.substr(i, n-i), b.substr(i, n-i), m);
              
           
            
            
            if(case1 or case2){
                fl = true;
            }
            
        }
        
        return m[key]=fl;
        
    }
    
    
    
    bool isScramble(string s1, string s2) {
        
        if(s1=="" && s2==""){
            return true;
        }
        
        if(s1.length() != s2.length()){
            return false;
        }
        
        unordered_map<string , bool>m;
        
        return solve(s1, s2, m);
        
        
    }
};