//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<int> a(nums.begin(),nums.end());
	    //hashing
	    unordered_map<int,int>mp;           
	    sort(a.begin(),a.end());
	    
	    for(int i=0; i<nums.size(); i++) {
	        mp[nums[i]]=i;
	    }
	    
	    int swaps=0;
	    for(int i=0; i<nums.size(); i++) {
	        if(a[i]!=nums[i]) {
	            int prev_idx=mp[a[i]];
	            mp[a[i]]=-1;
	            
	            mp[nums[i]]=prev_idx;
	            
	            swaps++;
	            
	            swap(nums[prev_idx],nums[i]);
	        }
	    }
	    return swaps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends