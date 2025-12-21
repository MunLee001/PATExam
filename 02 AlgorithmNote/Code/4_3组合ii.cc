#include<cstdio>
#include<vector>
using namespace std;

vector<int> g_input;
vector<int> g_tempResult;
int g_n = 0, g_k = 0;

static void GetCombinationK(int start)
{
    // 打印
    if (g_tempResult.size() == g_k) {
        for (int i = 0; i < g_k - 1; ++i) {
            printf("%d ", g_tempResult[i]);
        }
        printf("%d\n", g_tempResult[g_k - 1]);
        return;
    }
    
    if (start >= g_n) {
        return;
    }

    g_tempResult.push_back(g_input[start]);
    GetCombinationK(start + 1);
    g_tempResult.pop_back();
    GetCombinationK(start + 1);
}

int main(void)
{
    // 输入
    scanf("%d %d", &g_n, &g_k);
    for (int i = 0; i < g_n; ++i) {
        g_input.push_back(0);
        scanf("%d", &g_input[i]);
    }

    // 排列输出
    GetCombinationK(0);

    return 0;
}
