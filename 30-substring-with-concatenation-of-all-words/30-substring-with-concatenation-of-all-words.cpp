class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int>ans;
        unordered_map<string, int>m, temp;
        int size=s.size();
        
        int N=words.size();
        int L=words[0].size();
        
        for(auto it:words){
            m[it]++;
        }
        
        
        
        for(int i=0; i<size-N*L+1; i++){
            
            
            for(int j=i; j<i+N*L; j=j+L){
                string curr = s.substr(j, L);
                temp[curr]++;
            }
            
            
            int flag=1;
            
            for(auto it:m){
                if(m[it.first] != temp[it.first]){
                    flag=0;
                    break;
                }
            }
            
            if(flag==1){
                ans.push_back(i);
            }
            
            temp.clear();
            
        }
        
        return ans;

    }
};