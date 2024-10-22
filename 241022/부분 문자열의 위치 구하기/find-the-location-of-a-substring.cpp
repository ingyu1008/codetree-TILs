#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> MOD = {(ll)1e9+7, (ll)1e9 + 9};
vector<ll> PRIME = {31, 37};
vector<ll> POWP[2];

int main() {
    string T, P;
    cin >> T >> P;

    for(int i = 0; i < 2; i++){
        POWP[i].push_back(1);
        for(int j = 0; j < T.size(); j++){
            ll x = POWP[i].back();
            ll p = PRIME[i&1];
            ll m = MOD[i&1];
            POWP[i].push_back((x * p) % m);
        }
    } 

    vector<ll> hashP(2, 0);
    vector<ll> hashT(2, 0);
    for(int i = 0; i < 2; i++){
        for(int j = 0 ; j < P.size(); j++){
            ll valP = ((P[j] - 'a' + 1) * POWP[i][P.size() - 1 - j]) % MOD[i];
            hashP[i] = (hashP[i] + valP) % MOD[i];

            ll valT = ((T[j] - 'a' + 1) * POWP[i][P.size() - 1 - j]) % MOD[i];
            hashT[i] = (hashT[i] + valT) % MOD[i];
        }
    }

    if(hashP[0] == hashT[0] && hashP[1] == hashT[1]){
        cout << "0\n";
        return 0;
    }

    for(int j = P.size(); j < T.size(); j++){
        for(int i = 0; i < 2; i++){
            ll substract = ((T[j - P.size()] - 'a' + 1) * POWP[i][P.size() - 1]) % MOD[i];
            ll add = ((T[j] - 'a' + 1)) % MOD[i];
            hashT[i] = (hashT[i] - substract + MOD[i]) % MOD[i];
            hashT[i] = (hashT[i]*PRIME[i] + add)%MOD[i];
        }
        
        if(hashP[0] == hashT[0] && hashP[1] == hashT[1]){
            cout << j - P.size() + 1 << "\n";
            return 0;
        }
    }

    cout << "-1\n";

    

    return 0;
}