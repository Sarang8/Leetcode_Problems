class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>m;
        unordered_set<int>s;
        
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        
        for(auto it:m){
            //if()
            s.insert(it.second);
        }
        return s.size()==m.size();
    }
};