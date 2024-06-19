#include <bits/stdc++.h>
using namespace std;

int without_MPD(int n) {
    n = abs(n);  // Ensure n is non-negative

    int ans = 0;
    int bit_position = 0;

    while (n > 0) {
        if (n & 1) {  // Check if the least significant bit (LSB) is set
            ans += (n << bit_position);
        }
        n >>= 1;  // Right shift n to process the next bit
        bit_position++;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << without_MPD() << endl;
    return 0;
}