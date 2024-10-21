#include <bits/stdc++.h>
using namespace std;

int Manachers(string &S){
    int N = S.size();
    string T;
    for(int i = 0; i < N; i++){
        T += "#";
        T += S[i];
    }
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
            && T[i - A[i] - 1] == T[i + A[i] + 1]){
            A[i]++;
        }
        
        if(i + A[i] > r){
            p = i;
            r = p + A[p];
        }
    }

    int mx = 0;
    for(int i = 0; i < N; i++){
        mx = max(mx, 2*A[i]+1);
    }

    return mx;
}

int main() {
    string S;
    cin >> S;

    cout << Manachers(S)/2 << "\n";

    return 0;
}