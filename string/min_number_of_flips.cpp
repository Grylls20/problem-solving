//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string s)
{
    // your code here
    int flip1=0, flip2=0;
    for(int i=0; i<s.size(); i++) {
        // 10...
        if(i&1 && s[i]!='0' || (i&1)==0 && s[i]!='1') flip1++;
        // 01...
        if(i&1 && s[i]!='1' || (i&1)==0 && s[i]!='0') flip2++;
        
    }
    return min(flip1,flip2);
}