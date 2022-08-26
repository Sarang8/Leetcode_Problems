class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string num = to_string(n);
        sort(num.begin(), num.end());
        
        for(int i=0; i<32; i++){
            //powOf2 = powOf2<<i;
            string strPowOf2 = to_string(1<<i);
            sort(strPowOf2.begin(), strPowOf2.end());
            
            if(strPowOf2==num) return true;
        }
        
        return false;
    }
};