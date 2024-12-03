#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {
    char c;
    int depth;
    vector<int> nxt;
    Node(char c = '$', int depth = 0) : c(c), depth(depth) {
        nxt = vector<int>(26, -1);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N;
    cin >> N;

    vector<Node> trie(1);

    auto add = [&](string &s) {
        int cur = 0;
        for (char c : s) {
            if (trie[cur].nxt[c - 'A'] == -1) {
                trie[cur].nxt[c - 'A'] = trie.size();
                trie.emplace_back(c, trie[cur].depth + 1);
            }
            cur = trie[cur].nxt[c - 'A'];
        }
    };
    
    for(int i = 0; i < N; i++){
        int M;
        cin >> M;
        string s;
        for(int j = 0; j < M; j++){
            string t;
            cin >> t;
            s += t;
        }
        add(s);
    }

    function<void(int)> print = [&](int cur) {
        if(trie[cur].depth > 0){
            for(int i = 1; i < trie[cur].depth; i++){
                cout << "--";
            }
            cout << trie[cur].c << '\n';
        }
        for (int i = 0; i < 26; i++) {
            if (trie[cur].nxt[i] != -1) {
                print(trie[cur].nxt[i]);
            }
        }
    };

    print(0);

    return 0;
}