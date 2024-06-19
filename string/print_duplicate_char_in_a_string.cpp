#include <bits/stdc++.h>
using namespace std;

void print_duplicates(string s, int n) {
    map<char, int> mp;
    for(char c:s) {
        mp[c]++;
    } 
    for(auto it: mp) {
        if(it.second>1) {
            cout << it.first << ", Count= " << it.second << endl;
        }
    }
}

int main() {
    string s;
    int n;
    cin >> n >> s;
    print_duplicate(s,n);
    return 0;
}