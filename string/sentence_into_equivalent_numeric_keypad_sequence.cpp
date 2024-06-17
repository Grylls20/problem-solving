//{ Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}

// } Driver Code Ends


string printSequence(string s) {
    // Mapping characters to their respective key sequences on a mobile keypad
    vector<string> str = {
        "2", "22", "222",  // A, B, C
        "3", "33", "333",  // D, E, F
        "4", "44", "444",  // G, H, I
        "5", "55", "555",  // J, K, L
        "6", "66", "666",  // M, N, O
        "7", "77", "777", "7777",  // P, Q, R, S
        "8", "88", "888",  // T, U, V
        "9", "99", "999", "9999"  // W, X, Y, Z
    };
    
    string x = "";
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(s[i] == ' ') {
            x += "0";  
        } else {
            x += str[s[i] - 'A'];  // Mapping each character to the corresponding sequence
        }
    }
    return x;
}
