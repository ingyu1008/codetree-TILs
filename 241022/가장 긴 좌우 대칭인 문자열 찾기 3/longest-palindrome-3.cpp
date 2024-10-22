#include <bits/stdc++.h>
using namespace std;

vector<int> Manachers(string &S, char c){
    int N = S.size();
    string T;
    for(int i = 0; i < N; i++){
        T += "#";
        T += S[i];
    }
    T += "#";
    N = T.size();


    vector<int> A(N);
    A[0] = 0;

    int p = 0;
    int r = p + A[p];

    for(int i = 1; i < N; i++){
        A[i] = 0;

        if(r > i){
            int ii = 2*p - i;
            A[i] = min(r - i, A[ii]);
        }

        while(i - A[i] - 1 >= 0 && i + A[i] + 1 < N
            && T[i - A[i] - 1] == T[i + A[i] + 1] && T[i- A[i] - 1] != c){
            A[i]++;
        }
        
        if(i + A[i] > r){
            p = i;
            r = p + A[p];
        }
    }

    return A;
}

int main() {
    int N;
    char c;
    cin >> N >> c;
    string S;
    cin >> S;
    
    auto A = Manachers(S, c);
    
    int ans = 0;
    for(int i = 0; i < A.size(); i++){
        int x = 2*A[i]+1;
        x >>= 1;
        ans = max(ans , x);
    }

    cout << ans << "\n";

    return 0;
}