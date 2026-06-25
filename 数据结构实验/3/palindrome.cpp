#include <bits/stdc++.h>
using namespace std;
template <typename T> struct stk {
    struct node {
        T val;
        node* ne;
    };
    
    node* h = nullptr;
    int empty() { return h == nullptr;}

    void pop() {
        node* tmp = h->ne;
        delete h;
        h = tmp;
    }
    void push(T val) {
        node* nn = new node;
        nn->val = val, nn->ne = h;
        h = nn;
    }
    T top() {
        if (empty()) return -1;
        return h->val;
    }
};
template <typename T> struct q1 {
    struct node {
        T val;
        node* ne;
    };

    node* h = nullptr, *t = nullptr;

    int empty() {
        return h == nullptr;
    }

    void push(T val) {
        node* nn = new node;
        nn->val = val;
        nn->ne = nullptr;
        if (t) {
            t->ne = nn;
            t = nn;
        }
        else {
            h = t = nn;
        }
    }

    void pop_front() {
        if (h) {
            node* t = h;
            h = h->ne;
            delete t;
        }
    }

    T front() {
        if (h) {
            return h->val;
        }
        return -1;
    }
};
template<typename stk, typename que> void solve() {
    string s;cin >> s;
    int n = s.size();
    stk A;
    que B;
    for (int i = 0;i < n;i++) {
        A.push(s[i]), B.push(s[i]);
    }
    
    while (!A.empty()) {
        char t1 = A.top(), t2 = B.front();
        A.pop(), B.pop_front();
        if (t1 != t2) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}
int main() {
    solve<stk<char>,q1<char>>();
    return 0;
}