//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        // Your code goes here
        int n= arr1.size(), m=arr2.size();
        int i=0,  j=0;
        
        if((m+n)&1) {
            int med;
            for(int idx=0; idx<=(m+n)/2; idx++) {
                if (i != n && j != m) {
                    med = (arr1[i] > arr2[j]) ? arr2[j++] : arr1[i++];
                } else if (i < n) {
                    med = arr1[i++];
                } else {
                    med = arr2[j++];
                }    
            }
            return med;
        } 
        
        else {
            float med1, med2;
            for (int idx = 0; idx <= (n + m) / 2; idx++) {
                med2 = med1;
                if (i != n && j != m) {
                    med1 = (arr1[i] > arr2[j]) ? arr2[j++] : arr1[i++];
                } else if (i < n) {
                    med1 = arr1[i++];
                } else {
                    med1 = arr2[j++];
                }
            }
            float med=(med1+med2)/2;
            return med;
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
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends