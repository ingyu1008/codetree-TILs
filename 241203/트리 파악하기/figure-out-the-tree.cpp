#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {
    string s;
    int depth;
    vector<int> nxt;
    map<string, int> mp;
    Node(string s = "$", int depth = 0) : s(s), depth(depth) {}
};

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N;
    cin >> N;

    vector<Node> trie(1);

    auto add = [&](vector<string> &s) {
        int cur = 0;
        for (string &ss : s) {
            if (trie[cur].mp.find(ss) == trie[cur].mp.end()) {
                trie[cur].mp[ss] = trie[cur].nxt.size();
                trie[cur].nxt.push_back(trie.size());
                trie.push_back(Node(ss, trie[cur].depth + 1));
            }
            cur = trie[cur].nxt[trie[cur].mp[ss]];
        }
    };
    
    for(int i = 0; i < N; i++){
        int M;
        cin >> M;
        vector<string> s(M);
        for(int j = 0; j < M; j++){
            cin >> s[j];
        }
        add(s);
    }

    function<void(int)> print = [&](int cur) {
        if(trie[cur].depth > 0){
            for(int i = 1; i < trie[cur].depth; i++){
                cout << "--";
            }
            cout << trie[cur].s << '\n';
        }

        for(auto &[s, idx]: trie[cur].mp){
            print(trie[cur].nxt[idx]);
        }
    };

    print(0);

    return 0;
}