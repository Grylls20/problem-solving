//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> a(n,0);
        int p=-1, k=-1;
        for(int i=0; i<n; i++) {
            a[arr[i]-1]++;
            if(a[arr[i]-1]==2) {
                p=arr[i];
            }
        }
        for(int i=0; i<n;i++) {
            if(a[i]==0) {
                k=i+1;
                break;
            }
        }
        return {p,k};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends