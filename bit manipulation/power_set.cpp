//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> str;
		    int n=s.length();
		    for(int i=1; i<(1<<n); i++) {
		        int cur=i;
		        string cur_str="";
		        for(int i=0; i<n; i++) {
		            if(cur & (1<<i)) {
		                cur_str+=s[i];
		            }
		        }
		        str.push_back(cur_str);
		    }
		    sort(str.begin(),  str.end());
		    return str;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends