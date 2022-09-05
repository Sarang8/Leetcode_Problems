class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int N=words.size();
        int L=words[0].size();
        vector<int>ans;
        
        unordered_map<string, int>m, temp;
        
        for(auto it:words){
            m[it]++;
        }
        
        
        
        for(int i=0; i<s.size()-N*L+1; i++){
            
            for(int j=i; j<i+N*L; j=j+L){
                
                string curr = s.substr(j, L);
                temp[curr]++;
            }
            
            bool fl=1;
            
            for(auto it:m){
                if(m[it.first] != temp[it.first]){
                    fl=0;
                    break;
                }
            }
            
            if(fl==1){
                ans.push_back(i);
            }
            
            temp.clear(); 
        }
        return ans;   
    }
};