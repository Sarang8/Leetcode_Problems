class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int>freq, seq;
        
        for(auto it:nums){
            freq[it]++;
        }
        
        
        for(auto x:nums){
            
            if (freq[x]==0) continue;
            
            if(seq[x-1]>0){
                
                freq[x]--;
                seq[x-1]-=1;
                seq[x]+=1;
                
            }
            
            else{
                if(freq[x+1]==0 or freq[x+2]==0){
                    return false;
                }
                
                freq[x]--;
                freq[x+1]--;
                freq[x+2]--;
                
                seq[x+2] += 1;  
            }
        }
        
        return true;
    }
};