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

    string s;cin >> s;
    s = ' ' + s;
    int n = s.size();

    auto build = [&]() {
        np root = init();
        queue<np> q;q.push(root);

        int idx = 2;
        while (idx <= n) {
            np t = q.front();
            q.pop();
            t->lchild = init();
            t->lchild->info = s[idx++];
            t->rchild = init();
            t->rchild->info = s[idx++];
            q.push(t->lchild), q.push(t->rchild);
        }

        return root;
    };

    return build();
}
signed main() {
    solve();
}