class Solution {
public:
    int minPartitions(string n) {
        
        //if(n==1) return 1;
        
        int size=n.size();
        int maxi=0;
        //int num = stoi(n);
        
        for(int j =0; j<size; j++){  
            maxi = max(maxi, n[j]-'0');
        }
        
        
//         while(num>0){
            
//             int LastDigit=num%10;
//             num = num/10;
//             maxi = max(maxi, LastDigit);
//         }
        
        
         return maxi;
        
        
        
    }
};