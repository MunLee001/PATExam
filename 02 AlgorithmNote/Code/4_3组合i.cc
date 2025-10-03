#include<cstdio>
#include<vector>
using namespace std;

int g_n = 0, g_k = 0;
vector<int> g_resultTemp;

static void GetCombinationK(int start)
{
    if (g_resultTemp.size() == g_k) {
        for (int i = 0; i < g_k - 1; ++i) {
            printf("%d ", g_resultTemp[i]);
        }
        printf("%d\n", g_resultTemp[g_k - 1]);
        return;
    }

    if (start > g_n) {
        return;
    }

    g_resultTemp.push_back(start);
    GetCombinationK(start + 1);
    g_resultTemp.pop_back();
    GetCombinationK(start + 1);
}

int main()
{
    scanf("%d %d", &g_n, &g_k);
    GetCombinationK(1);
    return 0;
}
