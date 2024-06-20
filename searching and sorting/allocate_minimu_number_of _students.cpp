//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution 
{
public:
    static int findPages(int n, int A[], int m)
    {
        if (n < m) return -1; // If number of students are greater than number of books
        
        int sum = 0, maxPages = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (A[i] > maxPages) {
                maxPages = A[i];
            }
        }
        
        int low = maxPages; // Minimum pages any student can get is the maximum page in any single book
        int high = sum;     // Maximum pages any student can get is the sum of all pages
        
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(A, n, mid, m)) {
                result = mid;
                high = mid - 1; // Try for a smaller maximum pages
            } else {
                low = mid + 1;  // Increase the maximum pages
            }
        }
        
        return result;
    }
    
private:
    static bool isValid(int A[], int n, int maxPagesPerStudent, int m)
    {
        int studentsRequired = 1;
        int pagesAssigned = 0;
        
        for (int i = 0; i < n; i++) {
            if (pagesAssigned + A[i] > maxPagesPerStudent) {
                studentsRequired++;
                pagesAssigned = A[i];
                if (studentsRequired > m) {
                    return false;
                }
            } else {
                pagesAssigned += A[i];
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution 
{
public:
    static int findPages(int n, int A[], int m)
    {
        if (n < m) return -1; // If number of students are greater than number of books
        
        int sum = 0, maxPages = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (A[i] > maxPages) {
                maxPages = A[i];
            }
        }
        
        int low = maxPages; // Minimum pages any student can get is the maximum page in any single book
        int high = sum;     // Maximum pages any student can get is the sum of all pages
        
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(A, n, mid, m)) {
                result = mid;
                high = mid - 1; // Try for a smaller maximum pages
            } else {
                low = mid + 1;  // Increase the maximum pages
            }
        }
        
        return result;
    }
    
private:
    static bool isValid(int A[], int n, int maxPagesPerStudent, int m)
    {
        int studentsRequired = 1;
        int pagesAssigned = 0;
        
        for (int i = 0; i < n; i++) {
            if (pagesAssigned + A[i] > maxPagesPerStudent) {
                studentsRequired++;
                pagesAssigned = A[i];
                if (studentsRequired > m) {
                    return false;
                }
            } else {
                pagesAssigned += A[i];
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends