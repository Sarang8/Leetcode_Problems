class Solution {
public:
   bool closeStrings(string word1, string word2) {
        
        //w1 and w2 will store the frequency of word1 and word2 respectively
        //w3 and w4 will mark 1 at charcter's position 
        vector<int> w1(26,0) , w2(26,0) , w3(26,0) , w4(26,0);
        
        //storing the frequency of characters in w1 and
		//marking 1 at character's position in w3
        for(char c:word1){
            w1[c-'a']++;
            w3[c-'a']=1;
        }  
        
        //storing the frequency of characters in w2 and
		//marking 1 at character's position in w4
        for(char c:word2){
            w2[c-'a']++;
            w4[c-'a']=1;
        } 
        
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        
        return w1==w2 && w3==w4;
    }
};