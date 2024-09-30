#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> E(26, {-1, -1});

    for(int i = 0; i < N; i++){
        string n, l, r;
        cin >> n >> l >> r;
        if(l != ".") E[n[0]-'A'].first = l[0] - 'A';
        if(r != ".") E[n[0]-'A'].second = r[0] - 'A';
    }

    function<void(int, int)> dfs1 = [&](int cur, int par){
        if(E[cur].first >= 0) dfs1(E[cur].first, cur);
        string s = "A";
        s[0] += cur;
        cout << (s);
        if(E[cur].second >= 0) dfs1(E[cur].second, cur);
    };

    function<void(int, int)> dfs2 = [&](int cur, int par){
        string s = "A";
        s[0] += cur;
        cout << (s);
        if(E[cur].first >= 0) dfs2(E[cur].first, cur);
        if(E[cur].second >= 0) dfs2(E[cur].second, cur);
    };

    function<void(int, int)> dfs3 = [&](int cur, int par){
        if(E[cur].first >= 0) dfs3(E[cur].first, cur);
        if(E[cur].second >= 0) dfs3(E[cur].second, cur);
        string s = "A";
        s[0] += cur;
        cout << (s);
    };

    dfs2(0, -1);
    cout << "\n";
    dfs1(0, -1);
    cout << "\n";
    dfs3(0, -1);
    cout << "\n";
    



    return 0;
}