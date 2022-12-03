class Solution {
public:
    string frequencySort(string s) {
        
        sort(s.begin(),s.end());
            int count=1;
            vector<pair<int,char>>v;
            string c;
            for(int i=0;i<s.size()-1;i++){
                if(s[i]==s[i+1])
                     count++;
              else 
               {
                    v.push_back({count,s[i]});
                    count=1;
               }
            }
             v.push_back({count,s[s.size()-1]});
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                for(int j=1;j<=v[i].first;j++)
                  c.push_back(v[i].second);
            }
        return c;
    }
};