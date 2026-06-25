#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int> 
#define x first
#define y second
struct node {
    int ex, co;
    node* ne;
};
node* build(vector<pii> a) {
    node* h = new node;
    h->ne = nullptr;
    int n = a.size();
    for (int i = 0;i < n;i++) {
        node* nn = new node;
        nn->ex = a[i].x, nn->co = a[i].y;
        nn->ne = h->ne;
        h->ne = nn;
    }

    return h;
}
node* op(node* a, node* b , int mode) {
    node* hh = new node;
    hh->ne = nullptr;
    if (mode) {
        node* p = b->ne;
        while (p) {
            p->co = -p->co;
            p = p->ne;
        }
    }

    a = a->ne, b = b->ne;

    auto give = [&](node* nn, node* a) {
        nn->co = a->co, nn->ex = a->ex;
    };

    auto push = [&](node* nn) {
        nn->ne = hh->ne;
        hh->ne = nn;
    };

    while (a || b) {
        node* nn = new node;
        if (!a) while (b) {
            give(nn, b);
            push(nn);
            b = b->ne;
        }
        else if (!b) while (a) {
            give(nn, a);
            push(nn);
            a = a->ne;
        }
        else if (a->ex < b->ex) {
            give(nn, b);
            push(nn);
            b = b->ne;
        }
        else if (b->ex < a->ex) {
            give(nn, a);
            push(nn);
            a = a->ne;
        }
        else {
            give(nn, a);
            nn->co += b->co;
            if(nn->co)push(nn);
            a = a->ne, b = b->ne;
        }
    }
    return hh;
}
void solve() {
    int n, m;cin >> n >> m;
    vector<pii> a(n), b(m);
    for (int i = 0;i < n;i++) cin >> a[i].y >> a[i].x;
    for (int i = 0;i < m;i++) cin >> b[i].y >> b[i].x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    auto out = [&](node *  h) {
        h = h->ne;
        while (h) {
            cout << (h->co > 0 ? '+' : '-');
            cout << h->co << "x" << "^" << h->ex <<" ";
            h = h->ne;
        }
    };

    node* A = build(a), * B = build(b);
    out(op(A, B, 0));
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}