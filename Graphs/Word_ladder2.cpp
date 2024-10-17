class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;         // To track the shortest distance to each word
        vector<vector<string>> ans;            // To store all shortest paths
        for (auto& it: wordList) mp[it]=INT_MAX;
        // If endWord is not in wordList, return empty
        if (!mp.count(endWord)) return ans;
        mp[beginWord]=0;
        bfs(beginWord, endWord, mp, ans);
        return ans;
    }

private:
    void bfs(string& beginWord, string& endWord, unordered_map<string, int>& mp, vector<vector<string>>& ans) {
        queue<pair<string, vector<string>>> q;   // To store the current word and its path
        q.push({beginWord, {beginWord}});        
        int found=INT_MAX;                     // To stop once the shortest path length is found
        while (!q.empty()) {
            int k=q.size();
            unordered_set<string> st;  // To mark words visited at current level
            for (int i=0; i<k; i++) {
                auto [w,v]=q.front();  // To get current word and its path
                q.pop();                
                // Store the path if we reach endWord
                if (w==endWord) {
                    if ((int)v.size()<=found) {
                        found=(int)v.size();
                        ans.push_back(v);
                    }
                    continue;
                }                
                // If we've already found a path with minimum length, then stop finding longer path
                if ((int)v.size()>found) continue;
                for (int j=0; j<w.size(); j++) {
                    string temp=w;
                    for (char c='a'; c<='z'; c++) {
                        if (c==w[j]) continue;
                        temp[j]=c;                        
                        // If the word is in word list and not visited in this level
                        if (mp.count(temp) && mp[temp]>=(int)v.size()) {
                            st.insert(temp);
                            mp[temp]=(int)v.size();  // Mark as visited with the shortest path
                            v.push_back(temp);
                            q.push({temp, v});
                            v.pop_back();  // Backtrack to try other changes
                        }
                    }
                }
            }           
            // Update the visited map for the next level
            for (const auto& it : st) {
                mp[it]=min(mp[it], (int)q.front().second.size());
            }
        }
    }
};