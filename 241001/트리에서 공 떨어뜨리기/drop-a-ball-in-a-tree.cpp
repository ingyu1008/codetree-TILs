#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> E(N+1);

    for(int i = 1; i <= N; i++){
        cin >> E[i].first >> E[i].second;
    }

    int cur = 1;
    long long K;
    cin >> K;

    while(true){
        if(E[cur].first < 0 && E[cur].second < 0) break;
        if(E[cur].first >= 0 && E[cur].second >= 0){
            if(K&1) cur = E[cur].first;
            else cur = E[cur].second;
            K >>= 1;
            continue;
        }

        if(E[cur].first >= 0) cur = E[cur].first;
        else cur = E[cur].second;
    }

    cout << cur << "\n";

    return 0;
}