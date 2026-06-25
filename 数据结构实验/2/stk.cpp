#include <bits/stdc++.h>
using namespace std;

template <typename T> struct stk {
    struct node {
        T val;
        node* ne;
    };
    
    node* h = nullptr;
    int isnull() { return h == nullptr;}

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
        if (isnull()) return -1;
        return h->val;
    }
};

template <typename T> struct stk2 {
    vector<T> arr;

    int isnull() {
        return (int)arr.size() == 0;
    }
    void push(T val) {
        arr.push_back(val);
    }
    void pop() {
        if (arr.size()) arr.pop_back();
    }
    T top() {
        if (arr.size()) return arr.back();
        else return -1;
    }
};
int main() {
    stk<int> mstk;
    int n;cin >> n;
    for (int i = 1;i <= n;i++) mstk.push(i);
    cout << mstk.top() << endl;

    
    stk2<int> mstk2;
    for (int i = 1;i <= n;i++) mstk2.push(i);
    cout << mstk2.top() << endl;
    return 0;
}