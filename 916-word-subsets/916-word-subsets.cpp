class Solution {
public:
    
    vector<int>FindCount(string &a){
        vector<int>cnt(26);
        for(int i=0; i<a.size(); i++){
            cnt[a[i]-'a']++;
        } 
        return cnt;
    }
    
    
    
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {  
        
        vector<int>count(26);
        
        for(int i=0; i<words2.size(); i++){
            
            vector<int>temp = FindCount(words2[i]);
            
            for(int j=0; j<26; j++){
                count[j] = max(count[j], temp[j]);
            }
        }
        
        
        vector<string>ans;

        for(int i=0; i<words1.size(); i++){
            vector<int>freq = FindCount(words1[i]);
            
            int j=0;
            for(j=0; j<26; j++){
                if(count[j]>freq[j]){
                    break;
                }
            }
            if(j==26){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};