#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {
    char c;
    int depth;
    vector<int> nxt;
    Node(char c='$', int depth=0) : c(c), depth(depth) {
        nxt = vector<int>(27, -1);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    string T;
    cin >> T;

    int N;
    cin >> N;

    vector<Node> trie(1);

    auto add = [&](string &s) {
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
            int c = s[i] - 'a';
            if(trie[cur].nxt[c] == -1){
                trie[cur].nxt[c] = trie.size();
                trie.push_back(Node(s[i], i+1));
            }
            cur = trie[cur].nxt[c];
        }
    };

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        s += 'z' + 1;
        add(s);
    }

    T = '$' + T;

    ll mod = 1e9 + 7;

    vector<ll> dp(T.size(), 0);
    dp[0] = 1;

    for(int i = 1; i < T.size(); i++){
        int cur = 0;
        for(int j = i; j < T.size(); j++){
            int c = T[j] - 'a';
            if(trie[cur].nxt[c] == -1) break;
            cur = trie[cur].nxt[c];
            if(trie[cur].nxt[26] != -1){
                dp[j] = (dp[j] + dp[i-1]) % mod;
            }
        }
    }

    cout << dp[T.size()-1] << '\n';

    return 0;
}