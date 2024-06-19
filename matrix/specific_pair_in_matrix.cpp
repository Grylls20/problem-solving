#include <iostream>
#include <climits> // for INT_MIN
using namespace std;

#define N 5

int findMaxValue(int mat[][N]) {
    int maxValue = INT_MIN;

    // maxArr[i][j] will store the maximum value from mat[i][j] to the bottom-right corner
    int maxArr[N][N];

    // Start populating maxArr from the bottom-right corner
    maxArr[N - 1][N - 1] = mat[N - 1][N - 1];

    // Fill last row of maxArr
    int maxv = mat[N - 1][N - 1];
    for (int j = N - 2; j >= 0; j--) {
        if (mat[N - 1][j] > maxv)
            maxv = mat[N - 1][j];
        maxArr[N - 1][j] = maxv;
    }

    // Fill last column of maxArr
    maxv = mat[N - 1][N - 1];
    for (int i = N - 2; i >= 0; i--) {
        if (mat[i][N - 1] > maxv)
            maxv = mat[i][N - 1];
        maxArr[i][N - 1] = maxv;
    }

    // Fill the rest of the maxArr
    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 2; j >= 0; j--) {
            // Update maxValue if the current element can provide a better result
            if (maxArr[i + 1][j + 1] - mat[i][j] > maxValue)
                maxValue = maxArr[i + 1][j + 1] - mat[i][j];

            // Update maxArr[i][j] to store the maximum of current element, right and bottom elements
            maxArr[i][j] = max(mat[i][j], max(maxArr[i][j + 1], maxArr[i + 1][j]));
        }
    }

    return maxValue;
}

int main() {
    int mat[N][N] = {
        { 1, 2, -1, -4, -20 },
        { -8, -3, 4, 2, 1 },
        { 3, 8, 6, 1, 3 },
        { -4, -1, 1, 7, -6 },
        { 0, -4, 10, -5, 1 }
    };

    cout << "Maximum Value is " << findMaxValue(mat) << endl;

    return 0;
}
