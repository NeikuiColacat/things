#include <bits/stdc++.h>
using namespace std;
struct T{
    T* l , *r;
    int val;
};
struct cmp{
    bool operator()(T* a , T*b){
        return a->val > b->val;
    }
};
T* root;
T* build(vector<int> a){
    priority_queue<T*,vector<T*> , cmp> q;
    auto give = [&](int val){
        T* t = new T;
        t->val = val;
        t->l = t-> r  = nullptr; 
        return t;
    };

    for(int i : a){
        T* t = give(i);
        q.push(t);
    }

    while((int)q.size() > 1 ){
        T* x = q.top() ; q.pop();
        T* y = q.top() ; q.pop();

        T* t = give(x->val + y-> val);
        t->l = x , t->r = y;
        q.push(t);         
    }

    return q.top();
}
int decode(string s){
    int n = s.size();
    T* tmp = root;
    for(int i = 0;i<n;i++){
        if(s[i] == '0') tmp = root->l;
        else tmp = root->r;
        if(i == n-1) return tmp->val; 
    }

    return - 1;
}
string code(int val){
    string ans;

    int fl = 0;
    function<void(T*)> dfs = [&](T* u){
        if(!u->l && !u->r && u->val == val) fl = 1;
        if(!u->l && !u->r) return;

        ans.push_back('0') , dfs(u->l);
        if(fl) return;
        ans.pop_back();

        ans.push_back('1');
        dfs(u->r);  
        if(fl) return;
        ans.pop_back();
    }; 

    dfs(root);
    return ans;
}
int main(){
    vector<int> a = {1 , 2 , 3} ;
    root = build(a);

    cout << code(3) << endl;
    cout << decode("0") << endl;
    return 0 ;
}