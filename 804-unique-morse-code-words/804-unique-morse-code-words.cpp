class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        int n=words.size();
        
        // map<string,string>m;
        // m.insert({"a", ".-"});
        set<string>st;
        vector<string> m ={ ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
        
        for(int i=0; i<n; i++){
            string ans="";
            string temp=words[i];
            for(int j=0; j<temp.size(); j++){
                ans += m[temp[j]-'a'];
            }
            st.insert(ans);
        }
        
        return st.size();
    }
};