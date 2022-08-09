class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        if(nums.size()==0){
            return 0;
        }
        set<int>s;
        for(auto it:nums){
            s.insert(it);
        }
        
        int longestStreak=1;
        
        for(int i=0; i<n; i++){
            
            if(s.count(nums[i]-1)==0){
                int currStreak=1;
                int currNum=nums[i];
                
                while(s.count(currNum+1)){
                    currStreak++;
                    currNum++;
                }
                longestStreak=max(longestStreak, currStreak);
            }
            
            
        }
        
        
        return longestStreak;        
    }
};