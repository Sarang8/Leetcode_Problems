class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int maxi= INT_MIN;
        int sum=0;
        
        for(int i=0; i<k; i++){
            sum+=cardPoints[i];
        }
        maxi=max(maxi, sum);
        
        int i=0;
        while(k>0){
           sum = sum - cardPoints[k-1] + cardPoints[n-1-i];
            i++;
            k--;
            maxi  = max(maxi, sum);
        }
        
        return maxi;
        
    }
};