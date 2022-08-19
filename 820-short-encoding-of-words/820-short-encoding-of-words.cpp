class Solution {
public:
    
    static bool compare(string &a, string &b){
        return a.length()>b.length();
    }
    
    
    int minimumLengthEncoding(vector<string>& words) {
        
        int n=words.size();
        
        sort(words.begin(), words.end(), compare);
        
        string ans="";
        ans += words[0]+"#";
        
        for(int i=1; i<n; i++){
            
            string temp=words[i];
            
            int pos = ans.find(words[i]+"#");
            
            if(pos!=-1){
                continue;
            }
            else{
                ans += words[i]+"#";
            }            
        }
        return ans.size();        
    }
};