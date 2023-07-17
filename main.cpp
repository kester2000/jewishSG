#include <bits/stdc++.h>

#include "jewishSG.h"

using namespace std;
using ll = long long;

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
    for (int j = 1; j < 5; j++) {
        mp[1][j] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << SG(mp) << endl;
    return 0;
}