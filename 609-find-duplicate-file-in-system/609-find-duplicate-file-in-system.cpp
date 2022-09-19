class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        int n=paths.size();
        vector<vector<string>>ans;
        
        unordered_map<string, vector<string>>mp;
        
        for(auto pth : paths){
            int i=0, j;
            
            string dir="";
            
            while(pth[i] != ' '){
                i++;
            }
            dir = pth.substr(0, i);
            
            while(i<pth.size()){
                        
                string fileName;
                j=i+1;
                while(pth[i] != '('){
                    i++;
                }
                fileName=pth.substr(j, i-j);

                string content;
                j=i;
                while(pth[i] !=')'){
                    i++;
                }
                content=pth.substr(j, i-j);


                mp[content].push_back(dir+'/'+fileName);
                
                i++;
            }
            
        }
        
        for(auto it:mp){
            if((it.second).size() > 1){
                ans.push_back(it.second);
            }
        }
        
        
        return ans;
    }
};