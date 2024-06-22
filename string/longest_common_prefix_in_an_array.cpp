//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        string ans = arr[0];

        for (int i = 1;i < n;i++) {
            string curr = arr[i];

            //reducing the ans.
            // neither it will move on.
            if (curr == ans) continue;

            int j = 0;
            // compare 
            while (j < min(curr.size(), ans.size()) && curr[j] == ans[j]) j++;
            // update ans
            // till char match
            ans = ans.substr(0, j);
        }
        if(ans.size()==0) return "-1";
        else return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends