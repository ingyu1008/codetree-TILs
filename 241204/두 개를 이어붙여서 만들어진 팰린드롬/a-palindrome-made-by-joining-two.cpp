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

    vector<vector<pair<ll, ll>>> prefixHash(N, vector<pair<ll, ll>>(N, {0, 0}));
    vector<vector<pair<ll, ll>>> suffixHash(N, vector<pair<ll, ll>>(N, {0, 0}));

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

        prefixHash[i][0] = {h1, h2};
        suffixHash[i][sz - 1] = {sh1, sh2};

        for (int j = 1; j < sz; j++)
        {
            h1 = (h1 * p[0] + S[i][j] - 'a' + 1) % mod[0];
            h2 = (h2 * p[1] + S[i][j] - 'a' + 1) % mod[1];
            
            sh1 = (sh1 * p[0] + S[i][sz - j - 1] - 'a' + 1) % mod[0];
            sh2 = (sh2 * p[1] + S[i][sz- j - 1] - 'a' + 1) % mod[1];

            prefixHash[i][j] = {h1, h2};
            suffixHash[i][sz - j - 1] = {sh1, sh2};
        }

        hashSet.insert(prefixHash[i][sz - 1]);
        revHashSet.insert(suffixHash[i][0]);

        // cout << "i: " << i << ", forward hash: " << prefixHash[i][sz-1].first << " " << prefixHash[i][sz-1].second << endl;
        // cout << "i: " << i << ", reverse hash: " << suffixHash[i][0].first << " " << suffixHash[i][0].second << endl;
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

            pair<ll, ll> h = prefixHash[i][N-1];
            ll pn = pow(p[0], (sz-1) - j, mod[0]);
            ll pn2 = pow(p[1], (sz-1) - j, mod[1]);
            h.first = ((h.first - pn*prefixHash[i][j].first)%mod[0] + mod[0])%mod[0];
            h.second = ((h.second - pn2*prefixHash[i][j].second)%mod[1] + mod[1])%mod[1];

            // cout << "i: " << i << ", j: "<< j << ", h: " << h.first << " " << h.second << endl;

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

            pair<ll, ll> h = suffixHash[i][0];
            ll pn = pow(p[0], j, mod[0]);
            ll pn2 = pow(p[1], j, mod[1]);
            h.first = ((h.first - pn*suffixHash[i][j].first)%mod[0] + mod[0])%mod[0];
            h.second = ((h.second - pn2*suffixHash[i][j].second)%mod[1] + mod[1])%mod[1];

            if(hashSet.find(h) != hashSet.end()){
                ans = max(ans, sz + (j));
            }
        }
    }

    cout << ans << endl;

    return 0;
}