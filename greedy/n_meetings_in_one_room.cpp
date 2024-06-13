//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    static bool comparison(pair<int, int> meet1, pair<int, int> meet2) {
        if (meet1.second != meet2.second) 
            return (meet1.second < meet2.second);
        else 
            return (meet1.first < meet2.first);
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> schedule(n);
        for (int i = 0; i < n; i++) {
            schedule[i] = {start[i], end[i]};
        }
        sort(schedule.begin(), schedule.end(), comparison);
        int meet = 0, temp = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (schedule[i].first > temp) {
                temp = schedule[i].second;
                meet++;
            }
        }
        return meet;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends