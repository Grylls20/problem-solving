//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        vector<long long> dp(sum+1,0);
        dp[0]=1;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=sum; j++) {
                if(j-coins[i-1]>=0) {
                    dp[j]+=dp[j-coins[i-1]];
                }
            }
        }
        return dp[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends