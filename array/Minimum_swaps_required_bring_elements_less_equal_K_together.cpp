//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int a[], int n, int k) {
        // Complete the function
        int less=0;
        for(int i=0; i<n; i++) {
            if(a[i]<=k)less++;
        }
        int ans=less, more=0;
        for(int i=0; i<n; i++) {
            if (a[i]>k) {
                more++;
            }
            if (i==less-1) {
                ans=min(ans,more);
            } else if(i>=less) {
                if (a[i-less]>k) {
                    more-=1;
                }
                ans=min(ans,more);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends