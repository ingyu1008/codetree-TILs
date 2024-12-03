#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {
    char c;
    int depth;
    int cnt;
    vector<int> nxt;
    int numchild;
    Node(char c = '$', int depth = 0) : c(c), depth(depth), cnt(0), numchild(0) {
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
            if (trie[cur].nxt[c - 'a'] == -1) {
                trie[cur].nxt[c - 'a'] = trie.size();
                trie.emplace_back(c, trie[cur].depth + 1);
                trie[cur].numchild++;
            }
            cur = trie[cur].nxt[c - 'a'];
            trie[cur].cnt++;
        }
    };
    
    vector<string> S(N);
    
    for(int i = 0; i < N; i++){
        cin >> S[i];
        add(S[i]);
    }

    for(int i = 0; i < N; i++){
        int sz = S[i].size();
        int cur = 0;
        int ans = 0;
        for(int j = 0; j < sz; j++){
            if(trie[cur].numchild > 1 || cur == 0){
                ans++;
            }
            cur = trie[cur].nxt[S[i][j] - 'a'];
        }
        cout << ans << ' ';
    }
    
    

    return 0;
}

/*
5
dkpwscm gqpmxincm xkmfcnnwlnxfjjj prgoearasyt
dkpwscm gqpmxincm xkmfcnnwlnxfjjj abfse
dkpwscm gqpmxincm mjavxzzrqgfgivxsllqjyerw
dkpwscm gqpmxincm mjavxnwdwlonui
dkpwscm hsivrcbrbhjxvlf

*/