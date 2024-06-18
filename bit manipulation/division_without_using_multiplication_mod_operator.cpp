//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        // Check for overflow
        if (dividend == LLONG_MIN && divisor == -1) return LLONG_MAX;
        
        // Determine the sign of the quotient
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        
        // Convert both dividend and divisor to positive
        long long dvd = abs(dividend), dvs = abs(divisor);
        long long quotient = 0, temp = 0;
        
        // Bitwise division
        for (int i = 31; i >= 0; i--) {
            if ((temp + (dvs << i)) <= dvd) {
                temp += (dvs << i);
                quotient |= (1LL << i);
            }
        }
        
        return quotient * sign;
    }
};


//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends