class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int>ans;
        unordered_map<string, int>m, temp;
        int size=s.size();
        
        int N=words.size();
        int L=words[0].size();
        
        // Store all the frequencies of all strings
        // in the array words[]
        for(auto it:words){
            m[it]++;
        }
        
        
        
         // Loop till possible number of starting
        // index of the valid indices
        for(int i=0; i<size-N*L+1; i++){
            
            
            // Iterate the current window of
            // length N*L over the range
            // [i, i + N*L] and extract the
            // substring of length L and store
            // it's frequency
            for(int j=i; j<i+N*L; j=j+L){
                string curr = s.substr(j, L);
                temp[curr]++;
            }
            
            
            int flag=1;
            // Now, check if the frequency of each string
            // in map M is the same as the frequency in
            // map temp. This ensure that the current
            // window is of the same concatenation of
            // the strings in the array words[]
            for(auto it:m){
                if(m[it.first] != temp[it.first]){
                    flag=0;
                    break;
                }
            }
            
            // If the current window is the possible
			// result then store the starting index of it
            if(flag==1){
                ans.push_back(i);
            }
            
            // Clear the temp for another window
            temp.clear();
            
        }
        
        return ans;

    }
};