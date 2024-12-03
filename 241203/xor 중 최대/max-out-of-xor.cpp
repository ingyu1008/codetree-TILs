#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {
    vector<int> nxt;
    Node() {
        nxt = vector<int>(2, -1);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<Node> trie(1);

    auto add = [&](int x){
        int cur = 0;
        for(int i = 30; i >= 0; i--){
            int bit = (x >> i) & 1;
            if(trie[cur].nxt[bit] == -1){
                trie[cur].nxt[bit] = trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].nxt[bit];
        }
    };

    ll mx = 0;

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;

        add(x);

        int cur = 0;
        ll val = 0;
        // for(int j = 30; j >= 0; j--){
        //     int bit = (x >> j) & 1;
        //     if(trie[cur].nxt[bit ^ 1] != -1){
        //         val += (1LL << j);
        //         cur = trie[cur].nxt[bit ^ 1];
        //     } else if(trie[cur].nxt[bit] != -1){
        //         cur = trie[cur].nxt[bit];
        //     } else {
        //         break;
        //     }
        // }
        mx = max(mx, val);

    }

    cout << mx << '\n';

    return 0;
}