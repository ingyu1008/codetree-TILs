#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {
    vector<int> nxt;
    Node() {
        nxt = vector<int>(10, -1);
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
            if (trie[cur].nxt[c - '0'] == -1) {
                trie[cur].nxt[c - '0'] = trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].nxt[c - '0'];
        }
    };

    auto find = [&](string &s) {
        int cur = 0;
        for (char c : s) {
            if (trie[cur].nxt[c - '0'] == -1) {
                return false;
            }
            cur = trie[cur].nxt[c - '0'];
        }
        
        for(int i = 0; i < 10; i++) {
            if(trie[cur].nxt[i] != -1) {
                return true;
            }
        }

        return false;
    };

    vector<string> S(N);

    for (int i = 0; i < N; i++) {
        cin >> S[i];
        add(S[i]);
    }

    int ans = 1;

    for (int i = 0; i < N; i++) {
        if(find(S[i])) {
            ans = 0;
        }
    }

    cout << ans << '\n';

    return 0;
}