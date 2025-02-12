#include<bits/stdc++.h>
#define maxM 10000 // limits at 10^4
#define maxN 10000

using namespace std;

long long m, n;
long long a[maxM][maxN], b[maxN][maxM];
long long maxFirst = 0, maxSecond = 0;

// The complexity of this code is O(m * n * log(n)) due to the sorting step. 
int main(){
    freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);

    cin >> m >> n;
    for (int  i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    // sort descending the rows.
    for (int i = 0; i < m; i++){
        // The sort function sorts the elements in the range [a[i], a[i] + n) in descending order.
        // The greater<int>() is a comparison function that specifies the sorting order.
        // It returns true if the first argument is greater than the second, resulting in descending order.
        sort(a[i], a[i] + n, greater<int>());
    }
    // checking the matrix
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // create the transpose matrix 
    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            b[i][j] = a[j][i];
        }
    }
    
    cout << "Inverse matrix: " << endl;
    // checking the transpose matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // sort the first row in the transpose matrix
    sort(b[0], b[0] + n, greater<int>());
    cout << "Sort the first row: " << endl;
    // checking the transpose matrix
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    // the result is the sum of the first two elements in the first row of the transpose matrix
    cout << b[0][0] + b[0][1] << endl;

    return 0;
}