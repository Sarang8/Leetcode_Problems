class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        
        
        unordered_map<long long,long long>m;
        int n=tasks.size();
        long long day=0;
        for(int i=0;i<n;i++){
            
            if(m.find(tasks[i])!=m.end()){
                
                if(m[tasks[i]] > day){
                    day = m[tasks[i]];
                }  
                m[tasks[i]]=day+space+1;
                day++; 
            }
            
            else{
                m[tasks[i]]= day+space+1;
                day++;
            }
               
        }
        
        return day;
        
        
    }
};