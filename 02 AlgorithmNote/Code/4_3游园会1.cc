#include <cstdio>
#include <cstring>
#include <set>

#define MAX_N 12

using namespace std;

int g_projScore[MAX_N] = {0};
set<int> g_sumScore;

int main(void) {
    int n = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &g_projScore[i]);
    }

    for (unsigned int mask = 0; mask < (1 << n); ++mask) {  // 直接暴力搜索
        int sumTmp = 0;
        for (int i = 0; i < n; ++i) {
            if ((1 << i) & mask) {
                sumTmp += g_projScore[i];
            }
        }
        g_sumScore.insert(sumTmp);
    }

    int flag = 0;
    for (int i : g_sumScore) {
        printf((flag < 1 ? "%d" : " %d"), i);
        flag = 1;
    }

    return 0;
}
