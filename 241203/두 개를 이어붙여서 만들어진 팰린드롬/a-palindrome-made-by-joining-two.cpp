#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node {
    int nxt[26];
    bool isTerminal;
    string word;
    Node() {
        for(int i = 0; i < 26; i++){
            nxt[i] = -1;
        }
        isTerminal = false;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio();
    
    int N;
    cin >> N;

    vector<Node> trie(1);
    vector<Node> revTrie(1);

    auto add = [&](string &s){
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
            int c = s[i] - 'a';
            if(trie[cur].nxt[c] == -1){
                trie[cur].nxt[c] = trie.size();
                trie.emplace_back();
            }
            cur = trie[cur].nxt[c];
        }

        trie[cur].isTerminal = true;
        trie[cur].word = s;

        int revcur = 0;
        for(int i = s.size() -1; i >= 0; i--){
            int c = s[i] - 'a';
            if(revTrie[revcur].nxt[c] == -1){
                revTrie[revcur].nxt[c] = revTrie.size();
                revTrie.emplace_back();
            }
            revcur = revTrie[revcur].nxt[c];
        }

        revTrie[revcur].isTerminal = true;
        revTrie[revcur].word = s;
    };

    vector<string> S(N);

    for(int i = 0; i < N; i++){
        cin >> S[i];
        add(S[i]);
    }

    auto checkPalindrome = [](string &s, int idx, bool rev = false) -> bool {
        int l = idx;
        int r = s.size() - 1;


        if(rev){
            l = 0;
            r = idx;
        }
        
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    };

    int ans = 0;

    for(int i = 0; i < N; i++){
        int cur = 0;
        int mat = 0;
        
        for(int j = 0; j < S[i].size(); j++){
            int c = S[i][j] - 'a';
            if(revTrie[cur].nxt[c] == -1){
                break;
            }
            cur = revTrie[cur].nxt[c];
            mat++;
            if(revTrie[cur].isTerminal && checkPalindrome(S[i], j+1) && S[i] != revTrie[cur].word){
                ans = max(ans, mat + (int)(S[i].size()));
            }
        }

        cur = 0;
        mat = 0;
        for(int j = 0; j < S[i].size(); j++){
            int c = S[i][S[i].size() - 1 - j] - 'a';
            if(trie[cur].nxt[c] == -1){
                break;
            }

            cur = trie[cur].nxt[c];
            mat++;
            if(trie[cur].isTerminal && checkPalindrome(S[i], S[i].size() - 1 - j, true) && S[i] != trie[cur].word){
                ans = max(ans, mat + (int)(S[i].size()));
            }
        }
        
    }

    cout << ans << '\n';

    return 0;
}