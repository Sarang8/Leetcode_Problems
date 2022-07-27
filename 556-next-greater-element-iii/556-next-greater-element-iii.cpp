class Solution {
public:
    int nextGreaterElement(int n) {
        
        string temp = to_string(n);
        
        
        int i=temp.size()-2;
        while(i>=0 && temp[i+1]<=temp[i]){
            i--;
        }
        
        if(i>=0){
            
            int j=temp.size()-1;
            while(temp[j]<=temp[i]){
                j--;
            }
            
            swap(temp[i], temp[j]);
            reverse(temp.begin()+i+1, temp.end());
            
            long long res=0;
            
            for(int i=0; i<temp.size(); i++) {
                int num = int(temp[i] - '0');
                if (res*10 + num > INT_MAX) return -1; // to handle the condition where `res` overflows `MAX_INT`
                else res = res*10 + num;
            }

            return res;
        }
        
        
        return -1;        
        
        
    }
};