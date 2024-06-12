//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        if (n==1) return "1";
        if (n==2) return "11";
        string say="11";
        for(int i=3; i<=n; i++) {
            string temp="";
            int cnt=1;
            say+='&';
            for(int j=1; j<say.length();j++) {
                if(say[j]!=say[j-1]){
                    temp+=to_string(cnt);
                    temp+=say[j-1];
                    cnt=1;
                }else {
                    cnt++;
                }
            }
            say=temp;
        }
        return say;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends