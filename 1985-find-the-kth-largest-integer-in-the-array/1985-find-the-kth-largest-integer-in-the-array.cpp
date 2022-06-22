class Solution {
public:
    struct compr{
        bool operator()(string&a, string&b){
            if(a.size() != b.size())
                return a.size() > b.size();
            return a>b;
        }
    };
    
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string, vector<string>, compr>pq;
        
        for(int i=0; i<nums.size(); i++){
            
            //int j = stoi(nums[i]);
            pq.push(nums[i]);
            
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        return pq.top();
        //return to_string(p);
        
    }
};