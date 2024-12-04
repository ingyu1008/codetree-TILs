#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio();

    function<ll(ll, ll, ll)> pow = [&](ll a, ll b, ll mod) -> ll {
        ll res = 1;
        while (b > 0)
        {
            if (b & 1)
            {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    };
    
    int N;
    cin >> N;

    vector<string> S(N);

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    vector<ll> p = {31, 37};
    vector<ll> mod = {1000000007, 1000000009};

    set<pair<ll, ll>> hashSet, revHashSet;

    for (int i = 0; i < N; i++)
    {
        int sz = S[i].size();

        ll h1 = S[i][0] - 'a' + 1;
        ll h2 = S[i][0] - 'a' + 1;

        ll sh1 = S[i][sz - 1] - 'a' + 1;
        ll sh2 = S[i][sz - 1] - 'a' + 1;

        for (int j = 1; j < sz; j++)
        {
            h1 = (h1 * p[0] + S[i][j] - 'a' + 1) % mod[0];
            h2 = (h2 * p[1] + S[i][j] - 'a' + 1) % mod[1];
            
            sh1 = (sh1 * p[0] + S[i][sz - j - 1] - 'a' + 1) % mod[0];
            sh2 = (sh2 * p[1] + S[i][sz- j - 1] - 'a' + 1) % mod[1];
        }

        hashSet.insert({h1, h2});
        revHashSet.insert({sh1, sh2});
    }
    
    int ans = 0;

    for(int i = 0; i < N; i++)
    {
        int sz = S[i].size();
        
        for(int j = 0; j < sz; j++){
            int l = 0;
            int r = j;

            bool isPal = true;

            while(l < r){
                if(S[i][l] != S[i][r]){
                    isPal = false;
                    break;
                }
                l++; r--;
            }

            if(!isPal) continue;

            pair<ll, ll> h = {0, 0};
            
            for(int k = j+1; k < sz; k++){
                h.first = (h.first * p[0] + S[i][k] - 'a' + 1) % mod[0];
                h.second = (h.second * p[1] + S[i][k] - 'a' + 1) % mod[1];
            }

            if(revHashSet.find(h) != revHashSet.end()){
                ans = max(ans, sz + (sz - j - 1));
            }
        }

        for(int j = sz-1; j >=0; j --){
            int l = j;
            int r = sz-1;

            bool isPal = true;

            while(l < r){
                if(S[i][l] != S[i][r]){
                    isPal = false;
                    break;
                }
                l++; r--;
            }

            if(!isPal) continue;
            
            pair<ll, ll> h = {0, 0};

            for(int k = j-1; k >= 0; k--){
                h.first = (h.first * p[0] + S[i][k] - 'a' + 1) % mod[0];
                h.second = (h.second * p[1] + S[i][k] - 'a' + 1) % mod[1];
            }

            if(hashSet.find(h) != hashSet.end()){
                ans = max(ans, sz + (j));
            }
        }
    }

    cout << ans << endl;

    return 0;
}