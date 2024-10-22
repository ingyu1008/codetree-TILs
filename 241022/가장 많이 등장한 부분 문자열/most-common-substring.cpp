#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> MOD = {(ll)1e9+7, (ll)1e9 + 9};
vector<ll> PRIME = {31, 37};
vector<ll> POWP[2];

int main() {
    ll l;
    string T;
    cin >> l >> T;

    for(int i = 0; i < 2; i++){
        POWP[i].push_back(1);
        for(int j = 0; j < T.size(); j++){
            ll x = POWP[i].back();
            ll p = PRIME[i&1];
            ll m = MOD[i&1];
            POWP[i].push_back((x * p) % m);
        }
    } 

    vector<ll> hashT(2, 0);
    for(int i = 0; i < 2; i++){
        for(int j = 0 ; j < l; j++){
            ll valT = ((T[j] - 'a' + 1) * POWP[i][l - 1 - j]) % MOD[i];
            hashT[i] = (hashT[i] + valT) % MOD[i];
        }
    }
    
    map<pair<ll, ll>, int> mp;
    mp[{hashT[0], hashT[1]}] = 1;

    for(int j = l; j < T.size(); j++){
        for(int i = 0; i < 2; i++){
            ll substract = ((T[j - l] - 'a' + 1) * POWP[i][l - 1]) % MOD[i];
            ll add = ((T[j] - 'a' + 1)) % MOD[i];
            hashT[i] = (hashT[i] - substract + MOD[i]) % MOD[i];
            hashT[i] = (hashT[i]*PRIME[i] + add)%MOD[i];
        }
        
        mp[{hashT[0], hashT[1]}] = mp[{hashT[0], hashT[1]}] + 1;
    }
    
    int ans = 0;

    for(auto &[k, v]: mp){
        ans = max(ans , v);
    }

    cout << ans << "\n";

    

    return 0;
}