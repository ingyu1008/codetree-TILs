#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N, K;
    cin >> N >> K;

    vector<int> A(N);

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    queue<int> q;
    int root = A[0];
    q.push(A[0]);

    vector<int> par(1010101);
    vector<vector<int>> E(1010101);

    for(int i = 1; i < N; i++){
        if(A[i] > A[i-1] + 1 && i > 1) q.pop();
        int parent = q.front();

        par[A[i]] = parent;
        E[parent].push_back(A[i]);
        q.push(A[i]);
    }

    int ans = 0;
    for(int i = 1; i < N; i++){
        int pa = par[A[i]];
        int pb = par[K];
        if(pa != pb && par[pa] == par[pb]){
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}