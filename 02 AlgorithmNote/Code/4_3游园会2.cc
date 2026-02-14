#include <cstdio>
#include <set>
using namespace std;

#define MAX_N (12 + 1)

int n = 0;
int g_score[MAX_N] = {0};
set<int> g_resultScore;

void DfsScore(int tempScore, int idx)
{
    if (idx == n) {  // 完成所有项目的搜索
        g_resultScore.insert(tempScore);
        return;
    }

    // 第idx项目获得得分
    DfsScore(tempScore + g_score[idx], idx + 1);

    // 第idx项目没有获得得分
    DfsScore(tempScore + 0, idx + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &g_score[i]);
    }

    DfsScore(0, 0);

    // 打印所有情况啊
    int flag = 0;
    for (int i : g_resultScore) {
        printf((flag < 1 ? "%d" : " %d"), i);
        flag = 1;
    }

    return 0;
}
