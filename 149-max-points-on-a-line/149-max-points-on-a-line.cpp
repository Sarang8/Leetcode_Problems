class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        if(n<=2) return n;
        
       
        int maxPt=0;
        double slope=0.0;
        unordered_map<double, int>m;
        for(int i=0; i<n; i++){
             
            for(int j=i+1; j<n; j++){
                
                int x1=points[i][0];
                int x2=points[j][0];
                
                int y1=points[i][1];
                int y2=points[j][1];
                
                if(x2==x1) slope=INT_MAX;
                
                else
                    slope = (double)(y2-y1) / (double) (x2-x1);
                
                m[slope]++; 
            }
            for(auto it:m){
            maxPt = max(maxPt, it.second);
             }
            m.clear();
        }
        
        
        
        
       return maxPt+1; 
    }
};