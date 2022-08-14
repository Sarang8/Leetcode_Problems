class Solution {
public:
    unordered_map<string, int> stepMap;
    unordered_map<string, set<string>> trailTracker;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> output;
        
        wordList.push_back(beginWord);
        stepMap.insert({ beginWord, 1 });
        
        queue<string> q({ beginWord });
        while (q.size()) {
            const string currWord = q.front();
            q.pop();
            
            const int nextStep = stepMap[currWord] + 1;
            
            for (string& word: wordList) {
                if (stepMap[word] == 0 || nextStep <= stepMap[word]) {
                    int charDiffs = 0;
                    for (int i = 0; i < word.size(); ++i) {
                        if (word[i] != currWord[i]) {
                            ++charDiffs;
                        }
                        if (charDiffs > 1) {
                            goto findingMoreWords;
                        }
                    }
                    trailTracker[word].insert({ currWord });
                    if (stepMap[word] == 0 || nextStep < stepMap[word]) {
                        q.push(word);
                    }
                    stepMap[word] = nextStep;
                }
                
                findingMoreWords:;
            }
        }
        
        vector<string> curr({ endWord });
        backtrack(beginWord, endWord, curr, output);
        return output;
    }
    
    void backtrack(string& targetWord, string word, vector<string>& curr, vector<vector<string>>& output) {
        if (word == targetWord) {
            vector<string> nextList = vector<string>(curr);
            reverse(nextList.begin(), nextList.end());
            output.push_back(nextList);
        }
        
        if (trailTracker.find(word) == trailTracker.end()) {
            return;
        }
        
        for (string nextWord: trailTracker[word]) {
            curr.push_back(nextWord);
            backtrack(targetWord, nextWord, curr, output);
            curr.pop_back();
        }
    }
};