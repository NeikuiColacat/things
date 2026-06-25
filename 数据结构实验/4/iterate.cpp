#include <bits/stdc++.h>
using namespace std;
struct node {
    char info;
    node* lchild;
    node* rchild;
};
using np = node*;
np build() {
    auto init = [&]() {
        np res = new node;
        res->lchild = res->rchild = nullptr;
        return res;
    };

    np root = init();

    string s;cin >> s;
    s = ' ' + s;
    int n = s.size();

    int idx = 1;
    auto build = [&](np u, auto self) ->void {
        u->info = s[idx];
        idx++;
        if (idx <= n && s[idx] != '#') {
            np& L = u->lchild;
            L = init();
            L->info = s[idx];
            self(L, self);
        }
        idx++;
        if (idx <= n && s[idx] != '#') {
            np& R = u->rchild;
            R = init();
            R->info = s[idx];
            self(R, self);
        }
    };

    build(root, build);
    return root;
}
void solve1(np u) {
    if (!u) return;
    cout << u->info << " ";
    solve1(u->lchild);
    solve1(u->rchild);
}
void solve2(np u) {
    if (!u) return;
    solve1(u->lchild);
    cout << u->info << " ";

    solve2(u->rchild);
}
void solve3(np u) {
    if (!u) return;
    solve1(u->lchild);
    solve2(u->rchild);
    cout << u->info << " ";


}
void bfs(np u) {
    queue<np> q;
    q.push(u);
    while (q.size()) {
        np t = q.front();
        q.pop();
        cout << t->info << " ";

        if (t->lchild) q.push(t->lchild);
        if (t->rchild)q.push(t->rchild);
    }
}
signed main() {
    np root = build();
    solve1(root);
    cout << endl;
    solve2(root);
    cout << endl;
    solve3(root);
    cout << endl;
    bfs(root);
    cout << endl;
    return 0;
}