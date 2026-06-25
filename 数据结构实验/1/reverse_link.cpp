#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int> 
#define x first
#define y second
struct node {
    int val;
    node* ne;
};
node* solve1(node * head) {
    node* newh = new node;
    newh->ne = nullptr;
    node* p = head->ne;
    while (p) {
        node *nn = new node;
        nn->val = p->val;
        nn->ne = newh->ne;
        newh->ne = nn;
        p = p->ne;
    }
    return newh;
}
void solve2(node* head) {
    if (!(head->ne) || !(head->ne->ne)) return;

    node* cur = head->ne->ne;
    node* pre = head->ne;
    pre->ne = nullptr;

    while (cur) {
        node* t = cur->ne;
        cur->ne = pre;
        pre = cur;
        cur = t;
    }

    head->ne = pre;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    reverse(a.begin(), a.end());

    auto build = [&]() {
        node* h = new node;
        h->ne = nullptr;

        for (int i = 0;i < n;i++) {
            node* nn = new node;
            nn->val = a[i];
            nn->ne = h->ne;
            h->ne = nn;
        }
        return h;
    };

    auto out = [&](node *  h) {
        h = h->ne;
        while (h) {
            cout << h->val << " ";
            h = h->ne;
        }
        cout << endl;
    };

    node* h = build();
    
    node* t = solve1(h);
    out(t);
    solve2(h);
    out(h);
    return 0;
}