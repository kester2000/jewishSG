#include "jewishSG.h"

#include <assert.h>
#include <string.h>

#include <map>

#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)

static std::map<long long, int> dp;

static long long getIJHash(int mp[N][N], int bi, int di, int bj, int dj)
{
    long long ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int ii = bi + di * i, jj = bj + dj * j;
            ret = ret * 2 + (ii >= 0 && ii < N && jj >= 0 && jj < N && mp[ii][jj] == 0);
        }
    }
    return ret;
}

static long long getJIHash(int mp[N][N], int bi, int di, int bj, int dj)
{
    long long ret = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            int ii = bi + di * i, jj = bj + dj * j;
            ret = ret * 2 + (ii >= 0 && ii < N && jj >= 0 && jj < N && mp[ii][jj] == 0);
        }
    }
    return ret;
}

long long getHash(int mp[N][N])
{
    int minI = N - 1, minJ = N - 1, maxI = 0, maxJ = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mp[i][j] == 0) {
                minI = min(minI, i);
                minJ = min(minJ, j);
                maxI = max(maxI, i);
                maxJ = max(maxJ, j);
            }
        }
    }

    long long ret = 0;
    ret = max(ret, getIJHash(mp, minI, 1, minJ, 1));
    ret = max(ret, getIJHash(mp, minI, 1, maxJ, -1));
    ret = max(ret, getIJHash(mp, maxI, -1, minJ, 1));
    ret = max(ret, getIJHash(mp, maxI, -1, maxJ, -1));
    ret = max(ret, getJIHash(mp, minI, 1, minJ, 1));
    ret = max(ret, getJIHash(mp, minI, 1, maxJ, -1));
    ret = max(ret, getJIHash(mp, maxI, -1, minJ, 1));
    ret = max(ret, getJIHash(mp, maxI, -1, maxJ, -1));
    return ret;
}

static int sg(int mp[N][N])
{
    long long hash = getHash(mp);
    if (dp.count(hash)) return dp[hash];
    int sgList[N * N + 10] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mp[i][j] == 0) {
                mp[i][j] = 1;
                int sgVal = SG(mp);
                sgList[sgVal] = 1;
                int k;
                for (k = 1; i + k < N && mp[i + k][j] == 0; k++) {
                    mp[i + k][j] = 1;
                    int sgVal = SG(mp);
                    sgList[sgVal] = 1;
                }
                for (k--; k >= 1; k--) {
                    mp[i + k][j] = 0;
                }

                for (k = 1; j + k < N && mp[i][j + k] == 0; k++) {
                    mp[i][j + k] = 1;
                    int sgVal = SG(mp);
                    sgList[sgVal] = 1;
                }
                for (k--; k >= 1; k--) {
                    mp[i][j + k] = 0;
                }

                for (k = 1; i + k < N && j + k < N && mp[i + k][j + k] == 0; k++) {
                    mp[i + k][j + k] = 1;
                    int sgVal = SG(mp);
                    sgList[sgVal] = 1;
                }
                for (k--; k >= 1; k--) {
                    mp[i + k][j + k] = 0;
                }

                for (k = 1; i + k < N && j - k >= 0 && mp[i + k][j - k] == 0; k++) {
                    mp[i + k][j - k] = 1;
                    int sgVal = SG(mp);
                    sgList[sgVal] = 1;
                }
                for (k--; k >= 1; k--) {
                    mp[i + k][j - k] = 0;
                }

                mp[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < N * N + 10; i++) {
        if (sgList[i] == 0) {
            return dp[hash] = i;
        }
    }
    assert(0);
}

static void color(int flag[N][N], int i, int j, int colorNum)
{
    static int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    static int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    flag[i][j] = colorNum;
    for (int k = 0; k < 9; k++) {
        int a = i + dx[k], b = j + dy[k];
        if (a >= 0 && a < N && b >= 0 && b < N && flag[a][b] == 0) {
            color(flag, a, b, colorNum);
        }
    }
}

int SG(int mp[N][N])
{
    int ret = 0;
    int colorNum = 2;
    int flag[N][N], subNum[N][N];
    memcpy(flag, mp, sizeof(flag));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (flag[i][j] == 0) {
                color(flag, i, j, colorNum);
                colorNum++;
            }
        }
    }
    for (int k = 2; k < colorNum; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                subNum[i][j] = flag[i][j] == k ? 0 : 1;
            }
        }
        int sgVal = sg(subNum);
        ret ^= sgVal;
    }
    return ret;
}

int SGMove(int mp[N][N], int target, int (*p)[N][N])
{
    int top = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mp[i][j] == 0) {
                mp[i][j] = 1;
                int sgVal = SG(mp);
                if (sgVal == target) {
                    memcpy(p[top], mp, N * N * sizeof(int));
                    top++;
                }
                int k;
                for (k = 1; i + k < N && mp[i + k][j] == 0; k++) {
                    mp[i + k][j] = 1;
                    int sgVal = SG(mp);
                    if (sgVal == target) {
                        memcpy(p[top], mp, N * N * sizeof(int));
                        top++;
                    }
                }
                for (k--; k >= 1; k--) {
                    mp[i + k][j] = 0;
                }

                for (k = 1; j + k < N && mp[i][j + k] == 0; k++) {
                    mp[i][j + k] = 1;
                    int sgVal = SG(mp);
                    if (sgVal == target) {
                        memcpy(p[top], mp, N * N * sizeof(int));
                        top++;
                    }
                }
                for (k--; k >= 1; k--) {
                    mp[i][j + k] = 0;
                }

                for (k = 1; i + k < N && j + k < N && mp[i + k][j + k] == 0; k++) {
                    mp[i + k][j + k] = 1;
                    int sgVal = SG(mp);
                    if (sgVal == target) {
                        memcpy(p[top], mp, N * N * sizeof(int));
                        top++;
                    }
                }
                for (k--; k >= 1; k--) {
                    mp[i + k][j + k] = 0;
                }

                for (k = 1; i + k < N && j - k >= 0 && mp[i + k][j - k] == 0; k++) {
                    mp[i + k][j - k] = 1;
                    int sgVal = SG(mp);
                    if (sgVal == target) {
                        memcpy(p[top], mp, N * N * sizeof(int));
                        top++;
                    }
                }
                for (k--; k >= 1; k--) {
                    mp[i + k][j - k] = 0;
                }

                mp[i][j] = 0;
            }
        }
    }
    return top;
}
