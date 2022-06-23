class Solution {
public:
    
    static bool compare(vector<int>&a, vector<int>&b){
        
        return a[1]<b[1];
        
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        int n = courses.size();
        
        sort(courses.begin(), courses.end(), compare);
        
        priority_queue<int>pq;
        int days=0;
        
        for(int i=0; i<n; i++){
            
            if(days+courses[i][0]<=courses[i][1]){
                days+=courses[i][0]; 
                pq.push(courses[i][0]);
            }
            else if( !pq.empty() && pq.top()>courses[i][0]){
                days = days - pq.top();
                days = days + courses[i][0];
                pq.pop();
                pq.push(courses[i][0]);
            }
             
        }
        
        
        return pq.size();
            
    }
};