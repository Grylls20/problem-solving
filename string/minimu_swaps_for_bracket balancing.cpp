//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        int cnt1=0, cnt2=0;
        
        int ans=0;
        int diff=0;
        
        for(int i=0; i<s.length(); i++) {
            // from left
            if(s[i]=='[') {
                cnt1++;
                if(diff>0) {
                    ans+=diff;
                    diff--;
                }
            // from right    
            } else if(s[i]==']') {
                cnt2++;
                diff=cnt2-cnt1;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends