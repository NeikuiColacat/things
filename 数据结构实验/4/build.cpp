#include <bits/stdc++.h>
using namespace std;
struct node {
    char info;
    node* lchild;
    node* rchild;
};
using np = node*;
np solve() {
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
signed main() {
    solve();
}