#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Dfs(const vector<int>& nums, int k, int start, vector<int>& path)
{
    if (path.size() == k) {
        for (int i = 0; i < k; i++) {
            if (i > 0) cout << " ";
            cout << path[i];
        }
        cout << endl;
        return;
    }
    
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1]) {  // 跳过重复元素
            continue;
        }
        path.push_back(nums[i]);
        Dfs(nums, k, i + 1, path);
        path.pop_back();
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end()); // 确保升序
    vector<int> path;
    Dfs(nums, k, 0, path);
    return 0;
}
