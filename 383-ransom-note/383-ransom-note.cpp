class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int>m;
        
        for(auto it:ransomNote){
            m[it]++;
        }
        
        //cout<<m.size()<<endl;
        
        for(int i=0;i<magazine.size(); i++){
            
            if(m.find(magazine[i])!=m.end()){
                m[magazine[i]]--;
                
                 if(m[magazine[i]]==0){
                        m.erase(magazine[i]);
                 }
            }
           // cout<<m.size()<<endl;
        }
        
        if(m.empty()){
            return true;
        }
        else{
            return false;
        }
        
    }
};