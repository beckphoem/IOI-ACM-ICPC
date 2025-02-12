#include<bits/stdc++.h>
#define maxM 10000 // limits at 10^4
#define maxN 10000

using namespace std;

long long m, n;
long long a[maxM][maxN];
long long maxFirst = 0, maxSecond = 0;

// This code has the time complexity of O(m * n) = 10^8
int main(){
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);

    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        long long maxRow = 0;
        // find max in row i
        for (int j = 0; j < m; j++){
            if (a[i][j] > maxRow){
                maxRow = a[i][j];
            }
        }

        // compare maxRow with maxFirst and maxSecond
        if (maxRow > maxFirst){
            maxSecond = maxFirst;
            maxFirst = maxRow;
        } else if (maxRow > maxSecond){
            maxSecond = maxRow;
        }
    }

    // cout << maxFirst << " " << maxSecond << endl;

    cout << maxFirst + maxSecond << endl;


    return 0;
}