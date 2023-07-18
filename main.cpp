#include <bits/stdc++.h>

#include "jewishSG.h"

using namespace std;
using ll = long long;

int res[1000][N][N];

int main()
{
    int mp[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mp[i][j] = 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            mp[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << getHash(mp) << endl;
    cout << SG(mp) << endl;
    cout << endl;
    // int n = SGMove(mp, 1, res);
    // for (int k = 0; k < n; k++) {
    //     cout << endl;
    //     cout << getHash(res[k]) << endl;
    //     for (int i = 0; i < N; i++) {
    //         for (int j = 0; j < N; j++) {
    //             cout << res[k][i][j] << ' ';
    //         }
    //         cout << endl;
    //     }
    // }
    return 0;
}