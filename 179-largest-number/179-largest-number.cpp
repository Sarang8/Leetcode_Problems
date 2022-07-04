class Solution {
public:
    
    static bool compare(string a, string b){
        return a+b>b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        
        vector<string>v;
        int n = nums.size();
        
        for(int i=0;i<n; i++){
            
            v.push_back(to_string(nums[i]));
            
        }
        
        sort(v.begin(), v.end(), compare);
        
        string result="";
        
        for(int i=0; i<n; i++){
            result+=v[i];
        }
        
        if(result[0]=='0' && result[result.size()-1]=='0'){
            return "0";
        }
       
            return result; 
        
    }
};