class Solution {
public:
    string minWindow(string s, string t) {
        
        int n=s.size();
        //int v=t.size();
        
        unordered_map<char,int>m;
        for(auto it:t){
            m[it]++;
        }
        
        int count = m.size();
        
        int j=0;
        int i=0;
        int start=0, end=0;
        int ans=INT_MAX;
        while(j<n){
            
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0){
                    count--;
                }
            }
            
            if(count>0){
                j++;
            }
            
            else if(count==0){
                
                if(j-i+1 < ans){
                    ans=j-i+1;
                    start=i;
                    end=j; 
                }
                
                while(count==0){
                    if(m.find(s[i])!=m.end()){
                        
                        if(m[s[i]]<=0){
                             m[s[i]]++;
                            
                            if(m[s[i]]>0){
                                count++;
                            }
                        }   
                    }
                    i++;
                    if(count==0 && j-i+1 < ans){
                        ans=j-i+1;
                        start=i;
                        end=j; 
                    }   
                }
                 j++;
            }            
        }
        
        string res="";
        if(ans==INT_MAX){
            return "";
        }
        
        for(int i=start;i<=end;i++){
            res += s[i];
        }
        
        return res;
    }
};