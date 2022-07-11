class Solution {
public:
    string minWindow(string s, string t) {
        
        string ans = "";
       
        if (t.length() > s.length()){
		    return "";
	    }

        if (s == t)
		    return s;
        
        int i = 0; 
        int j = 0;
        unordered_map<char,int>mp;
        
        for(int i=0; i<t.size(); i++){
            mp[t[i]]++;
        }
        
        int count=mp.size();
        int start;
        int end;
        int mini = INT_MAX;
        
        
        while(j<s.size()){
            
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            
            
             if(count > 0){
               j++;
             }
            
            
             else if(count==0){
                
                if(mini > (j-i+1)){
                    
                    mini = j-i+1;
                    end = j;
                    start=i;   
                }
                
                 while(count==0){
                     
                     if(mp.find(s[i])!=mp.end()){
                         
                         if(mp[s[i]]<=0){
                             mp[s[i]]++;
                             
                             if(mp[s[i]]>0){
                                 count++;
                             }
                         } 
                     }
                     i++;
                     
                     if(j-i+1 < mini && count==0){
                        mini = j-i+1;
                        end = j;
                        start=i; 
                     }
                 } 
                    j++;
            }
           
        }
        
        
    
        if (mini==INT_MAX){
		    return ans;
	    }
        
        for(int i=start; i<=end; i++){
            ans = ans + s[i];
        }
        return ans;
    }
};