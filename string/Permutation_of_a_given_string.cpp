//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	private:
        void recur(vector<string> &arr, string s, int l, int r)
        {
            if (l == r) {
                arr.push_back(s);
                return;
            }
            for (int i = l; i <= r; i++) {
                swap(s[l], s[i]);   // swapping
                recur(arr, s, l + 1, r);  // Recursion
                swap(s[l], s[i]);  // Backtrack
            }
        }

    public:
        vector<string> find_permutation(string s)
        {
            vector<string> arr;
            int n = s.length();
            recur(arr, s, 0, n - 1);
            sort(arr.begin(), arr.end());
            arr.erase(unique(arr.begin(), arr.end()), arr.end());  // Remove duplicates
            return arr;
        }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends