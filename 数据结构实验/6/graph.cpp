#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int INF = 1e9;
int g[N][N];
using P = pair<int, int>;
#define x first
#define y second
void solve() {
    int n;cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> g[i][j];
        }
    }

    vector<int> dis(n + 1, INF);
    auto dijkstra = [&](int st) {
        priority_queue < P, vector<P>, greater<P>> q;
        vector<int> s(n + 1);
        q.push({ 0,st });
        dis[st] = 0;
        while (q.size()) {
            int t = q.top().y; q.pop();
            if (s[t]) continue;
            s[t] = 1;

            for (int i = 1;i <= n;i++) {
                if (i == t) continue;
                if (dis[i] > dis[t] + g[t][i]) {
                    dis[i] = dis[t] + g[t][i];
                    q.push({ dis[i],i });
                }
            }
        }
    };

    int st, ed;cin >> st >> ed;
    dijkstra(st);
    cout << dis[ed] << endl;
}
void guide() {
    map<string,int> mp;
    map<int, string> name;

    int idx = 1;
    cout << "input the number of sights and number of roads" << endl;
    int n,m;cin >> n>>m;
    vector<vector<P>> g(n + 1);
    cout << "input the roads , each road defined by two sights , and the distance between them" << endl;
    for (int i = 1;i <= m;i++) {
        int u, v, w;
        string U, V; 
        cin >> U >> V >> w;
        if (!mp.count(U)) mp[U] = idx++;
        if (!mp.count(V)) mp[V] = idx++;
        u = mp[U], v = mp[V];
        name[u] = U, name[v] = V;
        g[u].push_back({ v,w }), g[v].push_back({ u,w });
    }
    
    const int INF = 1e9;
    vector<int> fa(n + 1), dis(n + 1,INF );
    cout << "input the loacation where you start , and where you end" << endl;
    string St, Ed;cin >> St >> Ed;
    int st = mp[St], ed = mp[Ed];

    auto dijkstra = [&](int st) {
        dis[st] = 0;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({ 0,st });
        vector<int> s(n + 1);
        while (q.size()) {
            int t = q.top().y;q.pop();
            if (s[t]) continue;
            s[t] = 1;

            for (auto i : g[t]) {
                int j = i.x, w = i.y;
                if (dis[j] > dis[t] + w) {
                    dis[j] = dis[t] + w;
                    q.push({ dis[j],j });
                    fa[j] = t;
                }
            }
        }
    };

    dijkstra(st);
    vector<int> route;
    cout << "distance:" << dis[ed] << endl;
    while (ed != st) route.push_back(ed), ed = fa[ed];
    route.push_back(st);
    for (auto i = route.rbegin();i != route.rend();i++) {
        cout << name[*i] << endl;
    }
}
int main() {
    guide();
    return 0;
}