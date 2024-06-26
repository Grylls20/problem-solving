//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n, int x) {
        int first_index = -1, last_index = -1;

        // Finding the first occurrence of x
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                first_index = i;
                break;
            }
        }

        // Finding the last occurrence of x
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == x) {
                last_index = i;
                break;
            }
        }

        // Checking if the element was found or not
        if (first_index == -1 && last_index == -1) {
            // Element not found, returning -1
            return {-1, -1};
        } else {
            // Returning both indices
            return {first_index, last_index};
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends