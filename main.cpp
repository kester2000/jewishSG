#include <bits/stdc++.h>

#include "jewishSG.h"

using namespace std;
using ll = long long;

int res[1000][N][N];

void print(int mp[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    int a, b;
    int mp[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mp[i][j] = 1;
        }
    }
    print(mp);
    cout << endl;
    while (1) {
        cin >> a;
        if (cin.fail()) continue;
        if (a >= -1) {
            cin >> b;
            if (cin.fail()) continue;
        }
        if (a >= 0 && a < N && b >= 0 && b < N) {
            mp[a][b] = !mp[a][b];
            print(mp);
            cout << endl;
        } else if (a == -1) {
            int n = SGMove(mp, b, res);
            for (int k = 0; k < n; k++) {
                print(res[k]);
                cout << endl;
            }
        } else if (a == -2) {
            print(mp);
            cout << SG(mp) << endl;
        } else if (a == -3) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    mp[i][j] = 0;
                }
            }
        } else if (a == -4) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    mp[i][j] = 1;
                }
            }
        }
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