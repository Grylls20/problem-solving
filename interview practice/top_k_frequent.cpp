#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp; // map to store frequency of each number
        for(int it: nums) {
            mp[it]++;
        }
        vector<vector<int>>bucket (n+1);  // Creating bucket where index=frequency
        for(auto& [num, cnt]: mp) {
            bucket[cnt].push_back(num);   // Storing number according to their corresponding frequency bucket
        }
        vector<int> ans; // to store top k frequent element
        for(int i=n; i>=0; --i) {   // iterating according to highest frequency first
            for(int num: bucket[i]) {
                ans.push_back(num);
                if(ans.size()==k) return ans;
            }
        }
    }
}

int main() {
    Solution sol;
    int k;
    cin >> k;
    vector<int> nums;
    for(int num: nums) {
        cin >> num;
    }
    vector<int> ans=sol.topKFrequent(nums,k); // Calling function
    for(int num: ans) {
        cout << num << " ";
    }
    return 0;
}