// Link to question: https://codeforces.com/contest/781/problem/C


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> vis(200001, false);

void dfs(vector<vector<int>>& g, vector<int>& ans, int start) {
    vector<pair<int, int>> st;
    st.push_back({start, 0});
    vis[start] = true;
    ans.push_back(start);

    while (!st.empty()) {
        int u = st.back().first;
        int& idx = st.back().second;

        if (idx == (int)g[u].size()) {
            st.pop_back();

            if (!st.empty()) {
                ans.push_back(st.back().first);
            }
            continue;
        }

        int v = g[u][idx];
        idx++;

        if (!vis[v]) {
            vis[v] = true;
            ans.push_back(v);
            st.push_back({v, 0});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> g(n + 1);
    vector<int> ans;

    int l = (2 * n + k - 1) / k;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(g, ans, 1);

    int s = (int)ans.size();
    int pos = 0;

    for (int i = 0; i < k; i++) {
        int len = min(l, s - pos);

        if (len <= 0) {
            cout << "1 1\n";
            continue;
        }

        cout << len << " ";
        for (int j = 0; j < len; j++) {
            cout << ans[pos++] << " ";
        }
        cout << '\n';
    }

    return 0;
}
