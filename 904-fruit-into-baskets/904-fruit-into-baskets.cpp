class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n=fruits.size();
        
        unordered_map<int,int>m;
        int i=0;
        int j=0;
        int ans=INT_MIN;
        
        while(j<n){
            
            m[fruits[j]]++;
            
            if(m.size()<2){
                ans = max(ans, (j-i+1));
                j++;
            }
            
            else if(m.size()==2){
                ans = max(ans, (j-i+1));
                j++;
            }
            
            else if(m.size()>2){
                while(m.size()>2){
                    m[fruits[i]]--;
                    if(m[fruits[i]]==0){
                        m.erase(fruits[i]);
                    }
                    i++;
                }
                if(m.size()==2){
                    ans = max(ans, (j-i+1));
                }
                j++;
            } 
        }
        return ans;
    }
};