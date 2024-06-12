//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n) {
        long long max_ending=0;
        long long cur_max=INT_MIN;
        for(long long i=0;i<n;i++) {
            max_ending=max_ending+arr[i];
            if(cur_max<max_ending) {
                cur_max=max_ending;
            }
            if(max_ending<0) {
                max_ending=0;
            }
        }
        return cur_max;
    }
};

//{ Driver Code Starts.

int main() {
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends