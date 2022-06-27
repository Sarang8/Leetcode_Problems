class Solution {
public:
    
    void solve(int ind, string &digits, vector<string>&map, string &op, vector<string>&ans){
        
        if(ind==digits.size()){
            ans.push_back(op);
            return;
        }
        
        int num = digits[ind] - '0';
        //cout<<num<<endl;
        string temp = map[num];
        //cout<<"sdjc"<<temp<<endl;
        
        
        for(int i=0; i<temp.size(); i++){
            op.push_back(temp[i]);
            solve(ind+1, digits, map, op, ans);
            op.pop_back();
        } 
    }
    
    
    vector<string> letterCombinations(string digits) {
        
        vector<string>ans;
        if(digits.size()==0) return ans;
        
        vector<string>map{"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        //string map[10] = {"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        string op="";
        solve(0, digits, map,op,ans);
        return ans;
        
    }
};