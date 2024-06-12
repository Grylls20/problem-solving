//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> u, v;
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                v.push_back(arr[i]);
            } else {
                u.push_back(arr[i]);
            }
        }
        for (int i = 0; i < u.size(); i++) {
            arr[i] = u[i];
        }
        for (int i = 0; i < v.size(); i++) {
            arr[i + u.size()] = v[i];
        }
    }
};


//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends