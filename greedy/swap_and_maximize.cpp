//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int i=0, j=1, n=arr.size();
        int ans=0;
        while(i<(n-1)) {
            ans+=abs(arr[i]-arr[n-1]) + abs(arr[j]-arr[n-1]);
            n--;
            i++;
            j++;
            if(i>=(n-1)) {
                ans+=abs(arr[i]-arr[0]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Endss