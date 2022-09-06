class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        queue<pair<int,int>>q;
        vector<int>visi(n, 0);
        q.push({arr[start], start});
        visi[start]=1;
        
        while(!q.empty()){
            
            int val = q.front().first;
            int ind = q.front().second;
            q.pop();
            
            if(val==0){
                return true;
            }
            
            
            int ind1 = (ind+arr[ind]);
            if(ind1<n && visi [ind1] == 0){
                q.push( {arr[ind1],  ind1} );
                visi [ind1]=1;
            }
            
            int ind2 = (ind-arr[ind]);
            if(ind2>=0 && visi [ind2] == 0){
                q.push( {arr[ind2],  ind2} );
                visi [ind2]=1;
            }        
        }
        
        return false;
        
    }
};