class Solution {
public:
    int bfs(string startWord, string targetWord, unordered_set<string>& st) {
        queue<pair<string, int>> q;  // To store current word and number of steps
        q.push({startWord,1});
        st.erase(startWord);
        while (!q.empty()) {
            // Fetching current word and no. of steps from the front of queue
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if (word==targetWord) {
                return steps;
            }
            /// All possible changes
            for (int i=0; i<word.size(); i++) {
                char original=word[i];
                for (char ch='a'; ch<='z'; ch++) {
                    word[i]=ch;                    // Changing character
                    // If found, valid for further steps
                    if (st.find(word)!=st.end()) { 
                        st.erase(word);           
                        q.push({word, steps+1});  // Pushing new word
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        return bfs(beginWord, endWord, st);
    }
};