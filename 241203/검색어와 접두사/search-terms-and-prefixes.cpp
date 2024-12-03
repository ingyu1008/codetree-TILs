#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {
    char c;
    int depth;
    int cnt;
    vector<int> nxt;
    Node(char c = '$', int depth = 0) : c(c), depth(depth), cnt(0) {
        nxt = vector<int>(26, -1);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio();

    int N, M;
    cin >> N >> M;

    vector<Node> trie(1);

    auto add = [&](string &s) {
        int cur = 0;
        for (char c : s) {
            if (trie[cur].nxt[c - 'a'] == -1) {
                trie[cur].nxt[c - 'a'] = trie.size();
                trie.emplace_back(c, trie[cur].depth + 1);
            }
            cur = trie[cur].nxt[c - 'a'];
            trie[cur].cnt++;
        }
    };
    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        add(s);
    }

    string s;
    cin >> s;

    int cur = 0;
    for(int i = 0; i < M; i++){
        if(trie[cur].nxt[s[i] - 'a'] == -1){
            trie[cur].nxt[s[i] - 'a'] = trie.size();
            trie.emplace_back(s[i], trie[cur].depth + 1);
        }
        cur = trie[cur].nxt[s[i] - 'a'];
        cout << trie[cur].cnt << " ";
    }

    return 0;
}