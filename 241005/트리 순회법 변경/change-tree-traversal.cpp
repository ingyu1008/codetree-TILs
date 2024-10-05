#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N, 1e9);

    for(int i = 0; i < N; i++) cin >> A[i];

    stack<int> monotone;

    for(int i = 0; i < N; i++){
        
        while(!monotone.empty() && A[monotone.top()] < A[i]){
            B[monotone.top()] = i;
            monotone.pop();
        }

        monotone.push(i);
    }

    function<void(int, int)> dfs = [&](int l, int r){
        if( l > r) return;
        if(B[l] == 1e9){
            dfs(l+1, r);
        } else {
            dfs(l+1, B[l]-1);
            dfs(B[l], r);
        }
        cout << A[l] << "\n";
        return;
    };

    dfs(0, N-1);

    return 0;
}