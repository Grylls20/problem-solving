//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPalindrome(string s)
	{
	    int n=s.length();
	    string k = s;
	    reverse(s.begin(),s.end());
	    int p=0;
	    for (int i=0; i<n; i++) {
	        if (s[i]==k[i]) {
	            p+=1;
	        }
	    }
	    if (p==n) return 1;
	    else return 0;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends