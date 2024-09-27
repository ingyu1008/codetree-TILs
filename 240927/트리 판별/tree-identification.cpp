#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> par(10101);
    iota(par.begin(), par.end(), 0);

    function<int(int)> find = [&](int u){
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    };

    auto unite = [&](int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return false;

        par[u] = v;
        return true;
    };

    int M;
    cin >> M;

    stack<int> st;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        if(!unite(a, b)){
            cout << "0\n";
            return 0;
        }

        st.push(a);
        st.push(b);
    }

    int root = find(st.top());

    while(!st.empty()){
        int cur = st.top();
        st.pop();

        if(root != find(cur)){
            cout << "0\n";
            return 0;
        }
    }

    cout << "1\n";

    return 0;
}