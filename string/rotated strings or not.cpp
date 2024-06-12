//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    
    bool areRotations(string str1, string str2){
   if(str1.length() != str2.length())
      return false;
   string con_str = str1 + str1;
   if(con_str.find(str2) != string::npos){
      return true;
   } else {
      return false;
   }
}
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends