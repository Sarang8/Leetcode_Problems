class Solution {
public:
    int minPartitions(string n) {
        
        int size=n.size();
        int maxi=0;
        //int num = stoi(n);
        
        for(int j =0; j<size; j++){  
            maxi = max(maxi, n[j]-'0');
        }
        
         return maxi;
        
    }
};