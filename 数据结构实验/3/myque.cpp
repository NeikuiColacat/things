#include <bits/stdc++.h>
using namespace std;
template <typename T> struct q1 {
    struct node {
        T val;
        node* ne;
    };

    node* h = nullptr, t = nullptr;

    int empty() {
        return h == nullptr;
    }

    void push(T val) {
        node* nn = new node;
        nn->val = val;
        nn->ne = nullptr;
        if (t) {
            t->ne = nn;
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
    }
};
template <typename T > struct q2 {
    const int N = 1e5 + 10;
    vector<T> q;
    q2() { q.resize(N); }
    
    int mod;

    int h = -1, t = -1;
    int empty() {
        return h == -1;
    }

    void push(T val) {
        if (h == -1) {
            h = t = 0;
            q[h] = val;
        }
        else if((t - h + 1 + mod) % mod){
            q[++t] = h;
        }
    }

    void pop_front() {
        if ((h - t) % mod == 0) h = t = -1;
        else if (!empty()) h++;
    }

    T front() {
        if (!empty()) return q[h];
        return -1;
    }
};

int main() {
    q2<int> myque;
    myque.push(1);
    cout << myque.front() << endl;
    myque.pop_front();
    cout << myque.front() << endl;
    return 0;
}