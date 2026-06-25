#include <bits/stdc++.h>
using namespace std;
int solve1(vector<int> a, int val) {
    int n = a.size();
    vector<int> tmp;
    for (int i = 0;i < n;i++) {
        if (a[i] == val) continue;
        tmp.push_back(a[i]);
    }

    return tmp.size();
}
int solve2(vector<int> a, int val) {
    int n = a.size();
    int cnt = 0;
    for (int i = 0;i < n - cnt;i++) {
        if(a[i] == val) {
            for (int j = i;j < n - cnt-1;j++) a[j] = a[j + 1];
            cnt++;
            i--;
        }
    }

    return n - cnt;
}
int solve3(vector<int> a, int val) {
    int n = a.size();
    int cnt = 0;
    for (int i = 0,j = 0;j < n;j++) {
        while (j < n && a[j] == val) j++,cnt++;
        a[i++] = a[j];
    }
    return n - cnt;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> a = { 0,1,2,2,3,0,4,2 };
    cout << solve1(a, 2) << endl;
    cout << solve2(a, 2) << endl;
    cout << solve3(a, 2) << endl;
    return 0;
}