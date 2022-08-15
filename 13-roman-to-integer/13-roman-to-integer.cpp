class Solution {
public:
    int romanToInt(string s) {
        
        int ans = 0;
        int n = s.size();
        int i=0;
        while(i<n){
            
            char a = s[i];
            
            if(a=='I'){
                if(s[i+1]=='V'){
                    ans += 4;
                    i++;
                }
                else if(s[i+1]=='X'){
                    ans += 9;
                    i++;
                }
                else{
                    ans+=1;
                } 
            }
            
            
            else if(a=='V'){
                ans+=5;
            }
            else if(a=='X'){
                if(s[i+1]=='L'){
                    ans += 40;
                    i++;
                }
                else if(s[i+1]=='C'){
                    ans += 90;
                    i++;
                }
                else{
                    ans+=10;
                }  
            }
            
            
            else if(a=='L'){
                ans+=50;
            }
            
            
            else if(a=='C'){
                if(s[i+1]=='D'){
                    ans += 400;
                    i++;
                }
                else if(s[i+1]=='M'){
                    ans += 900;
                    i++;
                }
                else{
                    ans+=100;
                }  
            }
            
            
            else if(a=='D'){
                ans+=500;
            }
            else if(a=='M'){
                ans+=1000;
            }
            i++;
            
        }
        
        return ans;
        
    }
};