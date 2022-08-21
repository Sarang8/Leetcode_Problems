class Solution {
public:
    
    string largestPalindromic(string s) {
        
        int n=s.size();
        unordered_map<char, int>m;
        
        for(auto it:s){
            m[it]++;
        }
        
        string lp="", rp="";
        
        for(int i=0; i<n; i++){
            
            for(int j=9; j>=0; j--){
                
                if(m[j+'0']>1 && (j>0 or lp.size()>0)){
                    lp += '0'+j;
                    rp += '0'+j;
                    m[j+'0']-=2;
                    break;
                }
            }  
        }
        
        for(int i=9; i>=0; i--){
            if(m[i+'0']>0){
                lp+='0'+i;
                break;
            }
        }
        
        reverse(rp.begin(), rp.end());
        
        return lp+rp;
        

        
    }

};