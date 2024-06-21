//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        if (n <= 2) return 0; // If there are less than 3 blocks, no water can be trapped

        long long area = 0;
        int lt[n], rt[n];

        // Fill left maximum array
        lt[0] = arr[0];
        for (int i = 1; i < n; i++) {
            lt[i] = max(arr[i], lt[i-1]);
        }

        // Fill right maximum array
        rt[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            rt[i] = max(arr[i], rt[i+1]);
        }

        // Calculate the accumulated water
        for (int i = 0; i < n; i++) {
            area += min(lt[i], rt[i]) - arr[i];
        }

        return area;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends