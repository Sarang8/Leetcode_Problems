class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int count=0;
        int res =0;
        
        for(int i=0; i<gain.size();i++){
            count = count+gain[i];
            res = max(count, res);
        }
        return res;
        
    }
};