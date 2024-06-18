//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        // First, we sort the intervals based on the starting time.
        sort(intervals.begin(),intervals.end());
        // This will store our merged intervals.
        vector<vector<int>> ans;
        for(const auto& it: intervals) {
            if(ans.empty()|| ans.back()[1]<it[0]) {
                ans.push_back(it);
            } else {
                // If there is an overlap, merge the current interval with the last one in ans.
                ans.back()[1]=max(ans.back()[1],it[1]);
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends