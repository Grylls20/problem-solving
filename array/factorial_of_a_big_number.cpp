//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    // code here
    int mul(vector<int>& arr, int k, int size) {
        int carry = 0;
        for (int i = 0;i < size;i++) {
            int curr_mul = k * arr[i] + carry;
            arr[i] = curr_mul % 10;
            carry = curr_mul / 10;
        }
        // if carry !=0
        while (carry) {
            arr.push_back(carry % 10);
            carry /= 10;
            size++;
        }
        return size;
    }
    vector<int> factorial(int n) {
        vector<int> arr = { 1 };
        int size = 1;
        for (int i = 2;i <= n;i++) {
            size = mul(arr, i, size);
        }
        
        reverse(arr.begin(), arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends