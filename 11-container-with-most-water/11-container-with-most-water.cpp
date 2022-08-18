class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int area = 0;
        int left_heightInd = 0;
        int right_heightInd = height.size()-1;
        
        while(left_heightInd<right_heightInd){
            
            int NewArea = ((min(height[left_heightInd], height[right_heightInd])) * (right_heightInd - left_heightInd));
            
            area = max (area, NewArea);
            
            if(height[left_heightInd]>height[right_heightInd]){
                right_heightInd--;
            }
            else{
                left_heightInd++;
                
            }
            
             
        }
        return area;
        
    }
};