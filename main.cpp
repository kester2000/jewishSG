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
    mp[0][0]=0;
    mp[0][1]=0;
    mp[0][2]=0;
    mp[0][3]=0;
    mp[1][0]=0;
    mp[1][1]=0;
    mp[1][3]=0;
    mp[2][0]=0;
    mp[2][1]=0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << mp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << getHash(mp) << endl;
    cout << SG(mp) << endl;
    cout << endl;
    // cout << getHash(mp) << endl;
    return 0;
}