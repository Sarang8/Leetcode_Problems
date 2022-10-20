class Solution {
public:
    string intToRoman(int num) {
        
         //int m[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<int>m = {1000, 900,  500, 400, 100, 90, 50, 40, 10, 9, 5, 4,1};
        vector<string>ch = {"M", "CM","D", "CD", "C", "XC","L", "XL" ,"X", "IX", "V","IV","I"};
        //vector<char>ch = {'M', 'CM','D', 'CD', 'C', 'XC','L', 'XL' 'X', "IX" "V","IV","I"};
        
        string ans="";
        
        for(int i=0;i<13;i++){
            
            if(num>=m[i]){
                
                while(num>=m[i]){
                    //cout<<i<<endl;
                    ans += ch[i];
                    num = num-m[i]; 
                }
               
            }
        }
        
        return ans;
    }
};