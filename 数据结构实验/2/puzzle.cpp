#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define x first
#define y second
template <typename stk > void solve() {
    int n, m;cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> g[i][j];
        }
    }

    int dx[] = { 1 , 1 , 1 , 0 ,  0 , -1 , -1, -1 };
    int dy[] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 };
    
    stk a;
    a.push({ 1,1 });
    map<P, P > ans;
    set<P> vis;
    vis.insert({ 1,1 });

    int ok = 0;
    while (a.size()) {
        P t = a.top();

        a.pop();

        if (ok) break;

        for (int i = 0;i < 8;i++) {
            int u = dx[i] + t.x, v = dy[i] + t.y;
            
            if (u >= 1 && u <= n && v >= 1 && v <= m && !g[u][v] && !vis.count({u,v})) {
                a.push({ u,v });
                ans[{u, v}] = t;
                vis.insert({ u,v });
                
                ok |= u == n && v == m;
            }

        }
    }

    if (!ok) cout << "NO WAY" << endl;
    else {
        vector<P> route;
        route.push_back({ n,m });
        while (route.back().x!= 1 || route.back().y!=  1) route.push_back(ans[route.back()]);

        reverse(route.begin(), route.end());
        for (P I : route) cout << I.x << " " << I.y << endl;
    }

}
int main() {
    solve<stack<P>>();
    return 0;
}