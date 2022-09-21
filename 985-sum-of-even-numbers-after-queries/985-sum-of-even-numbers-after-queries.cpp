class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n=nums.size();
        int m=queries.size();
        
        vector<int>ans;
        int evenSum=0;
        for(auto it:nums){
            if(it%2==0){
                evenSum+=it;
            }
        }
        
        for(int i=0;i<m;i++){
            
            int idx = queries[i][1];
            int val = queries[i][0];
            int temp = nums[idx];
            
            int updt = temp + val;
            nums[idx] = updt;
            
            if(temp%2==0){
                if(updt%2==0){
                    evenSum -= temp;
                    evenSum += updt;
                    //cout<<evenSum<<endl;
                    ans.push_back(evenSum);
                }
                else{
                    evenSum-=temp;
                    ans.push_back(evenSum);
                }
            }
            else{
                if(updt%2==0){
                    evenSum += updt;
                    //cout<<evenSum<<endl;
                    ans.push_back(evenSum);
                }
                else{
                    ans.push_back(evenSum);
                }
            }  
        }
        
        
        return ans;
        
    }
};