#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);

    vector<bool> possible(10101, false);
    possible[0] = true;

    for(int i = 0; i < N; i++){
        cin >> A[i];
        for(int j = 10000; j >= 0; j--){
            if(possible[j] && j + A[i] <= 10000) possible[j+A[i]] = true;
        }
    }

    if(!possible[M]){
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    


    return 0;
}
