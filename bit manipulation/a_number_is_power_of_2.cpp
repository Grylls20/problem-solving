//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    long long CountSetBit(long long n) {
        long long cnt=0;
        while(n) {
            if(n%2==1) {
                cnt++;
            }
            n=n/2;
        }
        return cnt;
    }
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n) {
        if(CountSetBit(n)==1LL) return true;
        else return false;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {

    int t;
    cin >> t; // testcases

    for (int i = 0; i < t; i++) {
        long long n; // input a number n
        cin >> n;
        // if (n == 11) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        if (ob.isPowerofTwo(n)) // Now, if log2 produces an integer not decimal then we
                                // are sure raising 2 to this value
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}

// } Driver Code Ends