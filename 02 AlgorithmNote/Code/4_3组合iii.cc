#include<cstdio>
#include<vector>
using namespace std;

vector<int> g_tempResult;
vector<vector<int>> g_Result;
vector<int> g_input;
int g_n = 0, g_k = 0;

// 判断是否已经存在该组合
static bool IsResult(void)
{
    bool tmpBool = true;
    for (int i = 0; i < g_Result.size(); ++i) {
        for (int j = 0; j < g_k; ++j) {
            if (g_tempResult[j] == g_Result[i][j]) {
                tmpBool = true;
            } else {
                tmpBool = false;
                break;
            }
        }
        if (tmpBool == true) {
            return false;
        }
    }
    return true;
}

// 深度优先搜索可能存在的组合
static void GetCombinationK(int start)
{
    if (g_tempResult.size() == g_k) {
        if (IsResult() == true) {
            for (int i = 0; i < g_k - 1; ++i) {
                printf("%d ", g_tempResult[i]);
            }
            printf("%d\n", g_tempResult[g_k - 1]);
            g_Result.push_back(g_tempResult);
        }
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
    scanf("%d %d", &g_n, &g_k);
    for (int i = 0; i < g_n; ++i) {
        g_input.push_back(0);
        scanf("%d", &g_input[i]);
    }
    GetCombinationK(0);
    return 0;
}
