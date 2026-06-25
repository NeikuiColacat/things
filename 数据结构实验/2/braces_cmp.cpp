#include <bits/stdc++.h>
using namespace std;
template <typename T> struct stk2 {
    vector<T> arr;

    int empty() {
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

template<typename stk > void  solve() {
    string s;cin >> s;
    stk a;
    int n = s.size();

    map<char, char > mp;

    mp['('] = ')', mp['['] = ']', mp['{'] = mp['}'];
    
    auto chk = [&](char x) {
        for (auto I : mp) {
            if (x == I.second) return 2;
            if (x == I.first) return 1;
        }
        return 0;
    };

    for (int i = 0;i < n;i++) {
        int res = chk(s[i]);
        if (!res) continue;
        if (res == 1) a.push(s[i]);
        else {
            if (a.empty() || mp[a.top()] != s[i]) {
                cout << "NO" << endl;
                return;
            }
            a.pop();
        }
    }

    cout << "YES" << endl;
}

int main() {
    solve<stk2<char>>();
    return  0;
}
