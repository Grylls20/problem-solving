//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &m, int r, int c) {
    int min_val = INT_MAX, max_val = INT_MIN;
    
    // Finding min and max values in the matrix
    for (int i = 0; i < r; i++) {
        if (m[i][0] < min_val)
            min_val = m[i][0];
        if (m[i][c - 1] > max_val)
            max_val = m[i][c - 1];
    }
    
    int desired = (r * c + 1) / 2;
    while (min_val < max_val) {
        int mid_val = min_val + (max_val - min_val) / 2;
        int place = 0;
        
        // Counting elements smaller than or equal to mid_val in each row
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i].begin(), m[i].end(), mid_val) - m[i].begin();
        
        if (place < desired)
            min_val = mid_val + 1;
        else
            max_val = mid_val;
    }
    return min_val;
}
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends