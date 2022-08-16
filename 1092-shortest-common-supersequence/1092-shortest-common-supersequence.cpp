class Solution {
public:
    
     string solve(string s1, string s2, int x, int y){
        //FIRST FIND LCS TABLE*************
        int t[x+1][y+1];
        
        for(int i=0; i<x+1; i++){
            for(int j=0; j<y+1; j++){
                if(i==0 or j==0){
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i=1; i<x+1; i++){
            for(int j=1; j<y+1; j++){
        
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i][j-1], t[i-1][j]);
                }      
            }
        }
//***HERE WE GOT LCS TABLE******
//NOE JUST PRINT LCS....
//BUT HERE ALONG WITH LCS YOU HAVE TO PRINT THE OTHER CHARACTERS AS WELL 
//HENCE LITTLE CHAMGE IN ELSE CONDITION TO PUT OTHER CHHARACTRS ALONG WITH LCS
        
        int i = x;
        int j = y;
        string lcs="";
        
        while(i>0 && j>0){
            
            if(s1[i-1]==s2[j-1]){
                lcs.push_back(s1[i-1]);
                i--; 
                j--;
            }
            
            else{
                if(t[i][j-1]>t[i-1][j]){
                    lcs.push_back(s2[j-1]);  //HERE WE ARE PUTTING THAT EXTRAA CHARACTER
                    j--;
                }
                else{
                    lcs.push_back(s1[i-1]);   //HERE WE ARE PUTTING THAT EXTRAA CHARACTER
                    i--;
                }
                
            }
        }
         
         while(i>0){          //IF THERE ARE SOME ELEMENTS LEFT IN S1
             lcs.push_back(s1[i-1]);
             i--;
         }

          while(j>0){           //IF THERE ARE SOME ELEMENTS LEFT IN S1
             lcs.push_back(s2[j-1]);
             j--;
         }
         
         reverse(lcs.begin(), lcs.end());
         
         return lcs;
        
    }
    
    
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        int x= str1.length();
        int y= str2.length();
        return solve(str1, str2, x,y);
    }
};