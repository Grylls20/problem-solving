//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xory = nums[0];
        for (int i = 1;i < nums.size();i++) {
            xory ^= nums[i];
        }
    

        // to get least bit 
        int least = xory & (~(xory - 1));

        // separating the x and y.
        int x = 0, y = 0;
        for (auto i : nums) {
            if (i & least) x ^= i;
            else y ^= i;
        }

        if (x < y) return { x,y };
        else return { y, x };
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends