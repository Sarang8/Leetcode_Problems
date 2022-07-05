class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
//         int n=nums.size();
        
//         if(n==0){
//             return 0;
//         }
        
//         set<int>s;
        
//         for(int it:nums){
//             s.insert(it);
//         }
        
//         int longestStreak=0;
//         for(int it:nums){
            
//             if(s.count(it-1)==0){
//                 int currStreak=1;
//                 int currNum = it;
                
//                 while(s.count(currNum+1)){
//                     currStreak++;
//                     currNum=currNum+1;
//                 }
                
//                 longestStreak=max(longestStreak, currStreak);
//             }  
            
//         }
        
        
//         return longestStreak;
        
         if(nums.size()==0){
            return 0;
        }
        
        unordered_set<int>s;
        
        for(int n:nums){
            s.insert(n);
        }
        
        int longestStreak=0;
        
        for(int n: nums){
            if(s.count(n-1)==0){
                int currStreak=1;
                int currNum = n;
                
                while(s.count(currNum+1)){
                    currStreak++;
                    currNum = currNum+1; 
                }
                
                longestStreak = max(longestStreak, currStreak);
            }  
            
        }
        return longestStreak;
        
    }
};