//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long inversionCount(vector<long long>& arr) {
        long long n = arr.size();
        vector<long long> sortedArr;
        sortedArr=arr;
        sort(sortedArr.begin(),sortedArr.end());
        // To maintain the sorted order of elements encountered so far
        long long cnt = 0;
        for (long long i=0; i<n; i++) {
        // Find the position where arr[i] should be inserted in sortedArr
            int val=arr[i];
            auto pos=lower_bound(sortedArr.begin(), sortedArr.end(), val);
        // Number of elements greater than arr[i] are those to the right of pos
            cnt+=(pos-sortedArr.begin());
            sortedArr.erase(pos);
        }

        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<long long> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
    }

    return 0;
}

// } Driver Code Ends