class Solution {
public:
    bool winnerOfGame(string colors) {
         if(colors.size()<=2)
            return false;
        int a=0;// how many times 'A' will be able to play 
        int b=0;// how many times 'B' will be able to play 
        for(int i=1;i<colors.size()-1;i++)
        {
            if(colors[i]=='A' && colors[i-1]=='A'&& colors[i+1]=='A')
                a++;
            if(colors[i]=='B' && colors[i-1]=='B'&& colors[i+1]=='B')
                b++;
        }
        if(a > b) // if the occurance of A and B are same then in the next chance A will not be able to remove so it losses.
            return true;
        return false;
        
    }
};