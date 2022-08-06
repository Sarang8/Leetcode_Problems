class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int n=columnTitle.size();
        long long ans=0;
        int j=n-1;
        long long t=1;
            
        while(j>=0){
            
            char ch=columnTitle[j];
            int temp = ch-'A'+1;
            ans = ans + temp*t;
            j--;
            t=t*26;
        }
        
       return ans; 
    }
};