class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n=tokens.size();
        sort(tokens.begin(), tokens.end());
        int score=0;
        int left=0;
        int right=n-1;
        
        while(left<=right){
                
            if(power>=tokens[left]){
                power-=tokens[left];
                score+=1;
                left++;
            }
            else{
                if(power + tokens[right] >= tokens[left] && score!=0 && right!=left){
                    power += tokens[right];
                    score--;
                    right--;
                }
                else{
                    break;
                } 
            }
            
            
            
        }
        
        
        return score;
        
    }
};