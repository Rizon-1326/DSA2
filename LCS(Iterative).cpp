#include <bits/stdc++.h>
using namespace std;

int c[100][100];
char b[100][100];

int main()
{
    string x, y;
    cin >> x >> y;

    int m = x.size(), n = y.size();

    for (int i = 0; i <= m; i++) {
        c[i][0] = 0;
    }

    for (int j = 0; j <= n; j++) {
        c[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'd';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }

    cout << "LCS length = " << c[m][n] << endl;

    cout << "LCS is  : ";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (b[i][j] == 'd') {
            cout << x[i - 1];
            i--;
            j--;
        } else if (b[i][j] == 'u') {
            i--;
        } else {
            j--;
        }
    }
    cout << endl;

    return 0;
}

