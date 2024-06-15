//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countBit(int n) {
        int cnt=0;
        while(n>0) {
            if(n%2==1){
                cnt++;
            }
            n=n/2;
        }
        return cnt;
    }
    int findPosition(int n) {
        // code here
        int cnt=countBit(n);
        if(cnt==1) {
            return log2(n)+1;
        } else {
            return -1;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends