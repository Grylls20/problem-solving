//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s) {
    set<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (st.find(s[i]) != st.end()) {
            return string(1, s[i]);
        }
        st.insert(s[i]);
    }
    return "-1"; // If no repeating character is found, return "-1"
}
