#pragma once

#define N 6

extern "C" {
long long getHash(int mp[N][N]);
int SG(int mp[N][N]);
int SGMove(int mp[N][N], int target, int (*p)[N][N]);
}