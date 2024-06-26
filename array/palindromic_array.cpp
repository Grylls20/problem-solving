//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:

    bool isPalin(int n) {
        string s =to_string(n);
        int i=0, j=s.length()-1;
        while(i<=j) {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i=0; i<n; i++) {
    	    if(!isPalin(a[i]))return false;
    	}
    	return true;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends