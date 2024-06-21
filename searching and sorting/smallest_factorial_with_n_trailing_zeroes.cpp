//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
        //complete the function here
        int ans=1, cnt=0;
        while(true) {
            int temp=ans;
            while(temp%5==0) {
                cnt++;
                temp/=5;
            }
            while(cnt>=n) {
                return ans;
            }
            ans++;
        }
        
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends