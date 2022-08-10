class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int>nums;
        
        int fact=1;
        
        for(int i=1; i<n; i++){
            nums.push_back(i);
            fact = fact*i;        
        }
        
        nums.push_back(n);
        k=k-1;
        string ans="";
        
        
        while(true){
            
            int temp = k/fact;
            ans = ans + to_string(nums[temp]);
            
            nums.erase(nums.begin()+temp);
            
            if(nums.size()==0){
                break;
            }
            
            k = k%fact;
            
            fact = fact/nums.size();
  
        }
        return ans;  
        
    }
};